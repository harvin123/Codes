#include<stdio.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* insert(struct node *root,int val)
{
	int i=0;
	struct node *temp;
	if(root==NULL)
	{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
else if(root->data>val)
{
root->left=insert(root->left,val);
}
else if(root->data<=val)
{
	root->right=insert(root->right,val);
}
}
void add_que(struct node *que[],struct node *root,int *rear)
{
	que[*rear]=root;
	*rear=*rear+1;
}
void level_order(struct node *root,struct node *que[],int *front,int *rear)
{
	add_que(que,root,rear);
	while(1)
	{
	if(root->left!=NULL)
	{
	add_que(que,root->left,rear);
}
   if(root->right!=NULL)
	{
	add_que(que,root->right,rear);
}
//printf("%d ",que[*front]->data);
//*front=*front+1;
//root=que[*front];
if(*front==*rear)
{
	break;
}
}
printf("%d",*rear);
que[*rear]=NULL;
}
int main()
{
	struct node *root=NULL;
	struct node *que[50];
	int a=0,b=0,i=0;
	int *front=&a,*rear=&b;
	root=insert(root,5);
	insert(root,2);
	insert(root,7);
	insert(root,1);
	insert(root,3);
	insert(root,6);
	insert(root,8);
	level_order(root,que,front,rear);
	printf("top down\n");
	while(que[i]!=NULL)
	{
		printf("%d ",que[i]->data);
		i++;
	}
	//printf("%d",*front);
	*front=*front-1;
	printf("\nbottom up\n");
		while(*front!=0)
	{
		printf("%d ",que[*front]->data);
		*front=*front-1;
	}
}
