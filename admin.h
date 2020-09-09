#ifndef ADMIN_H
#define ADMIN_H

#define A_NAME 20  		//管理员姓名长度
#define A_NUMBER 20 	//管理员学号长度
#define A_PASS 20		//管理员密码长度
//#define A_COUNT 10	//管理员数量

typedef struct Admin  	//管理员结构体
{
	char name[A_NAME];  	//姓名
	char sex;    			//性别
	char number[A_NUMBER];  //工号
	char password[A_PASS]; 	//密码 数字、字母、不允许符号、长度20以内；
	int landing;			//登陆的次数 第一次强制要求修改密码
}Admin;

extern Admin adm;

//修改自己的密码
void a_change_password_myself(void);

//重置自己的密码
//void a_reset_password_myself(void);

//重置教师密码
void a_reset_password_teacher(void);

//添加教师
void a_add_teacher(void);

//删除教师
void a_delete_teacher(void);

//显示所有在职教师
void a_show_in_teacher(void);

//显示所有离职教师
void a_show_down_teacher(void);

//给教师解锁
void a_unlock(void);

#endif//ADMIN_H
