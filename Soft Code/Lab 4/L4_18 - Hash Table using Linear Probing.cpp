#include<iostream>
//#include<bits/stdc++.h>
using namespace std;


#define SIZE 10
int H[SIZE+1];

#define m 7
void Insert()
{
    int key,index,n=0;

    cout<<"Enter key element to insert\n";
    cin>>key;

    index = (key%m)+1;

    while(H[index]!= 0)
    {
        if(H[index] == 0)
            break;


        index++;
        n++;
        if(index==SIZE+1)
            index=1;
        if(n==SIZE+1)
            break;
    }

    if(n==SIZE+1)
    {
        cout<<"\nHash Table is full of elements\nNo Place to insert this element\n\n";
    }

    else
        H[index] = key;
}

void Search()
{
    int key,index,n=0;

    cout<<"\nEnter the element you want to search\n";
    cin>>key;

    index = (key%m)+1;

    while(n!= SIZE)
    {
        if(H[index]==key)
        {
            cout<<"Element found at index "<<index<<"\n";
            break;
        }
        else
        {
            if(H[index] == 0)
            {
                cout<<"Element not found in Hash table\n";
                break;
            }
            if(H[index] == -1)
            {
                index++;
            }
            n++;
            index++;
            if(index==SIZE)
                index=0;
        }
    }
    if(n-- == SIZE)
        cout<<"Element not found in Hash table\n";
}
void display()
{
    int i;

    cout<<"Index\tValue\n";

    for(i=1; i<=SIZE; i++)
        printf("%d\t%d\n",i,H[i]);
}

int main()
{
    int choice;

    do
    {
        cout<<"Enter your choice\n";
        cout<<" 1. Insert\n 2. Search\n 3. Display\n 0. Exit\n";
        cin>>choice;

        switch(choice)
        {
        case 1:
            Insert();
            display();
            break;

        case 2:
            Search();
            display();
            break;
        case 3:
            display();
            break;
        default:
            cout<<"Enter correct choice\n";
            break;
        }
    }
    while(choice);

    return 0;
}

// Author: Sorowar Mahabub,  C201032