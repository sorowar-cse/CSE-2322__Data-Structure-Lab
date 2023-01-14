#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
Node* head = NULL;

void Insert(int newdata)
{
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode ;
    head = newnode;
}
void display()
{
    struct Node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
}
int main()
{
    int item,N;
    cout<<"How many Elements: ";
    cin>>N;
    cout<<"Enter elements: "<<endl;
    for (int i=1; i<=N; i++)
    {
        cin>>item;
        Insert(item);
    }
    cout<<"The doubly linked list is: ";
    display();
    return 0;
}

