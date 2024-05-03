#include<stdio.h>
#include<stdlib.h>
struct node
 {
  int key;
  struct node *right,*left;
 };
struct node *newnode(int item)
 {
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->key = item;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
 }

void inorder(struct node *node)
 {
  if(node != NULL)
   {
    //for left
    inorder(node->left);
    //for root
    printf("%d, ",node->key);
    //for right
    inorder(node->right);
   }
 }
void preorder(struct node *node)
{
  if(node != NULL)
   {
    //for root
    printf("%d, ",node->key);
    //for left
    preorder(node->left);
    //for right
    preorder(node->right);
   }
}
void postorder(struct node *node)
{
  if(node != NULL)
   {
    //for left
    postorder(node->left);
    //for right
    postorder(node->right);
    //for root
    printf("%d, ",node->key);
   }
}

//insert a node
struct node *insert (struct node *node,int key)
{
  if (node == NULL)
   {
    return newnode(key);
   }
  if (key < node->key)
  {
    node->left = insert(node->left,key);
  }
  else 
  {
    node->right = insert(node->right,key);
  }
  return node;
}

struct node *minvaluenode(struct node *node)
{
  struct node *current = node;
  while (current && current->left != NULL)
  {
    current = current->left;
  }
  return current;
} 

//deleting a node
struct node *deletenode(struct node *root,int key)
{
  if (root == NULL)
   {
    return root;
   }
  if (key < root->key)
  {
    root->left = deletenode(root->left,key);
  }
  else if (key > root->key)
  {
    root->right = deletenode(root->right,key);
  }
  else
  {
    if (root->left == NULL)
    {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minvaluenode(root->right);
    root->key = temp->key;
    root->right = deletenode(root->right,temp->key);
  }
  return root;
}

void main()
 {
  struct node *root = NULL;
  root = insert(root,8);
  root = insert(root,3);
  root = insert(root,1);
  root = insert(root,6);
  root = insert(root,7);
  root = insert(root,10);
  root = insert(root,14);
  root = insert(root,4);
  printf("inorder:\n");
  inorder(root);
  printf("\n");
  printf("preorder:\n");
  preorder(root);
  printf("\n");
  printf("postorder:\n");
  postorder(root);
  printf("\n");
  printf("after deleting 10\n");
  root = deletenode(root,10);
  printf("inorder traversal:\n");
  inorder(root);
  printf("\n");
 }