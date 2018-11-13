#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct stack1                      //数据栈
{
    float num[MAX];
    int top;
}O_NUM;

typedef struct stack2                      //符号栈
{
    char symbol[MAX];
    int top;
}O_SY;

void init_O_NUM(O_NUM *stacknum)                //初始化数据栈
{
    stacknum->top = -1;
}

void init_O_SY(O_SY *stacksymbol)               //初始化符号栈
{
    stacksymbol->top = -1;
}
int PUSH_Stacknum(O_NUM *stacknum,float num)
{
    if(stacknum->top == MAX-1)
    {
        printf("已经超过输入长度，输入失败!\n");
        return -1;
    }
    stacknum->top++;
    stacknum->num[stacknum->top] = num;
    return 0;
}

int PUSH_Stacksymbol(O_SY *stacksymbol,char ch)
{
    if(stacksymbol->top == MAX-1)
    {
        printf("已经超过输入长度，输入失败!\n");
        return -1;
    }
    stacksymbol->top++;
    stacksymbol->symbol[stacksymbol->top] = ch;
    return 0;
}

float POP_Stacknum(O_NUM *stacknum)
{
    float data = 0;
    data = stacknum->num[stacknum->top];
    stacknum->top--;
    return data;
}

char POP_Stacksymbol(O_SY *stacksymbol)
{
    char ch;
    ch = stacksymbol->symbol[stacksymbol->top];
    stacksymbol->top--;
    return ch;
}

int judge_symbol(char ch)
{
    if(ch == '+'||ch == '-'||ch == '*'|| ch == '/'||ch == '('||ch == ')'||ch == '='||ch == '\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char op_campare(char t1,char t2)
{
    char ch;
    switch(t2)
    {
        case '+':
        case '-':
        {
            ch = (t1 == '('||t1 == '=')?'<':'>';
            break;
        }
        case '*':
        case '/':
        {
            ch = (t1 == '*'||t1 == '/' ||t1 == ')')?'>':'<';
            break;
        }
        case '(':
        {
            if(t1 == ')')
            {
                printf("input error\n");
                return -1;
            }
            else
            {
                ch = '<';
            }
            break;
        }
        case ')':
        {
            switch(t1)
            {
                case '(':
                {
                    ch = '=';
                    break;
                }
                case '=':
                {
                    printf("error input\n");
                    exit(0);
                }
                default:ch = '>';
            }
            break;
        }
        case '=':
        {
            switch(t1)
            {
                case '=':
                {
                    ch = '=';
                    break;
                }
                case '(':
                {
                    printf("error input!\n");
                    return -1;
                }
                default:ch = '>';
            }
        }
    }
    return ch;
}

float calculate(float num1,char op,char num2)
{
    float result;
    switch(op)
    {
        case '+':
        {
            result = num1 + num2;
            break;
        }
        case '-':
        {
            result = num1 - num2;
            break;
        }
        case '*':
        {
            result = num1 * num2;
            break;
        }
        case '/':
        {
            if(num2 == 0)
            {
                printf("error input!\n");
                return -1;
            }
            else
            {
                result = num1/num2;
            }
        }
    }
    return result;
}

float MainCalc()
{
    O_NUM stacknum;                               //操作数
    O_SY stacksymbol;                             //运算符
    float num1,num2,result,num;
    char ch,sign;
    char *str = NULL;
    int count = 0;
    
    init_O_NUM(&stacknum);                        //初始化
    init_O_SY(&stacksymbol);
    
    //将'='计算在运算符栈中
    PUSH_Stacksymbol(&stacksymbol,'=');
    ch = getchar();                              //从键盘读取字符
    while((ch != '=')||stacksymbol.symbol[stacksymbol.top] != '=')
    {
        if(judge_symbol(ch) == 0)
        {
            str = (char *)malloc(sizeof(char)*10);
            do
            {
                *str = ch;
                str++;
                count++;
                ch = getchar();
            }while(judge_symbol(ch) == 0);
            *str = '\0';
            str = str - count;
            num = atof(str);                     //将字符串转换为浮点数
            PUSH_Stacknum(&stacknum,num);        //将数推进操作数栈中
            str = NULL;
            count = 0;
        }
        else
        {
            switch(op_campare(stacksymbol.symbol[stacksymbol.top],ch))
            {
                case '<':
                {
                    PUSH_Stacksymbol(&stacksymbol,ch);
                    ch = getchar();
                    break;
                }
                case '=':
                {
                    sign = POP_Stacksymbol(&stacksymbol);
                    ch = getchar();
                    break;
                }
                case '>':
                {
                    sign = POP_Stacksymbol(&stacksymbol);
                    num2 = POP_Stacknum(&stacknum);
                    num1 = POP_Stacknum(&stacknum);
                    result = calculate(num1,sign,num2);
                    PUSH_Stacknum(&stacknum,result);
                    break;
                }
            }
        }
    }
    result = stacknum.num[stacknum.top];
    return result;
}

int main()
{
    float result;
    
    result = MainCalc();
    printf("%g\n",result);
    return 0;
}

