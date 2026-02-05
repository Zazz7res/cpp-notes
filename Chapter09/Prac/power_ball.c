#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <time.h>
#include <math.h>

// 全局变量
int terminal_width = 80;
int terminal_height = 24;

// 信号处理函数，用于响应终端尺寸变化
void handle_sigwinch(int sig) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    terminal_height = w.ws_row;
    terminal_width = w.ws_col;
}

// 清屏函数
void clear_screen() {
    printf("\033[2J");    // 清屏
    printf("\033[H");     // 光标移动到左上角
    fflush(stdout);
}

// 设置光标位置
void set_cursor_position(int x, int y) {
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}

// 设置256色前景色
void set_color_256(int color_code) {
    printf("\033[38;5;%dm", color_code);
    fflush(stdout);
}

// 设置256色背景色
void set_bg_color_256(int color_code) {
    printf("\033[48;5;%dm", color_code);
    fflush(stdout);
}

// 重置所有颜色和样式
void reset_color() {
    printf("\033[0m");
    fflush(stdout);
}

// 彩虹颜色序列（256色模式）
int rainbow_colors[] = {196, 202, 208, 214, 220, 226, 190, 154, 118, 82, 46, 47, 48, 49, 50, 51, 45, 39, 33, 27, 21, 57, 93, 129, 165, 201, 200, 199, 198, 197};

// 球的结构体
typedef struct {
    int x, y;           // 当前位置
    int vx, vy;         // 速度
    int color_index;     // 当前颜色索引
    int trail[20][3];   // 拖影轨迹：[x, y, 颜色强度]
    int trail_count;     // 当前拖影数量
} Ball;

// 初始化球
void init_ball(Ball *ball) {
    ball->x = terminal_width / 2;
    ball->y = terminal_height / 2;
    ball->vx = (rand() % 3) + 1;
    ball->vy = (rand() % 3) + 1;
    if (rand() % 2) ball->vx = -ball->vx;
    if (rand() % 2) ball->vy = -ball->vy;
    ball->color_index = 0;
    ball->trail_count = 0;
    
    // 初始化拖影数组
    for (int i = 0; i < 20; i++) {
        ball->trail[i][0] = -1; // 标记为无效
    }
}

// 添加拖影点
void add_trail_point(Ball *ball) {
    // 移动现有拖影
    for (int i = 19; i > 0; i--) {
        if (ball->trail[i-1][0] != -1) {
            ball->trail[i][0] = ball->trail[i-1][0];
            ball->trail[i][1] = ball->trail[i-1][1];
            ball->trail[i][2] = ball->trail[i-1][2] - 3; // 颜色逐渐变淡
        }
    }
    
    // 添加新拖影点
    ball->trail[0][0] = ball->x;
    ball->trail[0][1] = ball->y;
    ball->trail[0][2] = 15; // 初始颜色强度
    
    if (ball->trail_count < 20) {
        ball->trail_count++;
    }
}

// 绘制球和拖影
void draw_ball(Ball *ball) {
    // 绘制拖影（从旧到新，颜色逐渐变亮）
    for (int i = ball->trail_count - 1; i >= 0; i--) {
        if (ball->trail[i][0] != -1 && ball->trail[i][2] > 0) {
            int trail_x = ball->trail[i][0];
            int trail_y = ball->trail[i][1];
            int color_intensity = ball->trail[i][2];
            
            if (trail_x >= 1 && trail_x <= terminal_width && 
                trail_y >= 1 && trail_y <= terminal_height) {
                
                set_cursor_position(trail_x, trail_y);
                int color_idx = (ball->color_index + i) % 30;
                set_color_256(rainbow_colors[color_idx]);
                
                // 根据强度选择字符
                char trail_char;
                if (color_intensity > 10) trail_char = '@';  // 实心效果
else if (color_intensity > 5) trail_char = 'O';  // 空心效果  
else trail_char = '.';  // 点状效果
                printf("%c", trail_char);
            }
        }
    }
    
    // 绘制球本身
    set_cursor_position(ball->x, ball->y);
    set_color_256(rainbow_colors[ball->color_index]);
    printf("●");
    
    // 更新颜色索引（创建彩虹效果）
    ball->color_index = (ball->color_index + 1) % 30;
}

// 更新球的位置
void update_ball(Ball *ball) {
    // 添加当前点到拖影
    add_trail_point(ball);
    
    // 更新位置
    ball->x += ball->vx;
    ball->y += ball->vy;
    
    // 边界碰撞检测
    if (ball->x <= 1 || ball->x >= terminal_width) {
        ball->vx = -ball->vx;
        ball->x += ball->vx * 2;
    }
    
    if (ball->y <= 1 || ball->y >= terminal_height) {
        ball->vy = -ball->vy;
        ball->y += ball->vy * 2;
    }
}

// 绘制边框
void draw_border() {
    // 上边框
    set_cursor_position(1, 1);
    set_color_256(81);
    for (int i = 0; i < terminal_width; i++) {
        printf("═");
    }
    
    // 下边框
    set_cursor_position(1, terminal_height);
    for (int i = 0; i < terminal_width; i++) {
        printf("═");
    }
    
    // 左边框
    for (int i = 2; i < terminal_height; i++) {
        set_cursor_position(1, i);
        printf("║");
    }
    
    // 右边框
    for (int i = 2; i < terminal_height; i++) {
        set_cursor_position(terminal_width, i);
        printf("║");
    }
    
    // 角落字符
    set_cursor_position(1, 1);
    printf("╔");
    set_cursor_position(terminal_width, 1);
    printf("╗");
    set_cursor_position(1, terminal_height);
    printf("╚");
    set_cursor_position(terminal_width, terminal_height);
    printf("╝");
}

int main() {
    // 设置随机种子
    srand(time(NULL));
    
    // 设置信号处理
    signal(SIGWINCH, handle_sigwinch);
    
    // 获取初始终端尺寸
    handle_sigwinch(0);
    
    // 隐藏光标
    printf("\033[?25l");
    
    // 初始化球
    Ball ball;
    init_ball(&ball);
    
    printf("彩色拖影弹跳球 - 按Ctrl+C退出\n");
    
    // 主动画循环
    int frame = 0;
    while (1) {
        clear_screen();
        
        // 绘制边框
        draw_border();
        
        // 绘制球和拖影
        draw_ball(&ball);
        
        // 更新球的位置
        update_ball(&ball);
        
        // 显示帧率信息
        set_cursor_position(2, 2);
        set_color_256(15);
        printf("帧: %d", frame);
        
        set_cursor_position(2, 3);
        printf("球位置: (%d, %d)", ball.x, ball.y);
        
        // 控制动画速度（约30帧/秒）
        usleep(33333);
        frame++;
    }
    
    // 显示光标（正常情况下不会执行到这里）
    printf("\033[?25h");
    reset_color();
    
    return 0;
}
