#include<stdio.h>    
#include<string.h> 
#include <conio.h>
#include <stdlib.h>
char str[50]; 
int index=0; 
void E();//��һ��ʽ�ӿ�ʼ�ж�                    
void X();//�ж�+ - ����                         
void T();//�ж�������ŵ����ȼ�������*/��+-      
void Y();//�ж�* / ����                          
void F();//�ж���һ���ַ��Ƿ�Ϸ�                

int main()                /*�ݹ����*/
{ 
    int len; 
    int m; 
    printf("������Ҫ���ԵĴ�����"); 
    scanf("%d",&m); 
    while(m--) 
    { 
        printf("�������ַ���(����<50>��:\n"); 
        scanf("%s",str);
        len=strlen(str);
       
        str[len+1]='\0'; 
        E(); 
        printf("%sΪ�Ϸ����Ŵ�!\n",str); 
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
	
    else if (str[index]=='��') 
    { 
        index++; 
        E(); 
      
	    if(str[index]==')') 
        {     
		index++; 
		}
	
		else
        { 
            printf("\n�Ƿ��ķ��Ŵ�!\n");
            exit(0);
        }     
		
	} 
    else
    {
        printf("�Ƿ��ķ��Ŵ�!\n"); 
       exit(0);
    } 
}
