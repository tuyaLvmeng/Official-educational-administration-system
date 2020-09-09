#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<getch.h>
#include"student.h"
#include"tool.h"

Student stu[S_COUNT];
Student s;

int s_position=0;

int s_count=0;

//成绩操作(查看)
void sorce(void)
{
	int ranking=1;
	Student a;
	int max=-1,min=101;
	for(int i=0;i<S_COUNT;i++)
	{
		if(stu[i].sex!=0)
		{
	 	    stu[i].sum=stu[i].math+stu[i].chinese+stu[i].english;
			if(stu[i].sum>max) max=stu[i].sum;
			if(stu[i].sum<min) min=stu[i].sum;
			if(s.sum<stu[i].sum) ranking++;
		}
	}	
	printf("1.排名 2.平均分 3.最高分 4.最低分");
	switch(getch())
	{
		case CHOOSE_ONE:printf("\n你的排名为:%d",ranking);
		anykey_continue();
		break;
		case CHOOSE_TWO:printf("\n你的平均分为:%d",s.sum/3);
		anykey_continue();
		break;
		case CHOOSE_THREE:printf("\n最高分为:%d",max);
		anykey_continue();
		break;
		case CHOOSE_FOUR:printf("\n最低分为:%d",min);
		anykey_continue();
		break;
	}
}


//更改密码
void Pass(void)
{
	char pass1[S_PASS],pass2[S_PASS],pass3[S_PASS];
	for(;;)
	{
		printf("输入原密码:\n");
		get_passwd(pass1,S_PASS,true);
		if(strcmp(pass1,s.password)==0)
		{
			printf("输入要更改的密码:\n");
			get_passwd(pass2,S_PASS,true);
		}
		else
	    {
    	    printf("原密码错误重新输入:\n");
			continue;
             }
		if(islegal_pass(pass2))
		{
			printf("再次输入密码:\n");
			get_passwd(pass3,S_PASS,true);
		}
	    else
	    {
     	     printf("输入不合法");
			 continue;
	    }
		if(strcmp(pass3,pass2)==0)
		{
			strcpy(s.password,pass3);
            for(int i=0;i<S_COUNT;i++)
			{
				if(strcmp(s.number,stu[i].number)==0)
				{
					stu[i]=s;
					stu[i].landing=1;
				}
			}
			printf("修改成功\n");
			anykey_continue();
			return;
		}
		else
		{
			printf("修改失败,请重新输入\n");
			anykey_continue();
			continue;
	    }
    }		
}

//显示信息
void Allmessage(void)
{
    for(int i=0;i<S_COUNT;i++)	        
	{
     	if(strcmp(s.number,stu[i].number)==0)
        {
            printf("姓名:%s ",stu[i].name);
		 	printf("性别:%c ",stu[i].sex);
		 	printf("学号:%s ",stu[i].number);
			printf("语文:%d ",stu[i].chinese);
			printf("数学:%d ",stu[i].math);
			printf("英语:%d\n",stu[i].english);
			anykey_continue();
        }
    }
}
