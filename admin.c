#include"admin.h"
#include"tool.h"
#include"teacher.h"

//管理员账号
Admin adm={"xixi",'m',"9527","123456",0};

//修改自己的密码
void a_change_password_myself(void)
{
	char new[A_PASS];
	while(true)
	{
		printf("请输入新的密码：");
		get_passwd(new,A_PASS,false);
		if(islegal_pass(new))
		{
			strcpy(adm.password,new);
			printf("修改成功!!");
			anykey_continue();
			return;
		}
		else
		{
			printf("密码不合法，重新输入!!!");
			anykey_continue();
		}
	}
}

//重置自己的密码
//void a_reset_password_myself(void)
//{
//	printf("是否确定重置密码!!!!(y/n)");
//	char temp=getchar();
//	if(temp=='Y'||temp=='y')
//	{
//		strcpy(adm.password,"123456");
//		printf("初始化成功!!初始密码为123456");
//		anykey_continue();
//		return;
//	}
//}

//重置教师密码
void a_reset_password_teacher(void)
{
	char number[T_NUMBER];
	char new[T_PASS];
	printf("请输入要修改的教师的工号：");
	get_number(number,T_NUMBER);
	for(int i=0;i<T_COUNT;i++)
	{
		if(strcmp(tea[i].number,number)==0&&tea[i].sex!=0)
		{
			while(true)
			{
				printf("\n请输入修改后该教师的密码:");
				get_passwd(new,T_PASS,true);
				if(islegal_pass(new))
				{
					strcpy(tea[i].password,new);
					printf("修改成功！！！");
					anykey_continue();
					return;
				}
				else
				{
					printf("密码不合法，请重新输入！！！");
					anykey_continue();
				}
			}
		}
	}
	printf("未找到该教师，请重新确认后再进行修改！！！");
	anykey_continue();
	return;
}

//添加教师
void a_add_teacher(void)
{
	if(t_count>T_COUNT)
	{
		printf("ｖｉｐ可享受更多存储空间!!!");
		return;
	}
	int the_number=0;
	for(int i=0;i<T_COUNT;i++)
	{
		if(tea[i].sex==0)
		{
			the_number=i;
			break;
		}
	}
	char name[T_NAME];
	char sex;
	char number[T_NUMBER];
	printf("请输入教师姓名：");
	scanf("%s",name);
	strcpy(tea[the_number].name,name);
	printf("请输入教师性别: ");
	while(true)
	{
		scanf(" %c",&sex);
		if('w'==sex||'m'==sex)
		{
			tea[the_number].sex=sex;
			break;
		}
		printf("输入有误请重新输入!!!\n");
	}
	printf("请输入教师的工号:");
	while(true)
	{
		int f=0;
		get_number(number,T_NUMBER);
		for(int i=0;i<t_count;i++)
		{
			if(strcmp(tea[i].number,number)==0)
			{
				printf("该工号已存在,请重新输入!!!\n");
				f=1;
				break;
			}
		}
		if(f==0)
		{
			strcpy(tea[the_number].number,number);
			break;
		}
	}
	printf("请输入教师的密码:");
	while(true)
	{
		char password[T_PASS];
		get_passwd(password,T_PASS,true);
		if(islegal_pass(password))
		{
			strcpy(tea[the_number].password,password);
			break;
		}
		else
		{
			printf("密码不合法请重新输入!!!\n");
			anykey_continue();
		}
	}
	tea[the_number].landing=0;
	tea[the_number].Account_status=1;
	printf("录入成功");
	t_count++;
	anykey_continue();
}

//删除教师
void a_delete_teacher(void)
{
	char number[T_NUMBER];
	printf("请输入要删除的教师的工号：");
	get_number(number,T_NUMBER);
	for(int i=0;i<T_COUNT;i++)
	{
		if(strcmp(tea[i].number,number)==0&&tea[i].sex!=0)
		{
			//文件存储离职教师的信息
			//删除离职老师的信息
			FILE *fwp = fopen("downteacher.txt","a");
			if(NULL==fwp)
			{
				printf("文件打开失败！！");
				return;
			}
			fprintf(fwp,"%s %c %s",tea[i].name,tea[i].sex,tea[i].number);
			fclose(fwp);
			tea[i].sex=0;
			t_count--;
			printf("删除成功！！！");
			anykey_continue();
			return;
		}
	}
	printf("未找到该老师的工号！！");
	anykey_continue();
}

//显示所有在职教师
void a_show_in_teacher(void)
{
	for(int i=0;i<T_COUNT;i++)
	{
		if(tea[i].sex!=0)
		{
			printf("姓名:%s ",tea[i].name);
			printf("性别:%s ",tea[i].sex=='w'?"女":"男");
			printf("编号:%s\n",tea[i].number);
		}
	}
	anykey_continue();
}

//显示所有离职教师
void a_show_down_teacher(void)
{
	char name[T_NAME];
	char sex;
	char number[T_NUMBER];
	FILE *frp = fopen("downteacher.txt","r");
	if(NULL==frp)
	{
		printf("文件打开失败!!");
		return;
	}
	while(!feof(frp))
	{
		fscanf(frp,"%s %c %s",name,&sex,number);
		printf("姓名:%s 性别:%s 编号:%s\n",name,sex=='w'?"女":"男",number);
		anykey_continue();
	}
	fclose(frp);
}

//给教师解锁
void a_unlock(void)
{
	char number[T_NUMBER];

	printf("请输入要解锁的教师工号:");
	get_number(number,T_NUMBER);

	while(true)
	{
		for(int i=0;i<T_COUNT;i++)
		{
			if(strcmp(tea[i].number,number)==0&&tea[i].Account_status==0)
			{
				tea[i].Account_status=1;
				printf("解锁成功!!");
				anykey_continue();
				return;
			}
			else if(strcmp(tea[i].number,number)==0)
			{
				printf("你输入的教师状态为未锁定请重新确认！！");
				anykey_continue();
				return;
			}
		}
		printf("你找到工号不存在!!!");
		anykey_continue();
		return;
	}
}
