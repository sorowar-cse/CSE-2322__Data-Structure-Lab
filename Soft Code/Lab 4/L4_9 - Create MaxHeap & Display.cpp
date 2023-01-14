#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int tree[201032],N;

void Insheap(int tree[],int N, int item)
{
    int ptr,PAR;

    N=N+1;
    ptr=N;
    while(ptr!=0)
    {
        PAR=float(ptr/2);
        //PAR=floor(ptr/2);
        if(item<=tree[PAR])
        {
            tree[ptr]=item;
            return;
        }
        tree[ptr]=tree[PAR];
        ptr=PAR;
    }
    tree[1]=item;

    return;
}

void Display()
{

    cout<<"Maxheap elements: ";
    for(int i=1; i<=N; i++)
        cout<<tree[i]<<" ";

}

int main()
{
    int element;
    cout<<"How many element? :";
    cin>>N;

    for(int i=1; i<=N; i++)
        cin>>tree[i];

    for(int j=1; j<N; j++)
    {
        Insheap(tree, j, tree[j+1]);
    }
    Display();

    return 0;

}

// Author: Sorowar Mahabub,  C201032
