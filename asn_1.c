#include <stdio.h>
#include <stdlib.h>
struct BST
{
    struct BST *lchild;
    int data;
    struct BST *rchild;
}*root = NULL;
typedef struct 
{
    int top;
    struct BST *q[100];
}queue;

void init(queue *q)
{
    q->top=-1;
}
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
void enqueue(queue *l, struct BST *address)
{
    l->top++;
    l->q[l->top]=address;
}
struct BST * dequeue (queue *l)
{
    struct BST *o= l->q[0];
    for(int i=0;i<l->top;i++)
    {
        l->q[i]=l->q[i+1];
    }
    l->top--;
    return o;
}
int isEmpty(queue q)
{
    if(q.top!=-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void level_order(struct BST *root)
{
    queue q;
    init(&q);
    printf("%d\t",root->data);
    enqueue(&q, root);
    struct BST *p;
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if(p->lchild)
        {
            printf("%d\t",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d\t",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int main()
{
    create(50);
    create(60);
    create(40);
    create(42);
    create(55);
    create(10);
    create(70);
    printf("\n");
    level_order(root);
    return 0;
}