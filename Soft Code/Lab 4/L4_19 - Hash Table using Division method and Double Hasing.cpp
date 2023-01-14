#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int table[12],SIZE;
#define m 7
#define SIZE 10

/*
Double hashing can be done using :
(hash1(key) + i * hash2(key)) % TABLE_SIZE

Here hash1() and hash2() are hash functions
and TABLE_SIZE is size of hash table.
(We repeat by increasing i when collision occurs)


First hash function is typically
    hash1(key) = key % TABLE_SIZE

A popular second hash function is :
    hash2(key) = PRIME – (key % PRIME)
where PRIME is a prime smaller
                than the TABLE_SIZE.
*/

void display();
void Insert()
{
    int key,H1,H2,H,i=0,c=0;

    cout<<"Enter key element to insert\n";
    cin>>key;

    H1= (key%SIZE);
    cout<<"h1 "<<H1;
    H2= m-(key%m);
    cout<<" H2 "<<H2;

    while(i<SIZE)
    {
        H=((H1+ i*H2)%SIZE )+1 ;

        cout<<"H "<<H<<endl;

        if(table[H]==0)
        {
            table[H]=key;
            //c++;
            break;
        }
        else
        {
            i++;
        }
    }
    if(i==SIZE)
        cout<<"Hash table was full of elements\nNo Place to insert this element\n\n";

    display();

}


void Search()
{
    int element,H1,H2,H,i=0;

    cout<<"Enter element you want to search\n";
    cin>>element;

    H1= element%SIZE;
    H2= m-(element%m);

    while(1)
    {
        H=((H1+ i*H2)%SIZE)+1;

        if(table[H]==0)
        {
            cout<<"Element not found in the table"<<endl;
            break;
        }

        if(table[H]==element)
        {
            cout<<"Element found at index : "<<H<<endl;
            break;
        }
        else
        {
            i++;
        }
    }

}

void display()
{
    int i;

    printf("Index\tValue\n");

    for(i=1; i<=SIZE; i++)
        printf("%d\t%d\n",i,table[i]);
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
            break;

        case 2:
            Search();
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