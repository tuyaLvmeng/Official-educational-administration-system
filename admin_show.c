#include"interface.h"
#include"tool.h"
#include"admin_show.h"
#include"admin.h"
#include"teacher.h"

//管理员登录
void admin_in(void)
{
	char number[A_NUMBER];
	char password[A_PASS];
	printf("请输入你的账号:");
	get_number(number,A_NUMBER);
	if(strcmp(adm.number,number)==0)
	{
		FILE *frp= fopen("admin.txt","r");
		if(NULL==frp)
		{
			printf("文件打开失败！！");
			return;
		}
		int landing;
		fscanf(frp,"%s %s %d\n",number,password,&landing);
		strcpy(adm.password,password);
		adm.landing=landing;
		printf("请输入你的密码:");
		get_passwd(password,A_PASS,true);
		if(strcmp(adm.password,password)==0)
		{
			printf("登录成功!!");
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
			anykey_continue();
			if(adm.landing==0)
			{
				printf("\n第一次登录请更改你的密码:");
				while(true)
				{
					get_passwd(password,A_PASS,true);
					if(islegal_pass(password))
					{
						strcpy(adm.password,password);
						printf("修改成功!!");
						adm.landing=1;
						anykey_continue();
						break;						
					}
					else
					{
						printf("输入有误请重新输入!!!");
					}
				}				
			}
			admin_show();
			return;
		}
	}
	printf("密码或者账号错误!!!!");
	anykey_continue();
	return;
}

//管理员操作
void admin_show(void)
{
	system("clear");
	while(true)
	{
		system("clear");
		admin_enum();
		switch(getch())
		{
			case CHOOSE_ONE:a_add_teacher();
			break;
			case CHOOSE_TWO:a_delete_teacher();
			break;
			case CHOOSE_THREE:a_reset_password_teacher();
			break;
			case CHOOSE_FOUR:a_change_password_myself();
			break;
			case CHOOSE_FIVE:a_show_in_teacher();
			break;
			case CHOOSE_SIX:a_show_down_teacher();
			break;
			case CHOOSE_SEVEN:a_unlock();
			break;
			case CHOOSE_EIGHT:
			{
				FILE *fwp = fopen("teacher.txt","w");
				if(NULL==fwp)
				{
					printf("文件打开失败!!!");
					return;
				}
				FILE *fw=fopen("admin.txt","w");
				if(NULL==fw)
				{
					printf("文件打开失败!!!");
					return;
				}
				for(int i=0;i<T_COUNT;i++)
				{
					if(tea[i].sex!=0)
					fprintf(fwp,"%s %c %s %s %d %d\n",tea[i].name,
					tea[i].sex,tea[i].number,tea[i].password,
					tea[i].landing,tea[i].Account_status);
				}
				fprintf(fw,"%s %s %d",adm.number,adm.password,adm.landing);
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
