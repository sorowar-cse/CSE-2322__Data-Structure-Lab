#include<iostream>
using namespace std;

int main()
{
    int N,f,s,t,i;
    cin>>N;
    f=0;
    s=1;
    for(i=0; i<N; i++)
    {
        cout<<f<<" ";
        t=f+s;
        f=s;
        s=t;
    }
    return 0;
}
