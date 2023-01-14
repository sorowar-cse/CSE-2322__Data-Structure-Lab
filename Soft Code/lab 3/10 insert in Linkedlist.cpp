#include<bits/stdc++.h>
using namespace std;
#define NULL 0
struct Node
{
    int Info;
    struct Node *Link;
};

Node *Start, *Curr, *Prev, *Loc, *New;

//---------Function Prototypes
void Display ();
void FindLoc(int Item);
void InsertLoc(int Item);

//------------Create List
void CREATE()
{
    int item,num,N,i;
    Node *Location;

    cout<<"How Many Numbers :";
    cin>>N;
    i=1;

    cout<<"Enter the elements: ";

    while(i<=N)
    {
        cin>>num;

        FindLoc(num);
        InsertLoc(num);
        i++;

    }

    Display();
}
//-------------Find Location
void FindLoc(int Item)
{
    if (Start == NULL)
    {
        Loc = NULL;
        return ;
    }
    if(Item < Start->Info)
    {
        Loc = NULL;
        return ;
    }
    Prev = Start;
    Curr = Start->Link;

    while(Curr!=NULL)
    {
        if(Item < Curr->Info)
        {
            Loc = Prev;
            return ;
        }
        Prev = Curr;
        Curr = Curr->Link;
    }
    Loc = Prev;

    return ;

}

//--------------------Insert
void InsertLoc(int Item)
{
    New = new Node();
    New->Info = Item;

    if(Loc == NULL)
    {
        New->Link= Start;
        Start = New;
    }
    else
    {
        New->Link = Loc->Link;
        Loc->Link = New;
    }
}

//--------------------Display
void Display ()
{
    Node *ptr;
    cout<<"\nElements in the Link list are(sorted): \n";
    ptr=Start;
    while(ptr!=NULL)
    {
        cout<<ptr->Info<<" ";
        ptr= ptr->Link;
    }
    cout<<endl;

}
int main()
{
    int item;

    CREATE();

    cout<<"\n\nEnter a number to Insert: ";
    cin>>item;

    FindLoc(item);
    InsertLoc(item);

    Display();

    return 0;
}
