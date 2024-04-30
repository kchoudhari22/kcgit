#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_s{
    char ch;
    struct node_s *next;
}node_t;

typedef struct{
    node_t *top;
}stack_t;

void push(stack_t*,char);
void print(stack_t*);
char peak(stack_t*);
void pop(stack_t*);
int empty(stack_t*);
int main(){
    //Initialize the Stack
    stack_t *stack=malloc(sizeof(stack_t));
    stack->top=NULL;
    char *seq=malloc(sizeof(char)*50);
    //Take the sequence as input
    printf("Provide the sequence");
    scanf("%s",seq);
    for (int i=0;i<strlen(seq);i++)
    {
        if (seq[i]=='('||seq[i]=='['||seq[i]=='{')
                push(stack,seq[i]);
        else if(seq[i]==')')
        {
            char ch=peak(stack);
            if(ch=='(')
                pop(stack);
        }
        else if(seq[i]==']')
        {
            char ch=peak(stack);
            if(ch=='[')
                pop(stack);
        }
        else if(seq[i]=='}')
        {
            char ch=peak(stack);
            if(ch=='{')
                pop(stack);
        }
    }
    int t=empty(stack);
    if(t==0)
        printf("Sequence is Complete");
    else if(t==1)
        printf("Sequence is Incomplete");
        print(stack);
}
void push(stack_t *stack,char ch)
{
    node_t *tmp=malloc(sizeof(node_t));
    tmp->ch=ch;
    tmp->next=stack->top;
    stack->top=tmp;
}

char peak(stack_t* stack)
{
    return(stack->top->ch);
}
void pop(stack_t* stack)
{
    stack->top=stack->top->next;
}
int empty(stack_t *stack)
{
    if (stack->top==NULL)
        return 0;
    else
        return 1;
}
void print(stack_t *stack)
{
    node_t *trav=stack->top;
    while(trav!=NULL)
    {
        printf("%c->",trav->ch);
        trav=trav->next;
    }
}

