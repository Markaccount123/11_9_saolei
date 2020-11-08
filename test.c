//但是对于这个小游戏还不是很完美
//当你点开一个，如果他的周围都没有别的地雷的时候，就会展开一片
//这样就能更加接近真正的扫雷小游戏
//递归方法来实现   1.这个坐标不是雷 2.该坐标的周围也都不是雷
#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
}
void game()
{
	//存放雷的信息  开始的时候布局都是0，当你想要放置雷的时候，雷的信息用1来代替
	//（存放雷的信息  和  排查出来雷的信息） 当你在存放雷的信息界面内如果出现了一个1，就会产生歧义，他到底是周围存在一个雷还是它本身就是一个雷
	//我们给玩家打印的是排查出来雷的信息的界面
	//1.布置好雷的信息
	char mine[ROWS][COLS] = { 0 }; // 11*11
	//2.排查出来雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化  
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);// 在打印雷的信息的时候我们一定要打印中间的那个9*9的格子
	DisplayBoard(show, ROW, COL);
	//布置雷（在mine(9*9)数组里面随机的找地方放入1）
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);  可以在你测试的时候验证代码的正确性
	//找雷
	FindMine(mine, show, ROW, COL); // 我需要从mine数组中找到雷的信息然后再把信息放到show数组中
	

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();  
	return 0;
}