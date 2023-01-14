#include <iostream>
using namespace std;

int Queue[3];

int Front = -1, rear = -1, n=3;
void Insert(int a)
{
    if ((Front == 0 && rear == n-1) || (Front == rear+1))
    {
        cout<<"Queue Overflow "<<endl;
        return;
    }
    if (Front == -1)
    {
        Front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }
    Queue[rear] = a ;
}
void Delete()
{
    if (Front == -1)
    {
        cout<<"Queue Underflow"<<endl;
        return ;
    }
    cout<<"Element deleted from queue is : "<<Queue[Front]<<endl;
    if (Front == rear)
    {
        Front = -1;
        rear = -1;
    }
    else
    {
        if (Front == n - 1)
        {
            Front = 0;
        }
        else
        {
            Front = Front + 1;
        }

    }
}
void display()
{
    int f = Front, r = rear;
    if (Front == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements are :"<<endl;
    if (f <= r)
    {
        while (f <= r)
        {
            cout<<Queue[f]<<" ";
            f++;
        }
    }
    else
    {
        while (f <= n - 1)
        {
            cout<<Queue[f]<<" ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout<<Queue[f]<<" ";
            f++;
        }
    }
    cout<<endl;
}
int main()
{
    int ch, a;
    cout<<"1)Insert"<<endl;
    cout<<"2)Delete"<<endl;
    cout<<"3)Display"<<endl;
    cout<<"4)Exit"<<endl;
    do
    {
        cout<<"Enter choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Input for insertion: "<<endl;
            cin>>a;
            Insert(a);
            break;
        case 2:
            Delete();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Exit\n";
            break;
        default:
            cout<<"Incorrect!\n";
        }
    }
    while(ch != 4);
    return 0;
}