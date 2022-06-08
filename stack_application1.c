//stack application converting infix expression to postfix expression
#include<stdio.h>

char stk[50];
int top=-1;

int is_empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char ch){
    top++;
    stk[top]=ch;
}

char pop(){
    char ch=stk[top];
    top--;
    return ch;
}

int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    else if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return 0;
    }
}

int main(){
    char infix[30],postfix[30],ch;
    int i,pi=0;
    printf("enter infix expression\n");
    gets(infix);
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[pi++]=infix[i];            
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(1){
                ch=pop();
                if(ch=='('){
                    break;
                }
                postfix[pi++]=ch;
            }
        }
        else{
            while(!is_empty()){
                if(precedence(infix[i])<=precedence(stk[top])){
                    ch=pop();
                    postfix[pi++]=ch;
                }
                else{
                    break;
                }
            }
            push(infix[i]);
        }
    }
    while(!is_empty()){
        postfix[pi++]=pop();
    }
    postfix[pi]='\0';
    printf("Postfix expression of the given infix expression %s is %s",infix,postfix);
}
