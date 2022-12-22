#include <stdio.h>
#include <stdlib.h>
struct BST
{
    struct BST *lchild;
    int data;
    struct BST *rchild;
}*root = NULL;

void create(int key)
{
    struct BST *t = root;
    struct BST *p, *r;
    if (root == NULL)
    {
        p = malloc(sizeof(struct BST));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (t->data == key)
            return;
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    p = malloc(sizeof(struct BST));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (p->data < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}
void preorder(struct BST *t)
{
    if (t)
    {
        printf("%d\t", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
int complete_check(struct BST *t)
{
    if (t)
    {
        if((t->lchild!=NULL)&&(t->rchild==NULL))
        {
            // printf("\nNOT COMPLETE TREE");
            return 0;
        }
        if((t->lchild==NULL)&&(t->rchild!=NULL))
        {
            // printf("\nNOT COMPLETE TREE");
            return 0;
        }
        complete_check(t->lchild);
        complete_check(t->rchild);
    }
    else
    {
        return 1;
    }
}
int main()
{
    create(10);
    create(20);
    create(7);
    create(31);
    create(19);
    create(5);
    create(8);
    preorder(root);
    int r= complete_check(root);
    if(r==1)
    {
        printf("\nComplete Tree\n");
    }
    else
    {
        printf("\nIncomplete Tree\n");
    }
    return 0;
}