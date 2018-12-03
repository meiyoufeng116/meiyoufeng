//
//  main.cpp
//  new_1
//
//  Created by Mac on 2018/10/9.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <iostream>
// tiaoshi1.cpp: 定义控制台应用程序的入口点。
//
#include <cstdio>
//#include "stdafx.h"//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define init_stack 10;
#define error "程序错误"
/*typedef struct stack //栈的结构
{
    char *top;
    char *base;
    int size;
}stack;
int initstack(stack &s)//建栈
{
    s.base = (char *)malloc(100 * sizeof(char));
    if (!s.base)
        return -1;
    s.top = s.base;
    s.size = 10;
    return 0;
}
int push(stack &s, char e)//插入栈顶元素
{
    if (s.top - s.base > s.size)
    {
        s.base = (char*)realloc(s.base, (s.size + 100) * sizeof(char));
        if (!s.base) {
            return -1;
        }
        s.top = s.base + s.size;
        s.size += 10;
    }
    *s.top = e;
    s.top++;
    return 0;
}
int Pop(stack &s, char &e)//删除栈顶元素
{
    if (s.top == s.base) {
        return -1;
    }
    e = *--s.top;
    return 0;
}
char Gettop(stack s)//得到栈顶元素
{
    if (s.top == s.base) {
        return -1;
    }
    return *(s.top - 1);
}
/*char Precede(char t, char k2)//比较运算符大小
{
    switch (k2) {
        case '+':
            if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')') {
                return '>';
            }
            else {
                return '<';
            }
            break;
        case '-':
            if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')') {
                return '>';
            }
            else {
                return '<';
            }
            break;
        case '*':
            if (t == '*' || t == '/') {
                return '>';
            }
            else {
                return '<';
            }
            break;
        case '/':
            if (t == '*' || t == '/') {
                return '>';
            }
            else {
                return '<';
            }
            break;
        case '(':
            return '<';
        case ')':
            if (t == '(') {
                return '=';
            }
            else {
                return'>';
            }
        case '#':
            if (t == '#') {
                return '=';
            }
            else {
                return '>';
            }
        default:
            printf("error in precede");
            break;
    }
    return 0;
}
char Precede(char x, char y)
{
    if (x=='+'||x=='-') {
        x='+';
    }
    if (x=='*'||x=='/') {
        x='*';
    }
    switch (x) {
        case '+':
            if (y=='*'||y=='-'||y==')'||y=='#') {
                return '>';
            }else
                return '<';
        case '*':
            if (y==')') {
                return '<';
            }else
                return '>';
        case '(':
            if (y=='(') {
                return '=';
            }
            else
                return '<';
            break;
        case ')':
            return '>';
        case '#':
            if (y=='#') {
                return '=';
            }
            else
                return '<';
        default:
            break;
    }
    return -1;
}

int In(char c)//判断是否是运算符
{
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return 1;
            break;
    }
    return 0;
}
char Operate(char a, char theta, char b)
{
    int x, y;
    char c;
    x = 0; y = 0;
    x = a - '0';
    y = b - '0';
    switch (theta) {
        case '+':c = x + y;
            return c;
        case '-':c = x - y;
            return c;
        case '*':c = x * y;
            return c;
        case '/':
            if (y == 0)
                printf("除数不能为0");
            c = x / y;
            return c;
            break;
            
        default:
            break;
    }
    return 0;
}
char EvaluateExpression(char a[])
{
    
    int i;
    char e;
    e = '#';
    stack OPND, OPTR;
    initstack(OPTR);
    push(OPTR, e);
    initstack(OPND);
    char c, x, d, b, theta;
    c = a[0];i=1;
    while (c != '#' || Gettop(OPTR) != '#') {
        if (0==In(c))//不是运算符就进栈
        {
            push(OPND, c);
            c = a[i];
        }
        else {
            switch (Precede(Gettop(OPTR), c))
            {
                case '<':
                    push(OPTR, c); c = a[i];
                    break;
                case '=':
                    Pop(OPTR, x); c = a[i];
                    break;
                case '>':
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, d);
                    push(OPND, Operate(d, theta, b));
                    break;
            }
        }i++;
   /* for (i = 1; c != '#' || Gettop(OPTR) != '#'; i++)
    {
        if (0==In(c))//不是运算符就进栈
        {
            push(OPND, c);
            c = a[i];
        }
        else {
            switch (Precede(Gettop(OPTR), c))
            {
                case '<':
                    push(OPTR, c); c = a[i];
                    break;
                case '=':
                    Pop(OPTR, x); c = a[i];
                    break;
                case '>':
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, d);
                    push(OPND, Operate(d, theta, b));
                    break;
            }
        }
    }
    return Gettop(OPND);
    //return c;
}
int main()
{
    char a[100], b;
    int c;
    printf("请输入表达式,并以#结尾\n");
    scanf("%s", a);
    b = EvaluateExpression(a);
    c = (int)b;
    printf("输出为%d\n",c);
}*/

