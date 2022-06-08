// stack application checking parenthesis matching
#include<stdio.h>

char stk[20];
int top=-1;

void push(char ch){
    top++;
    stk[top]=ch;
}

char pop(){
    if(top==-1){
        return '\0';
    }
    else{
        char ch=stk[top];
        top--;
        return ch;
    }
}

int main(){
    char exp[30],ch;
    int i,f=0;
    printf("enter an expression to check parenthesis matching\n");
    gets(exp);
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
            push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            ch=pop();
            if(ch=='\0'||(ch=='(' && exp[i]!=')')||(ch=='[' && exp[i]!=']')||(ch=='{' && exp[i]!='}')){
                f=1;
                break;
            }
        }
    }
    if(top==-1 && f==0){
        printf("parenthesis matched");
    }
    else{
        printf("parenthesis not matched");
    }
}
