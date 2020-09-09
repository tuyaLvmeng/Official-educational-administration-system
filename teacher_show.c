#include"tool.h"
#include"teacher_show.h"
#include"teacher.h"
#include"interface.h"

//教师登录
void teacher_in(void)
{
	int miscount=0;
	s_count=0;
	t_count=0;
	FILE *frp = fopen("teacher.txt","r");
	if(NULL==frp)
	{
		printf("文件打开失败!!!");
		return;
	}
	while(!feof(frp))
	{
		fscanf(frp,"%s %c %s %s %d %d\n",tea[t_count].name,
		&tea[t_count].sex,tea[t_count].number,tea[t_count].password,
		&tea[t_count].landing,&tea[t_count].Account_status);
		t_count++;
	}
	fclose(frp);

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

	printf("请输入你的工号:");
	get_number(number,T_NUMBER);
	
	for(int i=0;i<T_COUNT;i++)
	{
		if(strcmp(tea[i].number,number)==0&&tea[i].sex!=0)
		{
			if(tea[i].Account_status==0)
			{
				printf("账号已锁定，请联系管理员解锁!!");
				anykey_continue();
				return;
			}
			while(true)
			{
				printf("请输入你的密码:");
				get_passwd(password,T_PASS,true);
				if(strcmp(password,tea[i].password)==0)
				{
					printf("登录成功!!!!");
					t=tea[i];
					t_position=i;
					anykey_continue();
					if(t.landing==0)
					{
						printf("\n第一次登录请更改你的密码:");
						while(true)
						{
							get_passwd(password,T_PASS,true);
							if(islegal_pass(password))
							{
								strcpy(t.password,password);
								printf("修改成功!!");
								t.landing=1;
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
					teacher_show();
					return;
				}
				else
				{
					miscount++;
					if(miscount>=3)
					{
						tea[i].Account_status=0;
						printf("密码错误超过３次，账号已锁定，请联系管理员解锁!!");
						FILE *fwp = fopen("teacher.txt","w");
						if(NULL==fwp)
						{
							printf("文件打开失败!!!");
							return;
						}
						for(int i=0;i<T_COUNT;i++)
						{
							if(tea[i].sex!=0)
							{
								fprintf(fwp,"%s %c %s %s %d %d\n",tea[i].name,
								tea[i].sex,tea[i].number,tea[i].password,
								tea[i].landing,tea[i].Account_status);
							}
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

//教师操作
void teacher_show(void)
{
	system("clear");
	while(true)
	{
		system("clear");
		teacher_enum();
		switch(getch())
		{
			case CHOOSE_ONE:t_add_stu();
			anykey_continue();
			break;
			case CHOOSE_TWO:t_delete_stu();
			anykey_continue();
			break;
			case CHOOSE_THREE:t_psearch_stu();
			anykey_continue();
			break;
			case CHOOSE_FOUR:t_modify_stu();
			anykey_continue();
			break;
			case CHOOSE_FIVE:t_import_stu_score();
			anykey_continue();
			break;
			case CHOOSE_SIX:t_reset_stu_pass();
			anykey_continue();
			break;
			case CHOOSE_SEVEN:t_show_stu();
			anykey_continue();
			break;
			case CHOOSE_EIGHT:t_show_drop_stu();
			anykey_continue();
			break;
			case CHOOSE_NIGHT:t_unlock();
			break;
			case CHOOSE_ZERO:
			{
				tea[t_position]=t;
				FILE *fwp = fopen("student.txt","w");
				if(NULL==fwp)
				{
					printf("文件打开失败!!!");
					return;
				}
				FILE *fw=fopen("teacher.txt","w");
				if(NULL==fw)
				{
					printf("文件打开失败!!!");
					return;
				}
				for(int i=0;i<T_COUNT;i++)
				{
					if(tea[i].sex!=0)
					fprintf(fw,"%s %c %s %s %d %d\n",tea[i].name,
					tea[i].sex,tea[i].number,tea[i].password,
					tea[i].landing,tea[i].Account_status);
				}
				for(int i=0;i<S_COUNT;i++)
				{
					if(stu[i].sex!=0)
					fprintf(fwp,"%s %c %s %s %d %d %d %d %d\n",stu[i].name,
					stu[i].sex,stu[i].number,stu[i].password,stu[i].chinese,
					stu[i].math,stu[i].english,stu[i].landing,stu[i].Account_status);
				}
				fclose(fwp);
				fclose(fw);	
				return;
				break;
			}
			default:printf("输入有误，请重新输入!!!");
			break;
		}
	}
}
