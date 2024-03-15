#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} n;
n *p = NULL;
n *nodecreate(int data)
{
    n *no = (n *)malloc(sizeof(n));
    no->data = data;
    no->left = NULL;
    no->right = NULL;
    return no;
}
void preorder(n *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        // recursive- a function which calls itself.
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(n *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
        // recursive- a function which calls itself.
    }
}
void inorder(n *root)
{
    if (root != NULL)
    {
        // recursive- a function which calls itself.
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int isBST(n *root)
{
    static n *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = NULL;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
// recursive
n *Rsearch(n *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return Rsearch(root->left, key);
    }
    else
    {
        return Rsearch(root->right, key);
    }
}

// Iterative
n *Isearch(n *root, int key)
{
    while (root != NULL)
    {
        if (root == NULL || root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insert(n *root, int key)
{
    n *prev = NULL;
    n *current = root;  // Create a separate pointer to traverse the tree

    while (current != NULL)
    {
        prev = current;
        if (key == current->data)
        {
            printf("\nCannot insert %d, already exists in BST.", key);
            return;
        }
        else if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    n *new = nodecreate(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

n *inOP(n *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
n *delete(n *root, int val)
{
    n *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root->left = delete (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            n *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            n *temp = root->left;
            free(root);
            return temp;
        }
        ipre = inOP(root);
        root->data = ipre->data;
        root->left = delete (root->left, ipre->data);
    }
    return root;
}

int main()
{
  printf("\n1.Create\n2.Insert\n3.Delete\n4.Iterative search\n5.Recursive search\n6.Display\n7.Inorder\n8.Preorder\n9.Postorder\n10.Exit");
    while (1)
    {
        int ch;
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            // n *p = NULL;
            int val;
            printf("Enter the value to create: ");
            scanf("%d", &val);
            if (p == NULL)
            {
                p = nodecreate(val);
            }
            else if (val < p->data)
            {
                p->left = nodecreate(val);
            }
            else
            {
                p->right = nodecreate(val);
            }
            break;
        }
        case 2:
        {
            int val;
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            insert(p, val);
            break;
        }
        case 3:
        {
            int val;
            printf("\nEnter the value to delete: ");
            scanf("%d", &val);
            delete (p, val);
            break;
        }
        case 4:
        {
            int k;
            printf("\nEnter key value to search: ");
            scanf("%d", &k);
            n *c = Isearch(p, k);
            if (c != NULL)
            {
                printf("\nFound: %d", c->data);
            }
            else
            {
                printf("\nElement not found");
            }
            break;
        }
        case 5:
        {
            int k;
            printf("\nEnter key value to search: ");
            scanf("%d", &k);
            n *c = Rsearch(p, k);
            if (c != NULL)
            {
                printf("\nFound: %d", c->data);
            }
            else
            {
                printf("\nElement not found");
            }
            break;
        }
        case 6:
        {
            printf("\n");
            inorder(p);
            break;
        }
        case 7:
        {
            printf("\nInorder: ");
            inorder(p);
            break;
        }
        case 8:
        {
            printf("\nPreorder: ");
            preorder(p);
            break;
        }
        case 9:
        {
            printf("\nPostorder: ");
            postorder(p);
            break;
        }
        case 10:
        {
            printf("\nExiting....");
            exit(0);
        }
        default :
        {
            printf("Invalid choice.");
        }
        }
    }


return 0;
}
