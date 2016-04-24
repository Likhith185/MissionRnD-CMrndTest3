/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node1
{
	struct node  *t;
	struct node1 *next;
};
void push(struct node1 **s, struct node *k)
{
	struct node1 *tmp = (struct node1 *) malloc(sizeof(struct node1));
	tmp->t = k;
	tmp->next = *s;
	*s = tmp;
}
struct node *pop(struct node1 **s)
{
	struct  node *t;
	struct node1 *st;
	st = *s;
	(*s) = (*s)->next;
	t = st->t;
	free(st);
	return t;
}
int isEmpty(struct node1 *s)
{
	if (s == NULL)
		return 1;
return 0;
}
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void merge_two_bst(struct node *root1, struct node *root2){
	struct node1 *s1 = NULL; 
	struct node  *current1 = root1;
	struct node1 *s2 = NULL;
	struct node  *current2 = root2;
	if (root1 == NULL)
	{
		inorder(root2);
		return;
	}
	if (root2 == NULL)
	{
		inorder(root1);
		return;
	}
while (current1 != NULL || !isEmpty(s1) ||
		current2 != NULL || !isEmpty(s2))
	{
		if (current1 != NULL || current2 != NULL)
		{
			if (current1 != NULL)
			{
				push(&s1, current1);
				current1 = current1->left;
			}
			if (current2 != NULL)
			{
				push(&s2, current2);
				current2 = current2->left;
			}

		}
		else
		{
			if (isEmpty(s1))
			{
				while (!isEmpty(s2))
				{
					current2 = pop(&s2);
					current2->left = NULL;
					inorder(current2);
				}
				return;
			}
			if (isEmpty(s2))
			{
				while (!isEmpty(s1))
				{
					current1 = pop(&s1);
					current1->left = NULL;
					inorder(current1);
				}
				return;
			}
			current1 = pop(&s1);
			current2 = pop(&s2);
			if (current1->data < current2->data)
			{
				printf("%d ", current1->data);
				current1 = current1->right;
				push(&s2, current2);
				current2 = NULL;
			}
			else
			{
				printf("%d ", current2->data);
				current2 = current2->right;
				push(&s1, current1);
				current1 = NULL;
			}
		}
	}
}