// 计算器项目.cpp: 定义控制台应用程序的入口点。
//


typedef struct stack1
{
    double a[100];
    int top;
}OPND;

typedef struct stack2
{
    char b[100];
    int top;
}OPTR;

int push_OPND(stack1 *OPND, double a)
{
    if (OPND->top == 100 - 1)
    {
        printf("input is to looooooong\n");
        return -1;
    }
    OPND->top++;
    OPND->a[OPND->top] = a;
    return 0;
}

int push_OPTR(stack2 *OPTR, char a)
{
    if (OPTR->top == 100 - 1)
    {
        printf("input is to looooooong\n");
        return -1;
    }
    OPTR->top++;
    OPTR->b[OPTR->top] = a;
    return 0;
}
double pop_OPND(stack1 *OPND)
{
    double a = 0;
    a = OPND->a[OPND->top];
    OPND->top--;
    return a;
}

char pop_OPTR(stack2 *OPTR)
{
    char b;
    b = OPTR->b[OPTR->top];
    OPTR->top--;
    return b;
}

void init_OPND(stack1 *opnd)
{
    opnd->top = -1;
}

void init_OPTR(stack2 *optr)
{
    optr->top = -1;
}

int In(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=' || ch == '\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char precede(char f1, char f2)
{
    char a;
    switch (f2)
    {
        case'+':
        case'-':
        {
            a = (f1 == '(' || f1 == '=') ? '<' : '>';
            break;
        }
        case'*':
        case'/':
        {
            a = (f1 == '*' || f1 == '/' || f1 == ')') ? '>' : '<';
            break;
        }
        case'(':
        {
            if (f1 == ')')
            {
                printf("括号有问题1\n");
                return -1;
            }
            else
            {
                a = '<';
            }
            break;
        }
        case')':
        {
            switch (f1)
            {
                case'(':
                {
                    a = '=';
                    break;
                }
                case'=':
                {
                    printf("括号有问题2\n");
                    return -1;
                    break;
                }
                default:a = '>';
            }
            
        }
        case'=':
        {
            switch (f1)
            {
                case'=':
                {
                    a = '=';
                    break;
                }
                case'(':
                {
                    printf("括号有问题3\n");
                    return -1;
                    
                }
                default:a = '>';
            }
            
        }
    }
    return a;
}
char bijiao(char t1,char t2)
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
double calculate(double x, char op, char y)
{
    double z = 0.0;
    switch (op)
    {
        case'+':
        {
            z = x + y;
            break;
        }
        case'-':
        {
            z = x - y;
            break;
        }
        case'*':
        {
            z = x * y;
            break;
        }
        case'/':
        {
            if (y == 0)
            {
                printf("除数不能等于0\n");
                return -1;
            }
            else
            {
                z = x / y;
                
            }
        }
    }
    return z;
}

double evaluateexpression()
{
    OPND opnd;
    OPTR optr;
    double num1, num2, result, num;
    char ch1, sign;
    char *str = NULL;
    int i = 0;
    init_OPND(&opnd);
    init_OPTR(&optr);
    push_OPTR(&optr, '=');
    ch1 = getchar();
    while ((ch1 != '=') || optr.b[optr.top] != '=')
    {
        if (In(ch1) == 0)
        {
            str = (char*)malloc(sizeof(char) * 10);
            do
            {
                *str = ch1;
                str++;
                i++;
                ch1 = getchar();
            } while (In(ch1) == 0);
            *str = '\0';
            str=str-i;
            num = atof(str);
            push_OPND(&opnd, num);
            str = NULL;
            i = 0;
        }
        else
        {
            switch (bijiao(optr.b[optr.top], ch1))
            {
                case'<':
                {
                    push_OPTR(&optr, ch1);
                    ch1 = getchar();
                    break;
                }
                case'=':
                {
                    sign = pop_OPTR(&optr);
                    ch1 = getchar();
                    break;
                }
                case'>':
                {
                    sign = pop_OPTR(&optr);
                    num2 = pop_OPND(&opnd);
                    num1 = pop_OPND(&opnd);
                    result = calculate(num1, sign, num2);
                    push_OPND(&opnd, result);
                    break;
                }
            }
            
        }
    }
    result = opnd.a[opnd.top];
    return result;
}
int main()
{
    double a;
    printf("请输入表达式：");
    a = evaluateexpression();
    printf("计算的结果为%f", a);
    return 0;
}
