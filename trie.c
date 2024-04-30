//Dr. Andrew Steinberg
//COP3502C Computer Science 1
//Trie Demo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trienode_s{
	struct trienode_s * children [26];
	int flag; //1 if the string is in our trie, 0 otherwise
}trienode_t;

trienode_t * createTrieNode();
void insert(trienode_t * root, char * string);
int search(trienode_t * root, char * string);
trienode_t * removeTrieNode(trienode_t * root, char * string, int depth);
int isEmpty(trienode_t * root);
void display(trienode_t* root, char str[], int level);
void destroyTrie(trienode_t * root);

int main()
{
	trienode_t * root = createTrieNode();
	
	char word[20];
	
	insert(root, "pea");
	insert(root, "peach");
	insert(root, "peaches");
	
	display(root,word, 0);
	
	removeTrieNode(root, "pea", 0);
	
	display(root,word, 0);
	
	if(search(root, "peach"))
		printf("peach exists...\n");
	else
		printf("peach does not exists...\n");
	
	destroyTrie(root);

	return 0;
}

trienode_t * createTrieNode()
{
	trienode_t * node = NULL;
	
	node = malloc(sizeof(trienode_t)); //allocate trie node
	
	if(node != NULL)
	{
		node->flag = 0;
		
		for(int x = 0; x < 26; ++x)
			node->children[x] = NULL;
	}
	
	return node;
}

void insert(trienode_t * root, char * string)
{
	int length = strlen(string); //calculate length of string
	
	trienode_t * temp = root; //create temp pointer for root and use that for the traversal
	
	for(int level = 0; level < length; ++level)
	{
		int index = string[level] - 'a'; //detemine index 0-25 by using basic arithemtic between english alphabet
		
		if(temp->children[index] == NULL) //check to see if that index has a valid pointer already
		{
			temp->children[index] = createTrieNode(); //create new one
		}
		
		temp = temp->children[index]; //traverse through child pointer
	}
	
	temp->flag = 1;
}

int search(trienode_t * root, char * string)
{
	int length = strlen(string); //calculate length of string
	
	trienode_t * temp = root;
	
	for(int level = 0; level < length; ++level)
	{
		int index = string[level] - 'a'; //detemine index 0-25 by using basic arithemtic between english alphabet
		
		if(temp->children[index] == NULL) //check to see if that index has a valid pointer already
		{
			return 0; //if this was true, then prefix doesn't exist
		}
		
		temp = temp->children[index]; //traverse through child pointer
	}
	
	return temp->flag; //1 if exist or 0 if not exist
}


//NOTE this function assumes that the prefix already exist. Call the search function first to verify
trienode_t * removeTrieNode(trienode_t * root, char * string, int depth)
{
	if(root == NULL)
		return NULL;
	
	if(depth == strlen(string))
	{
		root->flag = 0;
		
		if(isEmpty(root))
		{
			free(root);
			root = NULL; //DEFENSIVE PROGRAMMING AT ITS FINEST!
		}
		
		return root;
	}
	
	
	int index = string[depth] - 'a';
	
	root->children[index] = removeTrieNode(root->children[index], string, depth + 1);
	
	if(isEmpty(root) && root->flag == 0)
	{
		free(root);
		root = NULL; //DEFENSIVE PROGRAMMING AT ITS FINEST!
	}
	
	return root;
	
}

int isEmpty(trienode_t * root)
{
	for(int x = 0; x < 26; ++x)
		if(root->children[x] != NULL)
			return 0;
	
	return 1;
}


void display(trienode_t* root, char str[], int level)
{
    if(root->flag == 1)
    {
        str[level] = '\0';
        printf("%s\n", str);
    }
	
	
    for(int i = 0; i < 26; i++)
    {
        if(root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

void destroyTrie(trienode_t * root)
{
	for(int i = 0; i < 26; i++)
    {
        if(root->children[i])
        {
            destroyTrie(root->children[i]);
        }
    }
	
	free(root);
}