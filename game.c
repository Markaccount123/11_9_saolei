#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

// 对于这个InitBoard函数来说，只会把所有的内容都初始化成为同样的内容,show数组在使用的时候里面也会都是'0'
//                                                                         但是我的show里面初始化需要'*'
//所以为了能够使初始化的内容不同，我们在传参的时候直接把需要初始化成的内容也加入就好了
//void InitBoard(char board[ROWS][COLS], int rows, int cols)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = '0';   
//		}
//	}
//}


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)   //对于传过去的mine数组一直都是11*11的所以千万不敢写成ROW , COL
{
	int i = 0;
	int j = 0;
	//这里我们打印的时候第一行和第一列都省略了，所以初始化的时候i，j=1 开始
	//打印列号
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;   //且在1-9的范围内
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//'3' - '0' = 0
	//'0' - '0' =0
	//把周围的8个都加起来看是几,但是你得到的是字符
	return mine[x - 1][y] +
		mine[x+1][y] +
		mine[x-1][y+1] +
		mine[x][y+1] +
		mine[x+1][y+1] +
		mine[x-1][y-1] +
		mine[x][y-1] +
		mine[x+1][y-1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	//9*9 - 10 = 71 当win=71时就赢了
	while (win<row*col -EASY_COUNT)
	{
		printf("请输入排查雷的坐标：>");
		scanf("%d%d", &x, &y);
		//这里还要判断用户输入的x和y坐标的有效值
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//有两种情况1.这个就是雷，直接炸死了
			//          2.这个不是雷，所以我要统计一下它周围8个位置的地雷总数
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, row, col);  //展示出来，避免你不知道自己是怎么死的
				break;
			}
			else
			{
				//计算x，y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);//在mine 数组的x，y数组周围去寻找
				//之后应该在mine数组对应的show数组中显示这个count数
				show[x][y] = count + '0';//在数组中应该放入字符0
				DisplayBoard(show, row, col);
				//但是你会发现这除非你被炸死了游戏停止，不然就会一直运行下去，那么怎么才算赢了呢
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入!\n");
		}
	}
	if (win = row*col - EASY_COUNT)  // 这里需要判断一下，不然你上面的很遗憾你被炸死了，也会break，直接告诉你成功，这就扯淡了
	{
		printf("恭喜你，排雷成功\n");
	}
}
