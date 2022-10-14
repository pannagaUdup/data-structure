#include <stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>

struct node{
    int info;
    struct node* llink;
    struct node* rlink;
};
typedef struct node* NODE;
NODE root=NULL;

NODE ins(int data)
{
    NODE temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
     return temp;
}

 void inorder(NODE root)
 {
     if(root==NULL)
        return;
     else{
        inorder(root->llink);
        printf("%d ",root->info);
        inorder(root->rlink);
     }
 }
NODE bst(NODE root,int val)
{
    if(root==NULL)
        return ins(val);
    else if(val>root->info)
      root->rlink=bst(root->rlink,val);
    else
        root->llink=bst(root->llink,val);
    return root;
}
NODE search(NODE root,int key)
{
    if(root==NULL)
        return NULL;
 if(key==root->info)
        printf("%d is found",key);
 else if(key>root->info)
 {
     return search(root->rlink,key);
 }
 else if(key<root->info)
    {
    return search(root->llink,key);
 }

}
int main()
{
    NODE root=NULL;
    root=ins(5);
    bst(root,4);
    bst(root,7);
    bst(root,2);
    bst(root,9);
    bst(root,3);
    bst(root,1);
    inorder(root);
    search(root,1);
}
