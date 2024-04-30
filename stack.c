#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

typedef struct{
    node_t * top;
}stack_t;

void push(stack_t*,int);
void print(stack_t*);
int main()
{
    stack_t *stack=malloc(sizeof(stack_t));
    stack->top=NULL;
    for (int i=0;i<5;i++)
    {
        int data;
        scanf("%d",&data);
        push(stack,data);
    }
    print(stack);
    return 0;
}

void push(stack_t *stack,int data)
{
    node_t *tmp=malloc(sizeof(node_t));
    tmp->data=data;
    tmp->next=stack->top;
    stack->top=tmp;
}

void print(stack_t *stack)
{
    node_t *trav=stack->top;
    while(trav!=NULL)
    {
        printf("%d->",trav->data);
        trav=trav->next;
    }
}
