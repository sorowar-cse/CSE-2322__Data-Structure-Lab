#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

#define Max 32

int adj[ Max ][ Max ];
int P[ Max ][ Max ] ;
int n;


int main()
{
    int max_edges, n, i, j, origin, destin;
    char graph_type;

    printf( "Enter number of nodes : " );
    scanf( "%d", &n );
    printf( "Enter type of graph, directed or undirected (d/u) : " );
    fflush( stdin );
    getchar();
    scanf( "%c", &graph_type );

    if ( graph_type == 'u' )
        max_edges = n * ( n - 1 ) / 2;
    else
        max_edges = n * ( n - 1 );

    for ( i = 1; i <= max_edges; i++ )
    {
        printf( "Enter edge %d( 0 0 to quit ) : ", i );
        scanf( "%d %d", &origin, &destin );

        if ( ( origin == 0 ) && ( destin == 0 ) )
            break;

        if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
        {
            printf( "Invalid edge!\n" );
            i--;
        }
        else
        {
            adj[ origin ][ destin ] = 1;

            if ( graph_type == 'u' )
                adj[ destin ][ origin ] = 1;
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(adj[i][j]==0)
            {
                P[i][j]=0;
            }
            else
                P[i][j]=1;
        }
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                P[i][j]= P[i][j]|| (P[i][k] && P[k][j]);
            }
        }
    }

    printf( "The adjacency matrix is :\n" );

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
            printf( "%4d", adj[ i ][ j ] );

        printf( "\n" );
    }


    printf( "The Path matrix is :\n" );

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
            printf( "%4d", P[ i ][ j ] );

        printf( "\n" );
    }


    return 0;
}

// Author: Sorowar Mahabub,  C201032