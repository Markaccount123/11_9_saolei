//���Ƕ������С��Ϸ�����Ǻ�����
//����㿪һ�������������Χ��û�б�ĵ��׵�ʱ�򣬾ͻ�չ��һƬ
//�������ܸ��ӽӽ�������ɨ��С��Ϸ
//�ݹ鷽����ʵ��   1.������겻���� 2.���������ΧҲ��������
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
	//����׵���Ϣ  ��ʼ��ʱ�򲼾ֶ���0��������Ҫ�����׵�ʱ���׵���Ϣ��1������
	//������׵���Ϣ  ��  �Ų�����׵���Ϣ�� �����ڴ���׵���Ϣ���������������һ��1���ͻ�������壬����������Χ����һ���׻������������һ����
	//���Ǹ���Ҵ�ӡ�����Ų�����׵���Ϣ�Ľ���
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 }; // 11*11
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��  
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);// �ڴ�ӡ�׵���Ϣ��ʱ������һ��Ҫ��ӡ�м���Ǹ�9*9�ĸ���
	DisplayBoard(show, ROW, COL);
	//�����ף���mine(9*9)��������������ҵط�����1��
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);  ����������Ե�ʱ����֤�������ȷ��
	//����
	FindMine(mine, show, ROW, COL); // ����Ҫ��mine�������ҵ��׵���ϢȻ���ٰ���Ϣ�ŵ�show������
	

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();  
	return 0;
}