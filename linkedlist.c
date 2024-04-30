#include<stdio.h>
#include<stdlib.h>
typedef struct node_s{

	int data;
	struct node_s * nextptr;

}node_t;

int main()
{
    node_t *head=NULL;
    node_t *ptr=NULL;
    printf("Enter 5 data in a linked list\n");
    for (int i =0;i<5;i++)
    {
        node_t *node=malloc(sizeof(node_t));;
        scanf("%d", &(node->data));
        node->nextptr=NULL;
        if (i==0)
        {
            head=node;
            ptr=node;
        }
        else
        {
            ptr->nextptr=node;
            ptr=ptr->nextptr;
        }
    }
    printf("Linked List Output\n\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->nextptr;
    }
    int M=200;
    int N=6;
    insertAfterN(head, M,N);
    printf("Linked List Insertion Output\n\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->nextptr;
    }
    //circular(head);
    delete_node(head);
    return 0;
}

void insertAfterN(node_t* head, int M, int N) {
	if (head == NULL) return;
if (head->data == N) {
        node_t* tmp = malloc(sizeof(node_t));
        tmp->data = M;
        tmp->nextptr = head->nextptr;
        head->nextptr = tmp;
        head = tmp;
}
insertAfterN(head->nextptr, M, N);
}

void circular(node_t * head)
{
    node_t *traverse=head;
    while(traverse->nextptr!=NULL)
    {
        traverse=traverse->nextptr;
    }
    traverse->nextptr=head;

    int c=0;
    traverse=head;
    while (1)
    {
        if (c==3)
            break;
        else{
            printf("%d->",traverse->data);
            traverse=traverse->nextptr;
        }
        if (traverse==head){
            c++;
        }
    }
 }
 
void delete_node(node_t*head)
{
    node_t *ptr=head;
    node_t *traverse=head->nextptr;
    //Traverse will help go through the link list
    //ptr will point to the node just before the node traverse is pointing to. This will help us yo delete the nodes.
    while (traverse!=NULL)
    {
        // Here I have to check if the value is at the last node or node. If it is at the last node, we have to be carefully handle that situation.
        if (traverse->data==200)//If the data has been found
        {
            if (traverse->nextptr==NULL)//Checking if the node is the last node or not
            {
                ptr->nextptr=NULL;//Removing traverse location since it is the last node.
                free(traverse);
                traverse=NULL;
            }
            else //If data is in other position
            {
                ptr->nextptr=traverse->nextptr;
                //free(traverse);//This command is optional but it is good practice
                //traverse=ptr->nextptr; //when this command is used, dont use break. This command will remove all nodes containing 200
                break;//When this command is used dont use previous command. This command will remove the first node containing 200
            }
        }
        else//If Data not found, we will traverse to the next node
        {
            traverse=traverse->nextptr;
            ptr=ptr->nextptr;
        }
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->nextptr;
    }
}
