#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

node *root, *loc, *par, *save, *child;

int insertNode(int Item)
{
    node *p, *newNode, *Back;

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

void Find(int item)
{
    node *ptr;
    if (root==NULL)
    {
        loc = NULL;
        par = NULL;

        return;
    }
    if(item == root->info)
    {
        loc = root;
        par = NULL;

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

    return;
}
void CaseA(node *loc, node *par)  //No children
{
    if(loc->left == NULL && loc->right == NULL)
        child = NULL;
    else if(loc->left!=NULL)
        child = loc->left;
    else
        child = loc->right;

    if(par!=NULL)
    {
        if(loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
    else
        root = child;

    return;

}

void CaseB(node *loc, node *par) // N has two children
{
    node *ptr, *SUC,*PARSUC;
    ptr = loc->right;
    save=loc;

    while(ptr->left!=NULL)
    {
        save=ptr;
        ptr=ptr->left;
    }
    SUC=ptr; //location of inorder successor
    PARSUC=save; //location of parent of inorder successor

    CaseA(SUC, PARSUC);

    if(par!=NULL)
    {
        if(loc= par->left)
            par->left = SUC;
        else
            par->right = SUC;
    }
    else
        root=SUC;

    SUC->left= loc->left;
    SUC->right= loc->right;

    return;

}

void Delete(int item)
{
    Find(item);

    if(loc==NULL)
    {
        cout<<"Item not found";
        return;
    }
    if(loc->right!=NULL && loc->left!=NULL)
    {
        CaseB(loc, par);
    }

    else
    {
        CaseA(loc, par);
    }
    return;

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

void Display()
{
    if(root)
    {
        cout<<"\nTraverse Tree PREorder\n";
        preOrder(root);
    }
    else
        cout<<"\nBST IS NULL\n";
}
int main()
{
    int Num,element,item;
    cout<<"How many elements for BST? " ;
    cin>>Num;
    cout<<"\nEnter elements: ";
    for (int i=0; i<Num; i++)
    {
        cin>>element;
        insertNode(element);
    }
    Display();

    cout<<"\nEnter an element to Delete : ";
    cin>>item;
    Delete(item);

    cout<<"After deleting "<<item<<" node : \n";
    Display();

    return 0;
}

// Author: Sorowar Mahabub,  C201032
