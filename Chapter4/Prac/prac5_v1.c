/*  

编写一个程序，提示用户输入以兆位每秒（Mb/s）为单位的下载速度
和以兆字节（MB）为单位的文件大小。程序中应计算文件的下载时间。
注意，这里1字节等于8位。使用float类型，并用/作为除号。
该程序要以下面的格式打印3个变量的值（下载速度、文件大小和下载时间）​，
显示小数点后面两位数字：
At 18.12 megabits per second, a file of 2.20 megabytes
downloads in 0.97 seconds.



*/


#include <stdio.h>


int main(void)
{

    float download_speed_mbps;
    float file_size_mb;

    printf("请输入下载速度(单位:兆位每秒):\n");
    scanf("%f", &download_speed_mbps);
    printf("请输入文件大小(单位:兆字节):\n");
    scanf("%f", &file_size_mb);

    float download_time_speeds = (file_size_mb * 8.0f) / download_speed_mbps;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", download_speed_mbps, file_size_mb);;
    printf("downloads in %.2f seconds.\n", download_time_speeds);




    return 0;
}