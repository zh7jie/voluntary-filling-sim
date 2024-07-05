#include <stdio.h>
#include <stdlib.h>
struct school {
	int id;
	char name[40];
};

struct Student {
	int id;
	char name[20];
	int volunteers[12];
	int scores[7];
};
typedef struct Student STU;

int init(void);

STU *input(STU *, int);

void *print(STU *, int);

int main()
{
	STU *student = NULL;
	int number = 0;
	while (number < 3) {
		int choice = init();
		switch (choice) {
		case 1:
			student = input(student, number);
			number++;
			break;
		case 2:
			print(student, number);

		default:
			break;
		}
	}

	return 0;
}

int init(void)
{
	system("clear");
	printf("高中招生信息管理系统\n");
	printf("===============================\n");
	printf("1.录入学生信息\t2.输出学生信息\n");
	printf("3.导出信息\t4.导入信息\n");
	printf("请输入选项（数字）：");
	int a;
	scanf("%d", &a);
	return a;
}

STU *input(STU *student, int number)
{
	if (student == NULL) {
		student = (STU *) malloc(sizeof(STU));
	} else {
		student = (STU *) realloc(student, (number + 1) * sizeof(STU));
		student++;
	}
	printf("请输入准考证号：");
	scanf("%d", &(student->id));
	printf("请输入考生姓名：");
	scanf("%s", student->name);
	printf("请填入志愿：\n");
	for (int i = 0; i < 12; i++) {
		printf("%d：", i + 1);
		scanf("%d", &(student->volunteers[i]));
	}
	printf
	    ("请输入六科分数（空格分隔，按语数英科社体顺序）：");
	scanf("%d %d %d %d %d %d", &(student->scores[0]),
	      &(student->scores[1]), &(student->scores[2]),
	      &(student->scores[3]), &(student->scores[4]),
	      &(student->scores[5]));
	for (int i = 0; i < 6; i++) {
		student->scores[6] += student->scores[i];
	}
	return student;
}

void *print(STU *student, int number)
{
	student -= (number - 1);
	for (int x = 0; x < number; x++) {
		printf("===============================\n");
        printf("准考证号：%d\t姓名：%s\n", student->id,
		       &(student->name));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				printf("志愿%d：%d\t", (i + 1) * (j + 1),
				       student->volunteers[(i + 1) * (j + 1) -
							   1]);
			}
			putchar('\n');
		}
		printf("语文：%d\t数学：%d\t英语：%d\t",
		       student->scores[0], student->scores[1],
		       student->scores[2]);
		printf("科学：%d\t社会：%d\t体育：%d\n",
		       student->scores[3], student->scores[4],
		       student->scores[5]);
		printf("总分：%d\n\n", student->scores[6]);
		student++;
	}
    printf("===============================\n");
	printf("按回车键退出...");
	getchar();
    getchar();
}
