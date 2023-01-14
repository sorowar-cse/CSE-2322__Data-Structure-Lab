#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
};

node *A[1032];

void Insert(int Size)
{
    int num;
    cout<<"Enter the elements : ";
    for(int i=0; i<Size; i++)
    {
        cin>>num;

        node *newNode = new node();
        newNode->data = num;
        newNode->next = 0;


        int mod = num % Size;

        if(A[mod] == 0)
        {
            A[mod] = newNode;
        }

        else
        {

            node *temp = A[mod];
            while(temp->next)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void display(int Size)
{
    int i;

    for(i = 0; i < Size; i++)
    {
        node *temp = A[i];
        cout<<"Array"<<"["<<i<<"]"<<"-->";
        while(temp)
        {
            cout<<temp->data<<" -->";
            temp = temp->next;
        }
        cout<<0<<endl;
    }
}

int main()
{

    int  i,Size;


    cout<<" Enter the size : ";
    cin>>Size;

    A[Size];
    for(i = 0; i < Size; i++)
        A[i] =0;
    
    Insert(Size);
    display(Size);

    return 0;
}

// Author: Sorowar Mahabub,  C201032
