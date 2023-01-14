#include<bits/stdc++.h>
using namespace std;
#define N 10
int A[N+1][N+1], Front[N+1], Rear [N+1];

void display();

//-------------------------Insert
void QueueInsert()
{
    int p, ITEM;
    cout<<"Enter the priority Num: ";
    cin>>p;

    if((Front[p] == 1 && Rear[p] == N ) || (Front[p] == Rear[p]+1))
    {
        cout<<"Overflow"<<endl;
        return;
    }

    cout<<"Enter the element to insert in Queue["<<p<<"] : ";
    cin>>ITEM;


    if(Front[p] == 0)
    {
        Front[p]=1;
        Rear[p]=1;
    }
    else if(Rear[p]==N)
    {
        Rear[p]=1;
    }
    else
    {
        Rear[p]=Rear[p]+1;
    }
    A[p][Rear[p]]=ITEM;

    display();

}
//------------------Delete
void QueueDelete()
{
    int p;
    for(int i=1; i<=N; i++)
    {
        if(Front[i]==0)
            continue;
        else
        {
            p=i;
            break;
        }
    }

    if(Front[p]==0)
    {
        cout<<"Underflow"<<endl;
        return;
    }

    cout<<"\nDeleted Item : "<<A[p][Front[p]]<<endl;

    if(Front[p] == Rear[p])
    {
        Front[p]=0;
        Rear[p]=0;
    }
    else if(Front[p] == N)
    {
        Front[p]=1;
    }
    else
        Front[p] = Front[p]+1;

    display();
}
//----------------Display
void display()
{
    int f,r;
    for(int i=1; i<=N; i++)
    {
        if(Front[i]!=0)
        {
            f=Front[i],r=Rear[i];
            if (f == 0)
            {
                cout<<"Queue["<<i<<"] is empty"<<endl;
                return;
            }
            if(f<=r)
            {
                cout<<"\nElements in Queue of Priority "<<i<<" are: ";

                while(f<=r)
                {
                    cout<<A[i][f]<<" ";
                    f++;
                }
            }
            else
            {
                cout<<"\nElements in Queue of Priority "<<i<<" are: ";
                while(f<=N)
                {
                    cout<<A[i][f]<<" ";
                    f++;
                }
                f=1;
                while(f<=r)
                {
                    cout<<A[i][f]<<" ";
                    f++;
                }
            }
        }
    }
    return;
}

int main()
{
    int choice;

    do
    {
        cout<<"\n1)Insert\n2)Delete\n0)Exit : "<<endl<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            QueueInsert();
            break;
        case 2:
            QueueDelete();
            break;
        case 0:
            printf("End of operation\n");
            break;
        }
    }
    while(choice!=0);
    return 0;
}
