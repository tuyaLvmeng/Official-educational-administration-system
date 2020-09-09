#include"tool.h"


//按任意键继续
void anykey_continue(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	printf("\n请按任意键继续...");
	getch();
}


//判断密码长度是否大于6或者小于20
//判断密码是否只包含数字和字母
//密码是否合法
bool islegal_pass(const char*pass)
{
	if (6 > strlen(pass) || strlen(pass) > 19)
	{
		return  false;
	}

	for (; *pass != '\0'; pass++)
	{
		if (!isalnum(*pass))
		return false;
	}

	return true;
}

//学生信息是否合法
bool is_legalstu(Student s)
{
	if(islegal_pass(s.password)&&0<strlen(s.name)\
	&&strlen(s.name)<20&&(s.sex=='w'||s.sex=='m')\
	&&(islegal_pass(s.number)))
	return true;
	return false;
}

//清空缓存区
void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}

//从键盘获取账号
char* get_number(char* pd,size_t hope_len)
{
	clear_stdin();
    if(NULL == pd) return NULL;

    size_t index = 0;
    while(index < hope_len-1)
    {
        int32_t key_val = getch();
        if(KEY_BACKSPACE == key_val)
        {
            if(index > 0)
            {
                index--;
                printf("\b \b");
            }
        }
        else if('\n' == key_val) break;
        else
        {
            pd[index++] = key_val;
            printf("%c",key_val);
        }
    }
    pd[index] = '\0';
    printf("\n");
    clear_stdin();
    return pd;
}

//从键盘获取密码
char* get_passwd(char* pd,size_t hope_len,bool is_show)
{
	clear_stdin();
    if(NULL == pd) return NULL;

    size_t index = 0;
    while(index < hope_len-1)
    {
        int32_t key_val = getch();
        if(KEY_BACKSPACE == key_val)
        {
            if(index > 0)
            {
                index--;
                is_show ? printf("\b \b") : nil;
            }
        }
        else if('\n' == key_val) break;
        else
        {
            pd[index++] = key_val;
            is_show ? printf("*") : nil;
        }
    }
    pd[index] = '\0';
    printf("\n");
    clear_stdin();
    return pd;
}
