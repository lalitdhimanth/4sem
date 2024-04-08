#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};
int getHeight(struct Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->height;
}
struct Node *create(int key)
{
    struct Node *N = (struct Node *)malloc(sizeof(struct Node));
    N->val = key;
    N->left = NULL;
    N->right = NULL;
    N->height = 1;
    return N;
}
int getBalanceFactor(struct Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return (getHeight(N->left) - getHeight(N->right));
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
struct Node *insert(struct Node *N, int key)
{
    if (N == NULL)
    {
        return (create(key));
    }
    if (key > N->val)
    {
        N->right = insert(N->right, key);
    }
    else if (key < N->val)
    {
        N->left = insert(N->left, key);
    }
    else
    {
        printf("YO");
    }
    N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
    int bf = getBalanceFactor(N);
    if (bf > 1 && key < N->left->val)
    {
        return rightRotate(N);
    }
    else if (bf < -1 && key > N->right->val)
    {
        return leftRotate(N);
    }
    else if (bf > 1 && key > N->left->val)
    {
        N->left = leftRotate(N->left);
        return rightRotate(N);
    }
    else if (bf < -1 && key < N->right->val)
    {
        N->right = rightRotate(N->right);
        return leftRotate(N);
    }
    return N;
}
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->val);

        inOrder(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    inOrder(root);
}