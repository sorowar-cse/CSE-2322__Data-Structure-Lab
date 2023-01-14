//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int i,fact=1,n;
    cin>>n;
    for(i=1; i<=n; i++)
        fact=fact*i;

    cout<<fact<<endl;
    return 0;
}
