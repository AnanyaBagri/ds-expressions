#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


char stk[20];
int top=-1;

void push(char x)
{
	top++;
	stk[top]=x;
}
char pop()
{
	char x;
	x=stk[top];
	top--;
	return(x);
}

int preced(char);

main()
{
	char infix[20],prefix[20],ch,sc;
	int i,j,k=0,l;
	system("cls");
	printf("\n\tenter any infix expresssion : ");
	gets(infix);
	l=strlen(infix);
	push('#');              ///*** dummy operator with lowest precedence
	for(i=l-1;i>=0;i--)        ///*** scan infix expression from right to left
	{
		sc=infix[i];        ///*** sc is scanned symbol
		switch(sc)          ///*** make sc as switch variable
		{
			case ')':
			push(sc);
			break;

			case '(':
			ch=pop();
			while(ch!=')')
			{
				prefix[k++]=ch;
				ch=pop();
			}
			break;

			case '^':
			case '/':
			case '*':
			case '+':
			case '-':
			if(preced(sc) >= preced(stk[top]))
			{
				push(sc);
			}
			else
			{
				while(preced(sc) < preced(stk[top]))
				{
					ch=pop();
					prefix[k++]=ch;        ///*** or  prefix[k++]=pop();  ****//
				}
				push(sc);
			}
			break;

			default:
			prefix[k++]=sc;
			break;

		}

	}
	while(top>0)            ///******** pop all the elements from stack and add into prefix expression //
	{
		prefix[k++]=pop();
	}
	prefix[k]='\0';
	strrev(prefix);
	printf("\n\n\tprefix expression : %s",prefix);
	getch();

}


int preced(char x)          ///**** function to set precedence of operators
{
	int p;
	switch(x)
	{
		case '^':
		p=5;
		break;

		case '/':
		p=4;
		break;

		case '*':
		p=3;
		break;

		case '+':
		p=2;
		break;

		case '-':
		p=1;
		break;

		case '(':
		p=0;
		break;

		case '#':
		p=-1;
		break;

	}
	return(p);
}


