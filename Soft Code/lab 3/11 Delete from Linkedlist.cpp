#include<bits/stdc++.h>
using namespace std;
#define NULL 0
struct Node
{
    int Info;
    struct Node *Link;
};
Node *Start, *Prev, *Curr, *Loc, *LocPrev;

void Display ();

//-------------Create
void CREATE()
{
    int N;
    Node *ptr;
    Start = new Node();
    ptr=Start;

    cout<<"How many elements: ";
    cin>>N;

    for(int i=1; i<=N; i++)
    {
        printf("input a number: ");
        cin>>ptr->Info;
        if(i!=N)
        {
            ptr->Link= new Node();
            ptr=ptr->Link;
        }
    }
    ptr->Link=NULL;

    Display();
}
//----------------Find Location
void FindLoc(int Item)
{
    if (Start == NULL)
    {
        Loc=NULL;
        LocPrev= NULL;
        return;
    }
    if(Start->Info == Item)
    {
        Loc=Start;
        LocPrev=NULL;
        return;
    }
    Prev = Start;
    Curr = Start->Link;

    while(Curr!=NULL)
    {
        if(Curr->Info == Item)
        {
            Loc=Curr;
            LocPrev=Prev;
            return;
        }
        Prev = Curr;
        Curr = Curr->Link;
    }

    Loc=NULL;
}

//----------------Delete
void Delete()
{
    if(Loc==NULL)
    {
        cout<<"Item is not in the List"<<endl;
        return;
    }
    if(LocPrev==NULL)
    {
        Start=Start->Link;
    }
    else
    {
        LocPrev->Link=Loc->Link;
    }
    return;
}
//----------------Display
void Display ()
{
    Node *ptr;
    cout<<"\nElements in the Link list are: \n";
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

    cout<<"Enter a number to Delete: ";
    cin>>item;

    FindLoc(item);
    Delete();
    Display();

    return 0;
}

