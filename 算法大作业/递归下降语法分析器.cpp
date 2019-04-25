#include<stdio.h>    
#include<string.h> 
#include <conio.h>
#include <stdlib.h>
char str[50]; 
int index=0; 
void E();//对一个式子开始判断                    
void X();//判断+ - 符号                         
void T();//判断运算符号的优先级，即先*/后+-      
void Y();//判断* / 符号                          
void F();//判断这一个字符是否合法                

int main()                /*递归分析*/
{ 
    int len; 
    int m; 
    printf("请输入要测试的次数："); 
    scanf("%d",&m); 
    while(m--) 
    { 
        printf("请输入字符串(长度<50>）:\n"); 
        scanf("%s",str);
        len=strlen(str);
       
        str[len+1]='\0'; 
        E(); 
        printf("%s为合法符号串!\n",str); 
        strcpy(str,""); 
        index=0;
    } return 0; 
} 

void E() 
{     
T();    
X();
}

void X() 
{ 
    if(str[index]=='+'||str[index]=='-')
    {     index++; 
        T(); 
        X(); 
    } 
} 

void T() 
{     
F();
Y(); 
}
 
void Y() 
{     
if(str[index]=='*'||str[index]=='/') { 
        index++; 
        F(); 
        Y(); 
    } 
} 

void F() 
{ 
    if((str[index]>='A'&&str[index]<='Z')||(str[index]>='a'&&str[index]<='z')||(str[index]>='0'&&str[index]<='9'))
    {    
	index++; 
	} 
	
    else if (str[index]=='（') 
    { 
        index++; 
        E(); 
      
	    if(str[index]==')') 
        {     
		index++; 
		}
	
		else
        { 
            printf("\n非法的符号串!\n");
            exit(0);
        }     
		
	} 
    else
    {
        printf("非法的符号串!\n"); 
       exit(0);
    } 
}
