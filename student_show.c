#include<string.h>
#include"student_show.h"
#include"student.h"
#include"tool.h"
#include"interface.h"
#include"teacher.h"

//学生登录
void student_in(void)
{
	int miscount=0;
	s_count=0;
	FILE *fwwp = fopen("student.txt","r");
	if(NULL==fwwp)
	{
		printf("文件打开失败!!!");
		return;
	}
	while(!feof(fwwp))
	{
		fscanf(fwwp,"%s %c %s %s %d %d %d %d %d\n",stu[s_count].name,
		&stu[s_count].sex,stu[s_count].number,stu[s_count].password,
		&stu[s_count].chinese,&stu[s_count].math,&stu[s_count].english,
		&stu[s_count].landing,&stu[s_count].Account_status);
		s_count++;
	}
	fclose(fwwp);
	char number[T_NUMBER];
	char password[T_PASS];
	printf("请输入你的学号:");
	get_number(number,T_NUMBER);
	for(int i=0;i<S_COUNT;i++)
	{
		if(strcmp(stu[i].number,number)==0&&stu[i].sex!=0)
		{
			if(stu[i].Account_status==0)
			{
				printf("账号已锁定，请联系老师解锁!!");
				anykey_continue();
				return;
			}
			while(true)
			{
				printf("请输入你的密码:");
				get_passwd(password,T_PASS,true);
				if(strcmp(password,stu[i].password)==0)
				{
					printf("登录成功!!!!");
					s=stu[i];
                    s.sum=s.chinese+s.math+s.english;
					s_position=i;
					anykey_continue();
					if(s.landing==0)
					{
						printf("\n第一次登录请更改你的密码:");
						while(true)
						{
							get_passwd(password,T_PASS,true);
							if(islegal_pass(password))
							{
								strcpy(s.password,password);
								printf("修改成功!!");
								s.landing=1;
								anykey_continue();
								break;						
							}
							else
							{
								printf("输入有误请重新输入!!!\n");
								anykey_continue();
							}
						}				
					}
					student_show();
					return;
				}
				else
				{
					miscount++;
					if(miscount>=3)
					{
						stu[i].Account_status=0;
						printf("密码错误超过３次，账号已锁定，请联系教师解锁!!");
						FILE *fwp = fopen("student.txt","w");
						if(NULL==fwp)
						{
							printf("文件打开失败!!!");
							return;
						}
						for(int i=0;i<S_COUNT;i++)
						{
							if(stu[i].sex!=0)
							fprintf(fwp,"%s %c %s %s %d %d %d %d %d\n",stu[i].name,
							stu[i].sex,stu[i].number,stu[i].password,stu[i].chinese,
							stu[i].math,stu[i].english,stu[i].landing,stu[i].Account_status);
						}
						fclose(fwp);
						anykey_continue();
						return;
					}
				}
			}
		}
	}
}

//学生操作
void student_show(void)
{
	system("clear");
	while(true)
	{
		system("clear");
		student_enum();
		switch(getch())
		{
			case CHOOSE_ONE:sorce();
			break;
			case CHOOSE_TWO:Pass();
			break;
			case CHOOSE_THREE:Allmessage();
			break;
			case CHOOSE_FOUR:
			{
				stu[s_position]=s;
				FILE *fwp = fopen("student.txt","w");
				if(NULL==fwp)
				{
					printf("文件打开失败!!!");
					return;
				}
				for(int i=0;i<S_COUNT;i++)
				{
					if(stu[i].sex!=0)
					fprintf(fwp,"%s %c %s %s %d %d %d %d %d\n",stu[i].name,
					stu[i].sex,stu[i].number,stu[i].password,stu[i].chinese,
					stu[i].math,stu[i].english,stu[i].landing,stu[i].Account_status);
				}
				fclose(fwp);
				return;
			}
			default:printf("输入有误，请重新输入!!!");
			break;
		}
	}
}
