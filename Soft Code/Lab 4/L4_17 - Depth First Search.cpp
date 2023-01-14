#include<iostream>
//#include<bits/stdc++.h>
using namespace std;


int A[100][100], s[100], visited[100],n,i,j,top=0;

void DFS(int v)
{
    for(i=1; i<=n; i++)
    {
        if(A[v][i] && !visited[i])
        {
            s[++top]=i;
        }
    }

    if(top!=0)
    {
        visited[s[top]]=1;
        DFS(s[top--]);
    }
}


int main()
{
    int v;

    cout<<" Enter the number of nodes : ";
    cin>>n;
    cout<<" Enter the adjacency matrix : ";

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>A[i][j];
        }
    }

    cout<<" Enter the starting node : ";
    cin>>v;

    for(i=1; i<=n; i++)
    {
        s[i]=0;
        visited[i]=0;
    }

    DFS(v);

    cout<<" The reachable nodes are : ";

    for(i=1; i<=n; i++)
    {
        if(visited[i]!=0)
        {
            cout<<endl<<" The node  "<<i<<" is reachable " ;
        }
        else
        {
            cout<<endl<<" The node  "<<i<<" is not reachable " ;
        }

    }
    return 0;
}


// Author: Sorowar Mahabub,  C201032