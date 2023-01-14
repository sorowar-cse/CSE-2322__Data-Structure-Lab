#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

struct nodeType
{
    int info;
    struct nodeType *left;
    struct nodeType *right;
};


typedef struct nodeType *nodeptr;
nodeptr root;
nodeptr loc,par,save;
//nodeType *root, *loc, *par, *save;
int insertNode(int Item)
{
    nodeptr p, newNode,back;

    p = root;
    back=NULL;

    newNode = (nodeType *) malloc(sizeof(nodeType));
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> info = Item;

    while (p!=NULL)
    {
        back=p;
        if (p->info > Item)
            p = p->left;
        else
            p = p->right;
    }

    if(back == NULL)
        root = newNode;
    else if (back->info > Item)
        back->left  = newNode;
    else back->right  = newNode;

    return 0;
}

void inOrder(nodeptr p)
{
    if(p!=NULL)
    {
        inOrder(p->left);
        printf("%d  ",p->info);
        inOrder(p->right);
    }
}

void preOrder(nodeptr p)
{
    if(p!=NULL)
    {
        printf("%d  ",p->info);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(nodeptr p)
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

    printf("\n\nMain Menu\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Exit\n\n");
    cout<<"4. search"<<endl;
    printf("Enter Choice(1-4): ");
    scanf("%d",&n);
    printf("\n");
    return n;
}
void Search(int item)
{
    nodeType *ptr;
    if (root==NULL)
    {
        loc = NULL;
        par = NULL;
        cout<<"\nTree is Empty ! \n";
        return;
    }
    if(item == root->info)
    {
        loc = root;
        par = NULL;
        cout << endl << item << " is Found  at Root." << endl;
        return;
    }

    if(item<root->info)
    {
        ptr = root->left;
        save=root;
    }
    else
    {
        ptr= root->right;
        save=root;
    }

    while(ptr!=NULL)
    {
        if (item == ptr->info)
        {
            loc=ptr;
            par=save;

            cout << endl << item << " is Found at location: " << loc << "! Search is Successful!\nChild of Parent: " << par->info << '!'<< endl;
            return;
        }
        if(item < ptr->info)
        {
            save=ptr;
            ptr=ptr->left;

        }
        else
        {
            save=ptr;
            ptr=ptr->right;
        }
    }

    loc=NULL;
    par=save;
    if(loc==NULL)
        cout << endl << "Opps, " << item <<  " is not Found! Search Unsuccessful!!" << endl;

    return;
}


void Display()
{
    if(root)
    {
        printf("\nTraverse Tree INorder\n");
        inOrder(root);
        printf("\nTraverse Tree PREorder\n");
        preOrder(root);
        printf("\nTraverse Tree POSTorder\n");
        postOrder(root);
    }
    else printf("\nBST IS NULL\n");
}

int main()
{
    nodeptr p;
    int VAL;

    root = NULL;

    char ch[11];
    int n = 2;

    n = menu();

    do
    {
        if(n==1)
        {
            printf("\nInsert a val :");
            scanf("%d",&VAL);
            insertNode(VAL);
        }
        
        if(n==2)
        {
            Display();
        }
        if(n==3)
        {
            printf("\n");
            break;
        }
        if(n==4)
        {
            cout << "Enter the item to search: ";
            int ok;
            cin >> ok;
            Search(ok);
        }
        if(n>4)
            printf("\nWrong Choice\n");
        n = menu();

    } while(1);
    return 0;
}

// Author: Sorowar Mahabub,  C201032
