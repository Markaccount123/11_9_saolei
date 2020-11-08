#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

// �������InitBoard������˵��ֻ������е����ݶ���ʼ����Ϊͬ��������,show������ʹ�õ�ʱ������Ҳ�ᶼ��'0'
//                                                                         �����ҵ�show�����ʼ����Ҫ'*'
//����Ϊ���ܹ�ʹ��ʼ�������ݲ�ͬ�������ڴ��ε�ʱ��ֱ�Ӱ���Ҫ��ʼ���ɵ�����Ҳ����ͺ���
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

void DisplayBoard(char board[ROWS][COLS], int row, int col)   //���ڴ���ȥ��mine����һֱ����11*11������ǧ�򲻸�д��ROW , COL
{
	int i = 0;
	int j = 0;
	//�������Ǵ�ӡ��ʱ���һ�к͵�һ�ж�ʡ���ˣ����Գ�ʼ����ʱ��i��j=1 ��ʼ
	//��ӡ�к�
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//�к�
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
		int x = rand() % row + 1;   //����1-9�ķ�Χ��
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
	//����Χ��8�������������Ǽ�,������õ������ַ�
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
	//9*9 - 10 = 71 ��win=71ʱ��Ӯ��
	while (win<row*col -EASY_COUNT)
	{
		printf("�������Ų��׵����꣺>");
		scanf("%d%d", &x, &y);
		//���ﻹҪ�ж��û������x��y�������Чֵ
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//���������1.��������ף�ֱ��ը����
			//          2.��������ף�������Ҫͳ��һ������Χ8��λ�õĵ�������
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, row, col);  //չʾ�����������㲻֪���Լ�����ô����
				break;
			}
			else
			{
				//����x��y������Χ�м�����
				int count = get_mine_count(mine, x, y);//��mine �����x��y������ΧȥѰ��
				//֮��Ӧ����mine�����Ӧ��show��������ʾ���count��
				show[x][y] = count + '0';//��������Ӧ�÷����ַ�0
				DisplayBoard(show, row, col);
				//������ᷢ��������㱻ը������Ϸֹͣ����Ȼ�ͻ�һֱ������ȥ����ô��ô����Ӯ����
				win++;
			}
		}
		else
		{
			printf("��������Ƿ�������������!\n");
		}
	}
	if (win = row*col - EASY_COUNT)  // ������Ҫ�ж�һ�£���Ȼ������ĺ��ź��㱻ը���ˣ�Ҳ��break��ֱ�Ӹ�����ɹ�����ͳ�����
	{
		printf("��ϲ�㣬���׳ɹ�\n");
	}
}
