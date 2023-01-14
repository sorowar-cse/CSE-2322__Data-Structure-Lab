#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
 };

node *root;

int insertNode(int Item)
{
    node *p , *newNode, *Back;

    p = root;
    Back=NULL;

    newNode = new node();
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> info = Item;

    while (p!=NULL)
    {
        Back=p;
        if (p->info > Item)
            p = p->left;
        else
            p = p->right;
    }

    if(Back == NULL)
        root = newNode;
    else if (Back->info > Item)
        Back->left  = newNode;
    else Back->right  = newNode;

    return 0;
}

void inOrder(node *p)
{
     if(p!=NULL)
     {
       inOrder(p->left);
       printf("%d  ",p->info);
       inOrder(p->right);
     }
}

void preOrder(node *p)
{
     if(p!=NULL)
     {
       printf("%d  ",p->info);
       preOrder(p->left);
       preOrder(p->right);
     }
}

void postOrder(node *p)
{
     if(p!=NULL)
     {
       postOrder(p->left);
       postOrder(p->right);
       printf("%d  ",p->info);
     }
}

int menu()
{
    int n;

    cout<<"\n\nMain Menu\n";
    cout<<"1. Insert\n";
    cout<<"2. Display\n";
    cout<<"3. Exit\n\n";
    cout<<"Enter Choice(1-3): ";
    cin>>n;
    cout<<"\n";
    return n;
}

void Display()
{
    if(root)
    {
        cout<<"\nTraverse Tree INorder\n";
        inOrder(root);
        cout<<"\nTraverse Tree PREorder\n";
        preOrder(root);
        cout<<"\nTraverse Tree POSTorder\n";
        postOrder(root);
    }
    else
        cout<<"\nBST IS NULL\n";
}

int main()
{
    node p;
    int VAL,n;

    n = menu();

    do
    {
        if(n==1)
        {
            cout<<"\nInsert a val :";
            cin>>VAL;
            insertNode(VAL);
         }
        if(n==2)
        {
            Display();
        }
        if(n==3)
        {
            cout<<"\n";
            break;
        }
        if(n>3)
            cout<<"\nWrong Choice\n";
        n = menu();

    } while(1);
    return 0;
}

// Author: Sorowar Mahabub,  C201032
