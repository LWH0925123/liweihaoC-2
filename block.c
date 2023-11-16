//头文件
#include<stdio.h>           //标准库
#include<windows.h>         //控制台界面
#include<conio.h>           //接受键盘输入输出
#include<time.h>            //获取随机数

//宏定义
#define FrameX 13           //游戏窗口左上角X坐标为13
#define FrameY 3            //游戏窗口左上角Y坐标为3
#define Frame_height 20     //游戏窗口高度为20
#define Frame_width 18      //游戏窗口宽度为18

//全局变量
int i,j,Temp,Temp1,Temp2;   //temp,temp1,temp2记住和转换方块变量的值
//标记游戏屏幕的图案：2，1，0表示游戏边框、方块、无图案，初始为无图案
int a[80][80]={0};
int b[4];                   //标记方块

struct Tetris               //生命俄罗斯方块的结构体
{
    int x;                  //中心方块的x坐标
    int y;                  //中心方块的y坐标
    int flag;               //标记方块的序号
    int next;               //标记下一个方块的序号
    int speed;              //方块速度
    int number;             //产生方块的个数
    int score;              //游戏分数
    int level;              //游戏等级
};
HANDLE hOut;                //控制台语句

//声明函数
int color(int c);
void gotoxy(int x,int y);    //光标移至指定位置
void DrawGameFrame();        //绘制游戏边框
void Flag(struct Tetris *);  //产生方块序号
void MakeTetris(struct Tetris *);           //制作方块
void PrintTetris(struct Tetris *);          //打印方块
void CleanTetris(struct Tetris *);          //清除方块移动痕迹
int ifMove(struct Tetris *);                //判断是否能移动，1为可以，0为不行
void Del_Fullline(struct Tetris *);         //判断是否满行，满足时删除整行
void Gameplay();                            //开始游戏
void Regulation();                          //游戏规则
void explation();                           //游戏按键
void welcome();                             //欢迎界面
void Replay(struct Tetris *);               //重新开始游戏
void title();                               //游戏标题
void close();                               //关闭游戏

//控制台文字颜色
int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);         //更改文字颜色
    return 0;
}

//获取光标位置
void gotoxy(int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//标题
void title()
{
    color(15);
    gotoxy(24,3);
    printf("俄罗斯方块\n");
    color(11);
    gotoxy(18,5);
    printf("■");
    gotoxy(18,6);
    printf("■■");
    gotoxy(18,7);
    printf("■");

    color(14);
    gotoxy(26,6);
    printf("■■");
    gotoxy(28,7);
    printf("■■");

    color(10);
    gotoxy(36,6);
    printf("■■");
    gotoxy(36,7);
    printf("■■");

    color(13);
    gotoxy(45,5);
    printf("■");
    gotoxy(45,6);
    printf("■");
    gotoxy(45,7);
    printf("■");
    gotoxy(45,8);
    printf("■");

    color(12);
    gotoxy(56,6);
    printf("■");
    gotoxy(52,7);
    printf("■■■");
}

void welcome()
{
    int n,i,j;
    color(14);
    for(i=9;i<=20;i++)
    {
        for(j=15;j<=60;j++)
        {
            gotoxy(j,i);
            if(i==9 || i==20)
            {
                printf("=");
            }
            else if(j==15 || j==59)
            {
                printf("||");
            }
        }
    }
}
int main()
{
    title();
    welcome();
    return 0;
}