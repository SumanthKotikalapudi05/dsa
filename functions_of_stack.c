#include<stdio.h>

#define MAX 4
int top=-1;
int stack[MAX];

void push(int data){
    if(top<MAX){
        stack[top] = data;
        printf("%d\n",stack[top]);
        top++;
    }
    
}
void pop(int data){
    if(top!=-1){
        top=stack[top-1];
    }
}

int main(){
    push(15);
    push(20);
    push(25);
    push(30);
}