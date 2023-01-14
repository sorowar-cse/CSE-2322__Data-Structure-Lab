#include <iostream>
using namespace std;

int ackf(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if((m!= 0) && (n == 0))
    {
        return ackf(m - 1, 1);
    }
    else if((m != 0) && (n!=0))
    {
        return ackf(m - 1, ackf(m, n - 1));
    }
}


int main()
{
    int m,n,A;
    cin>>m>>n;
    A = ackf(m,n);
    cout << A << endl;
    return 0;
}
