//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//AVL Tree Demo

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int data;
	int height; //new component
	struct node_s * leftchild;
	struct node_s * rightchild;
}avltreenode_t;

//old functions from BST with slight or no modifications
avltreenode_t * createNode(int val);
avltreenode_t * insertR(avltreenode_t * root, int val);
avltreenode_t * removeNode(avltreenode_t * root, int val);
avltreenode_t * inorderSuccessor(avltreenode_t * node);
avltreenode_t * search(avltreenode_t * root, int val);
void inorder(avltreenode_t * root);
void postorder(avltreenode_t * root);
void preorder(avltreenode_t * root);
void destroyTree(avltreenode_t * root);
//new AVL Functions
int height(avltreenode_t * n);
int max(int a, int b);
avltreenode_t * rightRotate(avltreenode_t * y);
avltreenode_t * leftRotate(avltreenode_t * y);
int calcBalanceFactor(avltreenode_t * n);


int main()
{
	avltreenode_t * root = NULL;
	
	root = insertR(root, 10);
	root = insertR(root, 20);
	root = insertR(root, 30);
	root = insertR(root, 40);
	root = insertR(root, 50);
	root = insertR(root, 25);
	
	preorder(root);
	printf("\n");
	root = removeNode(root, 40);
	printf("\n");
	preorder(root);
	printf("\n");
	
	destroyTree(root);
	return 0;
}

avltreenode_t * createNode(int val)
{
	avltreenode_t * node = malloc(sizeof(avltreenode_t));
	
	if(node == NULL)
	{
		printf("malloc not successful\n");
		return NULL;
	}

	node->data = val;
	
	node->leftchild = NULL;
	node->rightchild = NULL;
	
	node->height = 1;
	
	return node;
}

avltreenode_t * insertR(avltreenode_t * root, int val)
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
	
	//update balance factor
	
	root->height = 1 + max(height(root->leftchild), height(root->rightchild));
	
	int balance = calcBalanceFactor(root);
	
	//4 cases
	
	if(balance > 1 && val < root->leftchild->data)
		return rightRotate(root);
	
	if(balance < -1 && val > root->rightchild->data)
		return leftRotate(root);
	
	if(balance > 1 && val > root->leftchild->data)
	{
		root->leftchild = leftRotate(root->leftchild);
		return rightRotate(root);
	}
	
	if(balance < -1 && val < root->rightchild->data)
	{
		root->rightchild = rightRotate(root->rightchild);
		return leftRotate(root);
	}
 
    return root;
}

avltreenode_t * removeNode(avltreenode_t * root, int val)
{
	if (root == NULL)
	{
		printf("Node doesn't exist.\n");
        return root;
	}
    else if (val < root->data)
        root->leftchild = removeNode(root->leftchild, val);
	else if (val > root->data)
        root->rightchild = removeNode(root->rightchild, val);
    else 
	{
		//one or no child
        if (root->leftchild == NULL) 
		{
            avltreenode_t * temp = root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild == NULL) 
		{
            avltreenode_t * temp = root->leftchild;
            free(root);
            return temp;
        }
 
        avltreenode_t * temp = inorderSuccessor(root->rightchild);
 
        root->data = temp->data;
 
        root->rightchild = removeNode(root->rightchild, temp->data);
    }
	
	//update balance factor
	
	root->height = 1 + max(height(root->leftchild), height(root->rightchild));
	
	int balance = calcBalanceFactor(root);
	
	// 4 cases
	
	if(balance > 1 && calcBalanceFactor(root->leftchild) >= 0)
		return rightRotate(root);
	
	if(balance > 1 && calcBalanceFactor(root->leftchild) < 0)
	{
		root->leftchild = leftRotate(root->leftchild);
		return rightRotate(root);
	}
	
	if(balance < -1 && calcBalanceFactor(root->rightchild) <= 0)
		return leftRotate(root);
	
	if(balance < -1 && calcBalanceFactor(root->rightchild) > 0)
	{
		root->rightchild = rightRotate(root->rightchild);
		return leftRotate(root);
	}
	
    return root;
}

avltreenode_t * inorderSuccessor(avltreenode_t * node)
{
    avltreenode_t * current = node;
 
    while (current->leftchild != NULL)
        current = current->leftchild;
 
    return current;
}

avltreenode_t * search(avltreenode_t * root, int val)
{
	while(root != NULL)
	{
		if (root->data > val)
			root = root->leftchild;
		else if(root->data < val)
			root = root->rightchild;
		else
			return root;
	}
	
	return NULL;
}

void inorder(avltreenode_t * root)
{
	if(root != NULL)
	{
		inorder(root->leftchild);
		printf("%d\t", root->data);
		inorder(root->rightchild);
	}
		
}

void postorder(avltreenode_t * root)
{
	if(root != NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d\t", root->data);
	}	
}

void preorder(avltreenode_t * root)
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}


//checks which child has a bigger subtree
int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

avltreenode_t * rightRotate(avltreenode_t * y)
{
	avltreenode_t *x = y->leftchild;
	avltreenode_t *t2 = x->rightchild;
	
	x->rightchild = y;
	y->leftchild = t2;
	
	y->height = max(height(y->leftchild), height(y->rightchild)) + 1;
	x->height = max(height(x->leftchild), height(x->rightchild)) + 1;
	
	return x;
}

avltreenode_t * leftRotate(avltreenode_t * x)
{
	avltreenode_t *y = x->rightchild;
	avltreenode_t *t2 = y->leftchild;
	
	y->leftchild = x;
	x->rightchild = t2;
	
	x->height = max(height(x->leftchild), height(x->rightchild)) + 1;
	y->height = max(height(y->leftchild), height(y->rightchild)) + 1;
	
	return y;
}

int calcBalanceFactor(avltreenode_t * n)
{
	if(n == NULL)
		return 0;
	return height(n->leftchild) - height(n->rightchild);
}

int height(avltreenode_t * n)
{
	if(n == NULL)
		return 0;
	
	return n->height;
}

void destroyTree(avltreenode_t * root)
{
	//use postorder walk
	if(root != NULL)
	{
		destroyTree(root->leftchild);
		destroyTree(root->rightchild);
		free(root);
	}
}