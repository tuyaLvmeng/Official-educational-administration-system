#include<stdio.h>
#include<getch.h>
#include<stdbool.h>
#include<stdlib.h>
#include"tool.h"
#include "interface.h"
#include"teacher.h"
#include"admin.h"

void interface_enum(void)
{
	printf("--------------主  界  面---------------\n\n");
	printf("          1.学   生   登   录                  \n\n");
	printf("          2.教   师   登   录                  \n\n");
	printf("          3.管  理  员 登  录                  \n\n");
	printf("          4.退   出   系   统                   \n\n");
	printf("---------- -无敌工作室出品------------\n");
}

void student_enum(void)
{
	printf("--------------同学您好,欢迎登录学生信息管理系统----------\n\n");
    printf("                   1.查 询 成 绩                      \n\n");
	printf("                   2.修 改 密 码                      \n\n");
	printf("                   3.查看个人信息                      \n\n");
	printf("                   4.返回首页面                        \n\n");
}

void teacher_enum(void)
{
   printf("--------------尊敬的老师欢迎登录学生管理系统----------- \n\n");
   printf("                     1.添 加 学 生                      \n\n");
   printf("                     2.删 除 学 生                      \n\n");
   printf("                     3.查 找 学 生                      \n\n");
   printf("                     4.修改学生信息                     \n\n");
   printf("                     5.录入学生成绩                     \n\n");
   printf("                     6.重置学生密码                     \n\n");
   printf("                     7.显示所有在校学生信息             \n\n");
   printf("                     8.显示所有退学学生信息             \n\n");
   printf("                     9.给学生解锁                      \n\n");
   printf("                     0.返回主页面                      \n\n");
}

void admin_enum(void)
{
   printf("--------------尊敬的管理员欢迎登录学生管理系统----------- \n\n");
   printf("                     1.添 加 教 师                     \n\n");
   printf("                     2.删 除 教 师                     \n\n");
   printf("                     3.修改教师密码                     \n\n");
   printf("                     4.修改管理员密码                     \n\n");
   printf("                     5.显示所有在职教师                  \n\n");
   printf("                     6.显示所有离职教师                   \n\n");
   printf("                     7.给教师解锁                       \n\n");
   printf("                     8.返回主页面                       \n\n");
}
