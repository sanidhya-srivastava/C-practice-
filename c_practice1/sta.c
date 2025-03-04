#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 100
struct stack
{
    int top;
    int data[n];
};
void init(struct stack *s)
{
    s->top=-1;
}
int is_empty(struct stack *s){
    return s->top==-1;
}
int is_full(struct stack *s){
    return s->top==n-1;
}
void push(struct stack *s, int x){
    if(is_full(s)){
    printf("stack overflow\n");
    return;
    }
    s->top++;
    s->data[s->top]=x;
}
int pop(struct stack *s)
{
    if(is_empty(s)){
    printf("stack underflow\n");
    return -1;
    }
    int x=s->data[s->top];
    s->top--;
    return x;
}
void display(struct stack *s){
    if(is_empty(s))
    {
        printf("stack is empty\n");
        return;
    }
    for(int i=s->top;i>=0;i--)
    {
        printf(" %d   ",s->data[i]);
    }
    printf("\n");
}
int main()
{
    struct stack s;
    init(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    display(&s);

    printf("Popped: %d\n", pop(&s));
    display(&s);
    return 0;
}