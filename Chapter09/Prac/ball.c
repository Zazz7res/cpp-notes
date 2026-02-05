#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>

// 全局变量，用于存储终端尺寸
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
}

// 设置光标位置
void set_cursor_position(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// 显示弹跳球
void display_ball(int x, int y) {
    set_cursor_position(x, y);
    printf("●");  // 实心圆作为球
    fflush(stdout);  // 确保立即输出
}

int main() {
    // 设置信号处理，响应终端尺寸变化
    signal(SIGWINCH, handle_sigwinch);
    
    // 获取初始终端尺寸
    handle_sigwinch(0);
    
    // 球的初始位置和速度
    int ball_x = 2;
    int ball_y = 2;
    int velocity_x = 1;
    int velocity_y = 1;
    
    // 隐藏光标
    printf("\033[?25l");
    
    printf("终端弹跳球动画 - 按Ctrl+C退出\n");
    
    // 主动画循环
    while (1) {
        clear_screen();
        
        // 显示边框
        set_cursor_position(1, 1);
        for (int i = 0; i < terminal_width; i++) printf("─");
        
        set_cursor_position(1, terminal_height);
        for (int i = 0; i < terminal_width; i++) printf("─");
        
        for (int i = 2; i < terminal_height; i++) {
            set_cursor_position(1, i);
            printf("│");
            set_cursor_position(terminal_width, i);
            printf("│");
        }
        
        // 显示球
        display_ball(ball_x, ball_y);
        
        // 更新球的位置
        ball_x += velocity_x;
        ball_y += velocity_y;
        
        // 边界碰撞检测
        if (ball_x <= 2 || ball_x >= terminal_width - 1) {
            velocity_x = -velocity_x;
            ball_x += velocity_x * 2;  // 防止卡在边界
        }
        
        if (ball_y <= 2 || ball_y >= terminal_height - 1) {
            velocity_y = -velocity_y;
            ball_y += velocity_y * 2;  // 防止卡在边界
        }
        
        // 控制动画速度（约30帧/秒）
        usleep(33333);  // 约33毫秒
    }
    
    return 0;
}
