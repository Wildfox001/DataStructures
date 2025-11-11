#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double compute(char symbol, double op1, double op2);
double compute(char symbol, double op1, double op2){
    switch(symbol){
        case '+': return op1+op2;
        break;
        case '-': return op1-op2;
        break;
        case '*': return op1*op2;
        break;
        case '/': return op1/op2;
        break;
        case '^': return pow(op1,op2);
        break;
    }
}

void main(){
    double s[20], res, op1, op2;
    int top=-1, i;
    char postfix[20], symbol;
    printf("Enter a valid postfix expression:\n");
    scanf("%s",postfix);

    for(i=0;i<strlen(postfix);i++){
        symbol = postfix[i];
        if(isdigit(symbol)){
            s[++top] = symbol - '0';
        }
        else{
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1 , op2);
            s[++top] = res;
        }
    }
    res = s[top--];
    printf("\n The postfix evaluation result: %f",res);
}

6.TOWER OF HANOI

#include<stdio.h>
void tower(int,char,char,char);
void main()
{
  	int n;
  	printf("Enter the no.of discs\n");
  	scanf("%d",&n);
 	tower(n,'S','D','T');
    printf("Total moves: %d\n", moveCount);
    return 0;
 }
 void tower(int n,char from,char to,char temp)
 {
  	 if(n==0)
   		return;
  	 else
  	 {
    		 tower(n-1,from,temp,to);
    		 printf("Move disc %d from %c to %c\n",n,from,to);
    		 moveCount++;
    		 tower(n-1,temp,to,from);
   	}
 }
