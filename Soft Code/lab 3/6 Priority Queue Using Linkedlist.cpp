//#include<bits/stdc++.h>
#inculde<iostream>
using namespace std;

#define NULL 0

struct node

{

    int priority;

    int info;

    node *link;

};

node *Front = NULL;

void display();


void Insert(int item,int priority)

{

    node *temp,*q;


    temp = new node();

    temp->info = item;

    temp->priority = priority;


    if( Front == NULL || priority < Front->priority )

    {

        temp->link = Front;

        Front = temp;

    }

    else

    {

        q = Front;

        while( q->link != NULL && q->link->priority <= priority )

        {

            q=q->link;

        }

        temp->link = q->link;

        q->link = temp;

    }

    display();

}


void Delete()

{

    node *temp;

    if(Front == NULL)

        cout<<"Queue Underflow\n";

    else

    {

        temp = Front;

        cout<<"Deleted item is "<<temp->info<<endl;

        Front = Front->link;        

    }

}

void display()

{

    node *ptr;

    ptr = Front;

    if(Front == NULL)

        cout<<"\nQueue is empty\n";

    else

    {

        cout<<"\nQueue Elements  :";

        while(ptr != NULL)

        {

            cout<<ptr->info<<"("<<ptr->priority<<")";

            ptr = ptr->link;

        }

    }

}


int main()

{

    int choice,item,priority;

    do

    {

        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Quit\n";


        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)

        {

            case 1:

                cout<<"Input the item value  : ";

                cin>>item;

                cout<<"Enter its priority : ";

                cin>>priority;

                Insert(item,priority);

                break;

            case 2:

                Delete();

                break;

            case 3:

                display();

                break;

            case 4:

            break;

                default :

                cout<<"Wrong choice\n";

        }

    }while(choice!=4);


    return 0;

}

    