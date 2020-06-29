#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

#define N 60//���ѧ������
#define LEN 15//ID����

struct students
{
	char id[LEN + 1];//ѧ��
	char name[LEN + 1];//����
	float score[3];//���ſγ̵ĳɼ�
	float sum;//�ܷ�
	float aver;//ƽ����
}stu[N + 1];

//��������
void menu();//�˵�
void write();//д���ļ�
void add();//���ѧ����Ϣ
void check();//��ѯѧ����Ϣ
void alter();//�޸�ѧ����Ϣ
void del();//ɾ��ѧ����Ϣ
void sort();//���ֳܷɼ�����
void show();//��ʾ����ѧ����Ϣ
void sum_aver(struct students* p);//�����ֺܷ�ƽ����

int all=0;//�Ѽ�¼ѧ��������

int main()//������
{
	while (1)
	{
		menu();
	}
	return 0;
}
void menu()//�˵�
{
	int num = 0;
	int cnt = 0;
	printf("***************************************************\n");
	printf("*                  ѧ������ϵͳ                   *\n");
	printf("***************************************************\n");
	printf("*                    ���ܲ˵�                     *\n");
	printf("______________________     ________________________\n");
	printf("*   1.���ѧ����Ϣ   *     *    2.��ѯѧ����Ϣ    *\n"); 
	printf("*   3.�޸�ѧ����Ϣ   *     *    4.ɾ��ѧ����Ϣ    *\n");
	printf("*   5.��ʾ��ǰ��Ϣ   *     *    6.���浱ǰ��Ϣ    *\n");
	printf("*   0.�˳�ϵͳ       *\n");
	printf("***************************************************\n");
	do
	{
		cnt = 0;
		printf("������˵���ţ�");
		scanf_s("%d", &num);
		switch (num)
		{
		case 0:
			printf("���򼴽�����������\n");
			Sleep(1000);
			printf("3\n");
			Sleep(1000);
			printf("2\n");
			Sleep(1000);
			printf("1\n");
			Sleep(1000);
			printf("(�èi�s�n�t�ic) �ټ�������\n");
			Sleep(1000);
			exit(0); break;
		case 1:add(); break;
		case 2:check(); break;
		case 3:alter(); break;
		case 4:del(); break;
		case 5:show(); break;
		case 6:write(); break;
		default:
			printf("��������ȷ�Ĳ˵���ţ�\n");
			cnt = 1;
		}
	} while (cnt == 1);
}
void add()//���ѧ����Ϣ
{
	printf("�����Դ洢%d��ѧ����Ϣ\n", N);
	int cnt = 0;
	for (int i = all; i < N; i++)
	{
		do 
		{
			cnt = 0;
			printf("�������%d��ѧ����ѧ��:\n", i + 1);
			scanf_s("%s", &stu[i].id, LEN);
			for (int j = 0; j < i; j++)
			{
				if (strcmp(stu[j].id, stu[i].id) == 0)
				{
					cnt = 1;
					printf("����ѧ���Ѵ��ڣ����������룡\n");
				}
			}
		} while (cnt == 1);
		printf("�������%d��ѧ��������:\n", i + 1);
		scanf_s("%s", &stu[i].name, LEN);
		printf("�������%d��ѧ����c���Գɼ�\n", i + 1);
		scanf_s("%f", &stu[i].score[0]);
		printf("�������%d��ѧ���ĸߵȴ����ɼ�:\n", i + 1);
		scanf_s("%f", &stu[i].score[1]);
		printf("�������%d��ѧ������ѧ�����ɼ�:\n", i + 1);
		scanf_s("%f", &stu[i].score[2]);
		all++;
		printf("**  ���������0����˵�������������������  **\n");
		char c = _getch();
		if (c =='0')
		{
			printf("�������������\n");
			break;
		}
	}
	sum_aver(stu);
}
void sum_aver(struct students* p)//�����ֺܷ�ƽ����
{
	for (int i = 0; i < all; i++)
	{
		p[i].sum = p[i].score[0] + p[i].score[1] + p[i].score[2];
		p[i].aver = p[i].sum / 3;
	}
}
void check()//��ѯѧ����Ϣ
{
	while (1)
	{
		char str1[LEN + 1];
		int cnt = 0;
		printf("������Ҫ��ѯѧ����ѧ�ţ�");
		scanf_s("%s", &str1, LEN);
		for (int i = 0; i < all; i++)
		{
			if (strcmp(str1, stu[i].id) == 0)
			{
				cnt++;
				printf("%10s%10s%10s%10s%10s%10s%10s\n", "ѧ��", "����", "C����", "�ߵȴ���", "��ѧ����", "�ܷ�", "ƽ����");
				printf("-------------------------------------------------------------------------\n");
				printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
			}
		}
		if (cnt == 0)
		{
			printf("��ѧ�Ų����ڣ�����\n");
			printf("���������룡\n");
		}
		printf("**  �����ѯ��0����˵�����������������ѯ  **\n");
		char c = _getch();
		if (c == '0')
		{
			printf("��ѯ����������\n");
			break;
		}
	}
}
void alter()//�޸�ѧ����Ϣ
{
	int num = 0, k = 0, cnt = 0;
	char str1[LEN + 1], str2[LEN + 1];
	float score1;
	do
	{
		printf("��������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
		scanf_s("%s", str1, LEN);
		for (int i = 0; i < all; i++)
		{
			if (strcmp(str1, stu[i].id) == 0)
			{
				k = i;
				cnt++;
				printf("------------------\n");
				printf("1.�޸�ѧ��\n");
				printf("2.�޸�����\n");
				printf("3.�޸�C���Գɼ�\n");
				printf("4.�޸ĸߵȴ����ɼ�\n");
				printf("5.�޸���ѧ�����ɼ�\n");
				printf("0.�˳����˵�\n");
				printf("------------------\n");
				while (1)
				{
					printf("������˵���ţ�");
					scanf_s("%d", &num);
					switch (num)
					{
					case 0: return;
					case 1:
						printf("�������µ�ѧ�ţ�");
						scanf_s("%s", &str1, LEN);
						strcpy_s(stu[k].id, LEN, str1);
						printf("�޸ĳɹ�������\n");
						break;
					case 2:
						printf("�������µ�������");
						scanf_s("%s", &str2, LEN);
						strcpy_s(stu[k].name, LEN, str2);
						printf("�޸ĳɹ�������\n");
						break;
					case 3:
						printf("�������µ�C���Գɼ���");
						scanf_s("%f", &score1);
						stu[k].score[0] = score1;
						printf("�޸ĳɹ�������\n");
						break;
					case 4:
						printf("�������µĸߵȴ����ɼ���");
						scanf_s("%f", &score1);
						stu[k].score[1] = score1;
						printf("�޸ĳɹ�������\n");
						break;
					case 5:
						printf("�������µ���ѧ�����ɼ���");
						scanf_s("%f", &score1);
						stu[k].score[2] = score1;
						printf("�޸ĳɹ�������\n");
						break;
					default:
						printf("��������ȷ�Ĳ˵���ţ�\n");
					}
					sum_aver(stu);
				}
				printf("�޸���ϣ�����\n");
			}
		}
		if (cnt == 0)
		{
			printf("δ���ҵ���ѧ��������\n");
			printf("���������룡\n");
		}
	} while (1);
}
void del()//ɾ��ѧ����Ϣ
{
	char str1[LEN + 1];
	int cnt = 0;
	printf("������Ҫɾ����Ϣ��ѧ����ѧ�ţ�");
	scanf_s("%s", &str1, LEN);
	for (int i = 0; i < all; i++)
	{
		if (strcmp(str1, stu[i].id) == 0)
		{
			cnt++;
			printf("%10s%10s%10s%10s%10s%10s%10s\n", "ѧ��", "����", "C����", "�ߵȴ���", "��ѧ����", "�ܷ�", "ƽ����");
			printf("-------------------------------------------------------------------------\n");
			printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
			printf("�Ƿ�ȷ��ɾ����Y/N:");
			getchar();
			char c = getchar();
			if (c == 'Y' || c == 'y')
			{
				for (int j = i; j < all; j++)
				{
					stu[j] = stu[j + 1];
				}
				all--;
				printf("ɾ���ɹ�������\n");
			}
			else if (c == 'N' || c == 'n')
			{
				printf("ȡ��ɾ��������\n");
				break;
			}
		}
	}
	if (cnt == 0)
	{
		printf("��ѧ�Ų����ڣ�����\n");
		printf("���������룡\n");
	}
	system("pause");
}
void sort()//���ܷ�����
{
	for (int i = 0; i < all - 1; i++)
	{
		for (int j = 0; j < all - 1 - i; j++)
		{
			if (stu[j].sum < stu[j + 1].sum)
			{
				stu[N] = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stu[N];
			}
		}
	}
}
void show()//��ʾ����ѧ����Ϣ
{
	sort();
	printf("��ǰ����¼%d��ѧ����Ϣ\n", all);
	printf("%10s%10s%10s%10s%10s%10s%10s\n", "ѧ��", "����", "C����", "�ߵȴ���", "��ѧ����", "�ܷ�", "ƽ����");
	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < all; i++)
	{
		printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
	}
	system("pause");
}
void write()//����ѧ����Ϣ
{
	printf("������Students.csv�ļ�����ѧ����Ϣ\n");
	Sleep(500);
	FILE* fp;
	fp = fopen("Students.csv", "w");
	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n", "ѧ��", "����", "C����", "�ߵȴ���", "��ѧ����", "�ܷ�", "ƽ����");
	for (int i = 0; i < all; i++)
	{
		fprintf(fp, "%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
	}
	printf("����ɹ�������\n");
	fclose(fp);
	system("pause");
}