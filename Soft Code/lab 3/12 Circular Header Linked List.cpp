#include<bits/stdc++.h>
using namespace std;
#define NULL 0
struct node
{
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;
node *newNode;

void Insert(int data)
{
    newNode = new node();
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    newNode->data = data;
}

void display()
{
    node *curr = head;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        cout<<"Elements of the Circular linked list: \n";
        do
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        while(curr != head);
        cout<<endl;
    }
}

int main()
{
    int item,n;
    cout<<"How Many Elements: ";
    cin>>n;

    cout<<"Enter the elements: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cin>>item;
        Insert(item);
    }
    display();
    return 0;
}
