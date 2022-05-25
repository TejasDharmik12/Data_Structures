#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *CreateBST(struct node *, int);
void Inorder(struct node *);
void Preorder(struct node *);
void Postorder(struct node *);
int main()
{
    struct node *root = NULL;
    int choice, item, n, i;
    printf("\n                   TRAVERSALS IN TREE\n");
    do
    {
        printf("\n---CHOOSE OPTION--");
        printf("\n1. Create tree");
        printf("\n2. Inorder");
        printf("\n3. Preorder");
        printf("\n4. Postorder");
        printf("\n5. Exit\n");
        printf("\nEnter Option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            printf("\nEnter no. of Nodes: \n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("Enter data for node %d : ", i);
                scanf("%d", &item);
                root = CreateBST(root, item);
            }
            printf("\nTree created\n");
            break;
        case 2:
            printf("\nInorder Traversal\n");
            Inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal\n");
            Preorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal\n");
            Postorder(root);
            break;
        case 5:
            printf("\n      --------Ended--------   \n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
struct node *CreateBST(struct node *root, int item)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = CreateBST(root->left, item);
        else if (item > root->data)
            root->right = CreateBST(root->right, item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");
        return (root);
    }
}
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}
void Preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(struct node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ", root->data);
    }
}