#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int Array[201032],N;

void InsertionSort()
{
    int ptr,k,temp;

    Array[0]= -201032; //will be Infinity

    for(int k=2 ; k<=N; k++)
    {
        temp=Array[k];
        ptr=k-1;
        while(temp<Array[ptr])
        {
            Array[ptr+1]=Array[ptr];
            ptr--;
        }
        Array[ptr+1]=temp;
    }
}
// Author: Sorowar Mahabub, C201032

void DISPLAY()
{
    cout << endl;
    for(int i=1; i<=N; i++)
        cout<<Array[i]<<" ";
    cout << endl;
}

int main()
{
    cout<<"How many Elements: ";
    cin>>N;
    
    cout<<"Enter Elements: ";
    for(int i=1; i<=N; i++)
        cin>>Array[i];
        
    InsertionSort();
    DISPLAY();
    return 0;
}
