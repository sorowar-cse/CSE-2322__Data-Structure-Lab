#include<iostream>
//#include<bits/stdc++.h>
using namespace std;


#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);

int Queue[MAX], Front = -1, Rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void BF_Traversal()
{
    int v;
    for(v=0; v<n; v++)
        state[v] = initial;
    cout<<"Enter Start Vertex for BFS: \n";
    cin>>v;
    BFS(v);
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        cout<<v;
        state[v] = visited;
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    cout<<endl;
}

void insert_queue(int vertex)
{
    if(Rear == MAX-1)
        cout<<"Queue Overflow\n";
    else
    {
        if(Front == -1)
            Front = 0;
        Rear = Rear+1;
        Queue[Rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(Front == -1 || Front > Rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if(Front == -1 || Front > Rear)
    {
        cout<<"Queue Underflow\n";
        exit(1);
    }
    delete_item = Queue[Front];
    Front = Front+1;
    return delete_item;
}

void create_graph()
{
    int count,max_edge,origin,destin;

    cout<<"Enter number of vertices : ";
    cin>>n;
    max_edge = n*(n-1);

    for(count=1; count<=max_edge; count++)
    {
        cout<<"Enter edge "<<count<<"( -1 -1 to quit ) : ";
        cin>>origin>>destin;

        if((origin == -1) && (destin == -1))
            break;

        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            cout<<"Invalid edge!\n";
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

int main()
{
    create_graph();
    BF_Traversal();
    return 0;
}

// Author: Sorowar Mahabub,  C201032
