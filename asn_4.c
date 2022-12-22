#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("ENTER DATA(-1 FOR NO node) :");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    else
    {
        newnode->data = x;
        printf("ENTER LEFT CHILD OF %d\n", x);
        newnode->left = create();
        printf("ENTER RIGHT CHILD OF %d\n", x);
        newnode->right = create();
        return newnode;
    }
}

struct node *delete (struct node *root, int data)
{
    struct node *cur = root;
    struct node *parent = NULL;
    struct node *succ = NULL;

    if (cur->left == NULL && cur->right == NULL)
    {
        if (parent->left == cur)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        printf("%d deleted", cur->data);
        free(cur);
        return root;
    }
    if (cur->left != NULL && cur->right == NULL)
    {
        if (parent->left == cur)
        {
            parent->left = cur->left;
        }
        else
        {
            parent->right = cur->left;
        }
        printf("%d deleted", cur->data);
        free(cur);
        return root;
    }
    if (cur->left == NULL && cur->right != NULL)
    {
        if (parent->left == cur)
        {
            parent->left = cur->right;
        }
        else
        {
            parent->right = cur->right;
        }
        printf("%d deleted", cur->data);
        free(cur);
        return root;
    }
    if (cur->left != NULL && cur->right != NULL)
    {
        parent = cur;
        succ = cur->right;
        while (succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        cur->data = succ->data;
        if (parent->left == succ)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        printf("%d deleted", succ->data);
        free(succ);
        return root;
    }
}

int main()
{
    struct node *root;
    root = create();
    delete (root, 20);
    
    return 0;
}