//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//BST Demo

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int data;
	struct node_s * leftchild;
	struct node_s * rightchild;
}treenode_t;

treenode_t * createNode(int val);
treenode_t * insert(treenode_t * root, int val);
treenode_t * insertI(treenode_t * root, int val);
treenode_t * insertR(treenode_t * root, int val);
treenode_t * removeNode(treenode_t * root, int val);
treenode_t * inorderSuccessor(treenode_t * node);
treenode_t * search(treenode_t * root, int val);
void inorder(treenode_t * root);
void postorder(treenode_t * root);
void preorder(treenode_t * root);
void destroyTree(treenode_t * root);

int main()
{
	treenode_t * root = NULL;
	
	int flag = 1;
	int choice; //to understand what the user wants to do
	int val; //stores input variable
	
	do{
		printf("************************************************\n");
		printf("What would you like to do?\n");
		printf("1. Insert a new value into the tree.\n");
		printf("2. Delete a value from the tree.\n");
		printf("3. Perform an inorder walk on the tree.\n");
		printf("4. Perform an preorder walk on the tree.\n");
		printf("5. Perform an postorder walk on the tree.\n");
		printf("6. Check to see if a value exist in the tree.\n");
		printf("7. Exit the program.\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		
		
		switch(choice)
		{
			case 1:
				printf("Insertion Selected. What value would you like to enter: ");
				
				scanf("%d", &val);
				
				if(search(root, val) == NULL) //will search to see if the value exists in the tree already
					root = insertR(root, val); //if it doesn't exist in the tree this will add the value to the tree
				else
					printf("That value is already in the binary search tree.\n");
				
				break;
			case 2:
				printf("Deletion Selected. What value would you like to remove: ");
				
				scanf("%d", &val);
				
				if(search(root, val) != NULL) //if the value is not present in the tree; will only delete if the value is present
					root = removeNode(root, val); //deletes value
				else
					printf("That value is not in the binary search tree.\n");
				
				break;
			case 3:
				printf("Inorder walk selected.\n");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("Preorder walk selected.\n");
				preorder(root);
				printf("\n");
				break;
			case 5:
				printf("Postorder walk selected.\n");
				postorder(root);
				printf("\n");
				break;
			case 6:
				printf("Search selected.\n");
				printf("What value would you like to check to see if it exists in the binary search tree?\n");
				
				if(search(root, val) != NULL)
					printf("The value is currently in the binary search tree.\n");
				else
					printf("That value is not in the binary search tree.\n");
				
				break;
			case 7:
				printf("Exit selected.\n");
				flag = 0;
				break;
			default:
				printf("Invalid option selected.\n");
			
		}
		
		printf("************************************************\n");
	}while(flag);
	
	destroyTree(root);
	return 0;
}

treenode_t * createNode(int val)
{
	treenode_t * node = malloc(sizeof(treenode_t)); //initialize a node to be able to store the value
	
	if(node == NULL) //check if malloc was successful or not
	{
		printf("malloc not successful\n");
		return NULL; //return NULL if the allocation failed
	}

	node->data = val; //store the value
	
	node->leftchild = NULL; //we do not know the left child or right child so for now they are NULL
	node->rightchild = NULL;
	
	return node; //return the node
}

treenode_t * insert(treenode_t * root, int val){ //this is a recursive code so it will only stop when the node is NULL
	if(root == NULL)
		return createNode(val);  //first check if the node is NULL and if it is then call createNode to create the node
	
    if(val < root->data){
		root->leftchild = insert(root->leftchild, val); //if the value is less than the root's value then call insert on the left child
	}
	else{
		root->rightchild = insert(root->rightchild, val); //if the value is greater than the root's value then call insert on the right child
	}
	return root; //return the root which is the new value we just inserted
};

treenode_t * insertI(treenode_t * root, int val)
{
	treenode_t **temp = &root;

    while (*temp != NULL) 
	{
        if (val > (*temp)->data)
            temp = &(*temp)->rightchild;
        else
            temp = &(*temp)->leftchild;
    }
	
    *temp = createNode(val);
	
    return root;
}

treenode_t * insertR(treenode_t * root, int val)
{
	if (root == NULL) 
	{
        return createNode(val);
    }
 
    if (val < root->data) 
	{
        root->leftchild = insertR(root->leftchild, val);
    }
    else 
	{
        root->rightchild = insertR(root->rightchild, val);
    }
 
    return root;
}

treenode_t * removeNode(treenode_t * root, int val) //there are 4 conditions to check:
{
	if (root == NULL) //first/base condition: the root is NULL if the value is in the bst or not
	{
		printf("Node doesn't exist.\n");
        return root;
	}
    else if (val < root->data) //if the value is less than the root data
        root->leftchild = removeNode(root->leftchild, val); //the root will point to the left child and will remove the node ???
	else if (val > root->data)
        root->rightchild = removeNode(root->rightchild, val); //???
    else 
	{
		//No child
        if(root->leftchild == NULL && root->rightchild == NULL) //if left and right child are both NULL that means there are no children
		{
			free(root); //perform deletion of the node and frees the memory allocated or gets rid of the memory location allocated earlier
			return NULL; //returns NULL because ???
		}
		//One child
		else if (root->leftchild == NULL) //if you are removing a child node but there is a node in between the left child and parent node, you need a 
		{ //temp node to point to the leftmost child to save that, so you can remove the node in between and connect the leftmost child to the parent node
            treenode_t * temp = root->rightchild;
            free(root);
            return temp;
        } //same thing but for the right child
        else if (root->rightchild == NULL) {
            treenode_t * temp = root->leftchild;
            free(root);
            return temp;
        }
		
		//Two children
        treenode_t * temp = inorderSuccessor(root->rightchild); //first we need to look for the successor and do this by calling the inorderSuccessor function and
		//this sends the right subtree to the function and it will return the right most successor
        root->data = temp->data; //copy the successor node into the temp/root node ???
        root->rightchild = removeNode(root->rightchild, temp->data); //remove the successor node and this node has no children or will have one children depending
		//on if there is a leaf node or not
    }
    return root;
}

treenode_t * inorderSuccessor(treenode_t * node) //the leftmost child of the right tree is the successor
{
    treenode_t * current = node; //create a new node called current which will tell you where you are in the tree
 
    while (current->leftchild != NULL)
        current = current->leftchild; //while the current node has a left child keep moving towards the left until the current left child is NULL, then it'll return
    return current;
	//if you want to print all the nodes add a print statement in the loop, if you want to print just the leftmost node child than put the print statement outside the loop
}

treenode_t * search(treenode_t * root, int val)
{
	if(root == NULL || root->data == val)
		return root;
	else if(root->data < val)
		return search(root->rightchild, val);
	else 
		return search(root->leftchild, val);
}

void inorder(treenode_t * root) //first goes to the left, then right, then right
{
	if(root != NULL)
	{
		inorder(root->leftchild);
		printf("%d\t", root->data); //print data of the group
		inorder(root->rightchild); //go to the right subtree
	}
		
}

void postorder(treenode_t * root) //first goes to the left, then right, then prints the root
{
	if(root != NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d\t", root->data);
	}	
}

void preorder(treenode_t * root) //first prints the root, then goes to the left child, then the right child
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

void destroyTree(treenode_t * root)
{
	//use postorder walk
	if(root != NULL)
	{
		destroyTree(root->leftchild);
		destroyTree(root->rightchild);
		free(root);
	}
}