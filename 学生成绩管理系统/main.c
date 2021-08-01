#include"stdio.h"
#include"stdlib.h"

#define NUM 500

int menu();
int getN();
void readData();
void gradeConversion(struct studentType student[500], int N);
void findTop(struct studentType student[500], int N);
void sort(struct studentType student[500], int N);
void printscore(struct studentType student[500], int N);

struct studentType
{
	int studentNum;
	char studentName[8];
	int testScore;
	char grade;
}student[NUM];

int main()
{
	int k, N = 0;
	do {
		k = menu();
		switch (k)
		{
		case 0:
			break;
		case 1:
			N = getN();
			break;
		case 2:
			readData(student, N);
			break;
		case 3:
			gradeConversion(student, N);
			break;
		case 4:
			findTop(student, N);
			break;
		case 5:
			sort(student, N);
			break;
		case 6:
			printscore(student,N);
			break;
		default:
			printf("错误选择\n");
			system("pause");
			system("cls");
		}
	} while (k);
	return 0;
}

//提供菜单
int menu()
{
	int n = 0;
	printf("  学生成绩管理系统\n");
	printf("*******************\n");
	printf("1:输入统计人数\n");
	printf("2:录入成绩\n");
	printf("3:学生成绩等级转换\n");
	printf("4:查找最高分\n");
	printf("5:成绩正向排序\n");
	printf("6:打印成绩单\n");
	printf("0:退出\n");
	printf("*******************\n");
	printf("请选择: ");
	scanf("%d", &n);
	return n;
}

//输入统计人数
int getN()
{
	int N;
	printf("请输入要统计的班级总人数(500人以内):\n");
	scanf("%d",&N);
	printf("录入完毕!\n");
	system("pause");
	system("cls");
	return N;
}

//把学生的数据读到数组中的函数
void readData(struct studentType student[500],int N)
{
	int i;
	printf("请输入每位学生的学号,姓名,成绩:\n");
	for (i = 0;i < N;i++)
	{
		scanf("%d%s%d", &student[i].studentNum, student[i].studentName, &student[i].testScore);
	}
	printf("录入完毕!\n");
	system("pause");
	system("cls");
}

//学生成绩等级转换
void gradeConversion(struct studentType student[500], int N)
{
	int i, gpa;
	for (i = 0;i < N;i++)
	{
		gpa = student[i].testScore / 10;
		switch (gpa)
		{
		case 10:
			student[i].grade = 'A';
			break;
		case 9:
			student[i].grade = 'A';
			break;
		case 8:
			student[i].grade = 'B';
			break;
		case 7:
			student[i].grade = 'C';
			break;
		case 6:
			student[i].grade = 'D';
			break;
		case 5:
			student[i].grade = 'E';
			break;
		case 4:
			student[i].grade = 'E';
			break;
		case 3:
			student[i].grade = 'E';
			break;
		case 2:
			student[i].grade = 'E';
			break;
		case 1:
			student[i].grade = 'E';
			break;
		case 0:
			student[i].grade = 'E';
			break;
		}
	}
	printf("学号  姓名     成绩   等第\n");
	for (i = 0;i < N;i++)
	{
		printf("%3d   %-8s %3d     %c\n",student[i].studentNum,student[i].studentName,student[i].testScore,student[i].grade);
	}
	printf("转换完毕!\n");
	system("pause");
	system("cls");
}

//查找最高分
void findTop(struct studentType student[500], int N)
{
	int i, max = student[0].testScore;
	for (i = 1;i < N;i++)
	{
		if (student[i].testScore > max)
		{
			max = student[i].testScore;
		}
	}
	printf("所有学生中成绩最高分为%d\n",max);
	printf("查找完毕!\n");
	system("pause");
	system("cls");
}

//成绩正向排序
void sort(struct studentType student[500], int N)
{
	int i, j, num;
	struct studentType temp;
	for (i = 0;i < N-1;i++)
	{
		num = i;
		for (j = i + 1;j < N;j++)
		{
			if (student[j].testScore > student[num].testScore)
				num = j;
		}
		if (num != i)
		{
			temp = student[num];
			student[num] = student[i];
			student[i] = temp;
		}
	}
	printf("学号  姓名     成绩   等第  排名\n");
	for (i = 0;i < N;i++)
	{
		printf("%3d   %-8s %3d     %c     %d\n", student[i].studentNum, student[i].studentName, student[i].testScore, student[i].grade,i+1);
	}
	printf("排序完毕!\n");
	system("pause");
	system("cls");
}

//打印成绩单
void printscore(struct studentType student[500], int N)
{
	int i;
	int a[5] = { 0 };

	for (i = 0;i < N;i++)
	{
		if (student[i].grade == 'A')
		{
			a[0]++;
		}
		else if (student[i].grade == 'B')
		{
			a[1]++;
		}
		else if (student[i].grade == 'C')
		{
			a[2]++;
		}
		else if (student[i].grade == 'D')
		{
			a[3]++;
		}
		else if (student[i].grade == 'E')
		{
			a[4]++;
		}
	}
	FILE* fp;
	if ((fp = fopen("score.txt", "w")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fprintf(fp, "              成绩单\n");
	fprintf(fp, "**************************************\n");
	fprintf(fp, "学号  姓名     成绩   等第  排名\n");
	for (i = 0;i < N;i++)
	{
		fprintf(fp,"%3d   %-8s %3d     %c     %d\n", student[i].studentNum, student[i].studentName, student[i].testScore, student[i].grade, i + 1);
	}
	;
	fprintf(fp, "**************************************\n");
	fprintf(fp, "本班级获得A:%d人次,获得B:%d人次,获得C:%d人次,获得D:%d人次,获得E:%d人次", a[0], a[1], a[2], a[3], a[4]);
	fclose(fp);
	printf("打印完毕!\n");
	system("pause");
	system("cls");
}