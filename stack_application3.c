// stack application evaluating a postfix expression
#include<stdio.h>

int is_operator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

int perform_operation(int x,int y,char ch){
    switch(ch){
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
        default:
            printf("invalid operator\n");
            return 0;
    }
}

int main(){
    int stk[20],top=-1,i,x,y,z;
    char postfix[50];
    printf("enter a postfix expression to evaluate\n");
    gets(postfix);
    for(i=0;postfix[i]!='\0';i++){
        if(is_operator(postfix[i])){
            y=stk[top--];
            x=stk[top--];
            z=perform_operation(x,y,postfix[i]);
            stk[++top]=z;
        }
        else{
            stk[++top]=postfix[i]-48;//int num=[(ascii value of char num i.e,ranging from 48 to 57)-(ascii value of char 0 i.e.48)]
        }
    }
    printf("result of given postfix expression %s is %d",postfix,stk[top]);
}
