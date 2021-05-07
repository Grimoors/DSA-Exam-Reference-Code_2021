#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
 int data,ht;
 struct node *left, *right;
};
int max(int a,int b)
{
 if(a>b)
  return a;
 else
  return b;
}

int height(struct node *root)
{
 if(root == NULL)
    return -1;
 else
    return (max(height(root->left),height(root->right))+1); 
}

int bf(struct node *root)
{
 return abs(height(root->left)-height(root->right));

}

struct node * LL(struct node *x) /* rotate right*/
{
 struct node * y = x->left;
 x->left=y->right;
 y->right=x;
 x->ht=height(x);
 y->ht=height(y);
 return y;
}


struct node *RR(struct node *x)
{
 struct node *y=x->right;
 x->right=y->left;
 y->left=x;
 x->ht=height(x);
 y->ht=height(y);
 return y;
}
struct node *LR(struct node *x)
{
 x->left=RR(x->left);
 x=LL(x);
 return x;
}


struct node *RL(struct node *x)
{
 x->right=LL(x->right);
 x=RR(x);
 return x;
}


struct node *insert(struct node *root, int val)
{
 if(root == NULL)
 {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->ht=0;
  newnode->left = NULL;
  newnode->right = NULL;
  root=newnode;
  return root;
 }
 else if(val < root->data)
 {
  root->left=insert(root->left,val);
  if(bf(root)== 2)
  {
   if(val < root->left->data) /* newnode inserted to left of root->left*/
    return LL(root);
   else
    return LR(root);
  }
 }
 else
    {
     root->right = insert(root->right,val);
  if(bf(root)== 2)
  {
   if(val > root->right->data) /* newnode inserted to right of root->right*/
    return RR(root);
   else
    return RL(root);
  }
    }
    root->ht=height(root);
 return root;
}


void inorder(struct node * root)
{
 if(root != NULL)
 {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
struct node * findMin(struct node * root)
{
   if(root == NULL)
      return NULL;
   else if(root->left == NULL)
      return root;
   else
      return findMin(root->left);
}
struct node * delete(struct node *root, int val)
{
   struct node *c;
   if(root == NULL)
   {
      printf("deleted element not found");
      return root;
   }
   else if( val < root->data)
      root->left=delete(root->left,val);
   else if( val > root->data)
      root->right=delete(root->right,val);
   else
   {
      if(root->left == NULL && root->right == NULL)
         return NULL;
      else if(root->right != NULL && root->left == NULL) /*if only right child exists*/
         return root->right;
      else if(root->left != NULL && root->right == NULL)  /* if only left child exists*/
         return root->left;
      else
      {
         c=findMin(root->right); /*find the minimum element in right subtree*/
         root->data=c->data;           /* copy the minimum element value into the root */
         root->right=delete(root->right,c->data);  /*delete the duplicate element.*/
         return root;
      }
      root->ht = height(root);
      if (bf(root) >= 2 && root->left && root->left->left)
        return LL(root);
 
      else if (bf(root) >= 2 && root->left && root->left->right)
        root=LR(root);
     
      else if (bf(root) >= 2 && root->right && root->right->right)
        return RR(root);
 
      if (bf(root) >= 2 && root->right && root->right->left)
        root=RL(root);
              
   }
}

main()
{
 int i,n,val,opt;
 struct node *root=NULL;
 while(1)
 {
  printf("\nmenu\n");
  printf("1.insert\n2.display\n3.delete\n4.exit\n");
  printf("enter ur option\n");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1: printf("enter number of elements\n");
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
            printf("enter an element\n");
            scanf("%d",&val);
            root=insert(root,val);
           }
           break;
   case 2: inorder(root);
           break;
   case 3:
           printf("enter the value to be deleted\n");
           scanf("%d",&val);
           root=delete(root,val);
           break;
   case 4:
           exit(0);
     }
  }
}