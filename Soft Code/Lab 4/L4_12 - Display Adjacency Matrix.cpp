#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

#define Max 32

int adj[ Max ][ Max ];
int n;
int main()
{
    int max_edges, n, i, j, origin, destin;
    char graph_type;

    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter type of graph, directed or undirected (d/u) : ";
    fflush( stdin );
    cin>>graph_type;

    if ( graph_type == 'u' )
        max_edges = n * ( n - 1 ) / 2;
    else
        max_edges = n * ( n - 1 );

    for ( i = 1; i <= max_edges; i++ )
    {
        cout<<"Enter edge "<<i<<" ( 0 0 to quit ) : ";
        cin>>origin>>destin;

        if ( ( origin == 0 ) && ( destin == 0 ) )
            break;

        if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
        {
            cout<<"Invalid edge!\n" ;
            i--;
        }
        else
        {
            adj[ origin ][ destin ] = 1;

            if ( graph_type == 'u' )
                adj[ destin ][ origin ] = 1;
        }
    }

    cout<<"The adjacency matrix is :\n" ;

    for ( i = 1 ; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
            printf( "%4d", adj[ i ][ j ] );

        cout<< "\n" ;
    }
    return 0;
}

// Author: Sorowar Mahabub,  C201032
