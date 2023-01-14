#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int tree[201032],N, Size, Item;

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

void Delheap()
{
    int ptr,left,right,last;

    Item=tree[1];
    last=tree[N];
    N=N-1;
    ptr=1;
    left=2;
    right=3;
    while(right<=N || left<=N)
    {
        if(last>=tree[left] && last >=tree[right])
        {
            tree[ptr]=last;
            return;
        }
        if(tree[right]<=tree[left])
        {
            tree[ptr]=tree[left];
            ptr=left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left=2*ptr;
        right=left+1;
    }
    if(left==N && last<tree[left])
    {
        ptr=left;
    }
    tree[ptr]=last;
    return;
}

void heapsort()
{
    int val,j;
    for(j=1; j<N; j++)
    {
        val=tree[j+1];
        Insheap(tree,j, val);
    }
    while(N>1)
    {
        Delheap();
        tree[N+1]=Item;
    }
}
void Display()
{

    for(int i=1; i<=Size; i++)
        cout<<tree[i]<<" ";

}

int main()
{
    cout<<"How many Elements : ";
    cin>>N;
    Size=N;
    for(int i=1; i<=N; i++)
    {
        cin>>tree[i];
    }
    cout<<"Elements before Heapsort:"<<endl;
    Display();

    cout<<endl;
    heapsort();
    cout<<"After Heap sort:"<<endl;
    Display();

    return 0;

}

// Author: Sorowar Mahabub,  C201032
