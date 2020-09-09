#ifndef STUDENT_H
#define STUDENT_H

#define S_NAME 2000    		//学生姓名长度
#define S_NUMBER 20  	 	//学生学号长度
#define S_PASS 20  			//密码长度
#define S_COUNT 1000		//学生人数

typedef struct Student  	//学生结构体
{
    char name[S_NAME];  	//姓名
    char sex; 				//性别
    char number[S_NUMBER]; 	//学号
    char password[S_PASS]; 	//密码 数字、字母、不允许符号、长度20以内；
    int chinese; 			//语文 判断数字
    int math; 				//数学 判断数字
    int english; 			//英语
	int sum;				//总分
    int landing; 			//登陆的次数 第一次强制要求修改密码
    int Account_status;		//账号状态 1正常 0锁定
}Student;

extern Student stu[S_COUNT];
extern Student s;

extern int s_count;

extern int s_position;

void sorce(void);			//成绩

void Pass(void);			//更改密码

void Allmessage(void);		//显示信息

#endif //STUDENT_H
