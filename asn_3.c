#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
} *root = NULL;
void create(int v)
{
    struct tree *t = root;
    struct tree *p, *prev;
    if (t == NULL)
    {
        p = malloc(sizeof(struct tree));
        p->data = v;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        prev = t;
        if (v == t->data)
        {
            return;
        }
        else if (v < t->data)
        {
            t = t->lchild;
        }
        else if (v > t->data)
        {
            t = t->rchild;
        }
    }
    p = malloc(sizeof(struct tree));
    p->data = v;
    p->lchild = p->rchild = NULL;
    if (v < prev->data)
    {
        prev->lchild = p;
    }
    else if (v > prev->data)
    {
        prev->rchild = p;
    }
}
void inorder(struct tree *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d\t", p->data);
        inorder(p->rchild);
    }
}
void preorder(struct tree *p)
{
    if (p)
    {
        printf("%d\t", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void swap(struct tree *p)
{
    struct tree *temp=p;
    if (p != NULL)
    {
        swap(temp->lchild);
        swap(temp->rchild);
        temp = p->lchild;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}
int main()
{
    int n;
    while(1)
    {
        printf("Enter Data? ");
        scanf("%d",&n);
        if(n==-1)
        break;
        create(n);
    }    
    preorder(root);
    printf("\n");
    swap(root);
    preorder(root);

    return 0;
};