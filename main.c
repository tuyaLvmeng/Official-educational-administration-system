#include<stdlib.h>
#include<getch.h>
#include"tool.h"
#include"interface.h"

int main()
{
	system("clear");
	while(true)
	{
		system("clear");
		interface_enum();
		switch(getch())
		{
			case CHOOSE_ONE:student_in();
			break;
			case CHOOSE_TWO:teacher_in();
			break;
			case CHOOSE_THREE:admin_in();
			break;
			case CHOOSE_FOUR:
			{
				printf("欢迎下次使用!!\n");
				anykey_continue();
				exit(0);
			}
			default:
			{	
				printf("输入有误，请重新输入！！");
				anykey_continue();
				break;
			}
		}
	}
	return 0;
}
