#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

#define N 60//最大学生人数
#define LEN 15//ID长度

struct students
{
	char id[LEN + 1];//学号
	char name[LEN + 1];//姓名
	float score[3];//三门课程的成绩
	float sum;//总分
	float aver;//平均分
}stu[N + 1];

//函数声明
void menu();//菜单
void write();//写入文件
void add();//添加学生信息
void check();//查询学生信息
void alter();//修改学生信息
void del();//删除学生信息
void sort();//按总分成绩排序
void show();//显示所有学生信息
void sum_aver(struct students* p);//计算总分和平均分

int all=0;//已记录学生总人数

int main()//主函数
{
	while (1)
	{
		menu();
	}
	return 0;
}
void menu()//菜单
{
	int num = 0;
	int cnt = 0;
	printf("***************************************************\n");
	printf("*                  学生管理系统                   *\n");
	printf("***************************************************\n");
	printf("*                    功能菜单                     *\n");
	printf("______________________     ________________________\n");
	printf("*   1.添加学生信息   *     *    2.查询学生信息    *\n"); 
	printf("*   3.修改学生信息   *     *    4.删除学生信息    *\n");
	printf("*   5.显示当前信息   *     *    6.保存当前信息    *\n");
	printf("*   0.退出系统       *\n");
	printf("***************************************************\n");
	do
	{
		cnt = 0;
		printf("请输入菜单编号：");
		scanf_s("%d", &num);
		switch (num)
		{
		case 0:
			printf("程序即将奔溃！！！\n");
			Sleep(1000);
			printf("3\n");
			Sleep(1000);
			printf("2\n");
			Sleep(1000);
			printf("1\n");
			Sleep(1000);
			printf("(っ╥╯﹏╰╥c) 再见！！！\n");
			Sleep(1000);
			exit(0); break;
		case 1:add(); break;
		case 2:check(); break;
		case 3:alter(); break;
		case 4:del(); break;
		case 5:show(); break;
		case 6:write(); break;
		default:
			printf("请输入正确的菜单编号！\n");
			cnt = 1;
		}
	} while (cnt == 1);
}
void add()//添加学生信息
{
	printf("最多可以存储%d个学生信息\n", N);
	int cnt = 0;
	for (int i = all; i < N; i++)
	{
		do 
		{
			cnt = 0;
			printf("请输入第%d个学生的学号:\n", i + 1);
			scanf_s("%s", &stu[i].id, LEN);
			for (int j = 0; j < i; j++)
			{
				if (strcmp(stu[j].id, stu[i].id) == 0)
				{
					cnt = 1;
					printf("输入学号已存在，请重新输入！\n");
				}
			}
		} while (cnt == 1);
		printf("请输入第%d个学生的姓名:\n", i + 1);
		scanf_s("%s", &stu[i].name, LEN);
		printf("请输入第%d个学生的c语言成绩\n", i + 1);
		scanf_s("%f", &stu[i].score[0]);
		printf("请输入第%d个学生的高等代数成绩:\n", i + 1);
		scanf_s("%f", &stu[i].score[1]);
		printf("请输入第%d个学生的数学分析成绩:\n", i + 1);
		scanf_s("%f", &stu[i].score[2]);
		all++;
		printf("**  输入结束按0进入菜单，按其他键继续输入  **\n");
		char c = _getch();
		if (c =='0')
		{
			printf("输入结束！！！\n");
			break;
		}
	}
	sum_aver(stu);
}
void sum_aver(struct students* p)//计算总分和平均分
{
	for (int i = 0; i < all; i++)
	{
		p[i].sum = p[i].score[0] + p[i].score[1] + p[i].score[2];
		p[i].aver = p[i].sum / 3;
	}
}
void check()//查询学生信息
{
	while (1)
	{
		char str1[LEN + 1];
		int cnt = 0;
		printf("请输入要查询学生的学号：");
		scanf_s("%s", &str1, LEN);
		for (int i = 0; i < all; i++)
		{
			if (strcmp(str1, stu[i].id) == 0)
			{
				cnt++;
				printf("%10s%10s%10s%10s%10s%10s%10s\n", "学号", "姓名", "C语言", "高等代数", "数学分析", "总分", "平均分");
				printf("-------------------------------------------------------------------------\n");
				printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
			}
		}
		if (cnt == 0)
		{
			printf("该学号不存在！！！\n");
			printf("请重新输入！\n");
		}
		printf("**  输入查询按0进入菜单，按其他键继续查询  **\n");
		char c = _getch();
		if (c == '0')
		{
			printf("查询结束！！！\n");
			break;
		}
	}
}
void alter()//修改学生信息
{
	int num = 0, k = 0, cnt = 0;
	char str1[LEN + 1], str2[LEN + 1];
	float score1;
	do
	{
		printf("请输入需要修改信息的学生的学号：");
		scanf_s("%s", str1, LEN);
		for (int i = 0; i < all; i++)
		{
			if (strcmp(str1, stu[i].id) == 0)
			{
				k = i;
				cnt++;
				printf("------------------\n");
				printf("1.修改学号\n");
				printf("2.修改姓名\n");
				printf("3.修改C语言成绩\n");
				printf("4.修改高等代数成绩\n");
				printf("5.修改数学分析成绩\n");
				printf("0.退出本菜单\n");
				printf("------------------\n");
				while (1)
				{
					printf("请输入菜单编号：");
					scanf_s("%d", &num);
					switch (num)
					{
					case 0: return;
					case 1:
						printf("请输入新的学号：");
						scanf_s("%s", &str1, LEN);
						strcpy_s(stu[k].id, LEN, str1);
						printf("修改成功！！！\n");
						break;
					case 2:
						printf("请输入新的姓名：");
						scanf_s("%s", &str2, LEN);
						strcpy_s(stu[k].name, LEN, str2);
						printf("修改成功！！！\n");
						break;
					case 3:
						printf("请输入新的C语言成绩：");
						scanf_s("%f", &score1);
						stu[k].score[0] = score1;
						printf("修改成功！！！\n");
						break;
					case 4:
						printf("请输入新的高等代数成绩：");
						scanf_s("%f", &score1);
						stu[k].score[1] = score1;
						printf("修改成功！！！\n");
						break;
					case 5:
						printf("请输入新的数学分析成绩：");
						scanf_s("%f", &score1);
						stu[k].score[2] = score1;
						printf("修改成功！！！\n");
						break;
					default:
						printf("请输入正确的菜单编号！\n");
					}
					sum_aver(stu);
				}
				printf("修改完毕！！！\n");
			}
		}
		if (cnt == 0)
		{
			printf("未查找到该学生！！！\n");
			printf("请重新输入！\n");
		}
	} while (1);
}
void del()//删除学生信息
{
	char str1[LEN + 1];
	int cnt = 0;
	printf("请输入要删除信息的学生的学号：");
	scanf_s("%s", &str1, LEN);
	for (int i = 0; i < all; i++)
	{
		if (strcmp(str1, stu[i].id) == 0)
		{
			cnt++;
			printf("%10s%10s%10s%10s%10s%10s%10s\n", "学号", "姓名", "C语言", "高等代数", "数学分析", "总分", "平均分");
			printf("-------------------------------------------------------------------------\n");
			printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
			printf("是否确认删除？Y/N:");
			getchar();
			char c = getchar();
			if (c == 'Y' || c == 'y')
			{
				for (int j = i; j < all; j++)
				{
					stu[j] = stu[j + 1];
				}
				all--;
				printf("删除成功！！！\n");
			}
			else if (c == 'N' || c == 'n')
			{
				printf("取消删除！！！\n");
				break;
			}
		}
	}
	if (cnt == 0)
	{
		printf("该学号不存在！！！\n");
		printf("请重新输入！\n");
	}
	system("pause");
}
void sort()//按总分排序
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
void show()//显示所有学生信息
{
	sort();
	printf("当前共记录%d个学生信息\n", all);
	printf("%10s%10s%10s%10s%10s%10s%10s\n", "学号", "姓名", "C语言", "高等代数", "数学分析", "总分", "平均分");
	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < all; i++)
	{
		printf("%10s%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
	}
	system("pause");
}
void write()//保存学生信息
{
	printf("将生成Students.csv文件保存学生信息\n");
	Sleep(500);
	FILE* fp;
	fp = fopen("Students.csv", "w");
	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n", "学号", "姓名", "C语言", "高等代数", "数学分析", "总分", "平均分");
	for (int i = 0; i < all; i++)
	{
		fprintf(fp, "%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].aver);
	}
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");
}