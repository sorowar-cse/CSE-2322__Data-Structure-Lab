#include<iostream>
using namespace std;
int factorial(int n)
{
    int fact=1;
    if(n==0)
    {
        return fact;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int main()
{
    int n,value;
    cin>>n;
    value=factorial(n);
    cout<<value;
    return 0;
}
