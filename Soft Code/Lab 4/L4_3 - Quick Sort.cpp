#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int compareTo(const void* first, const void* second)
{
    int* x = (int*) first;
    int* y = (int*) second;

    if (*x > *y)
    {
        return +1;
    }
    else if (*x < *y)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


// Author: Sorowar Mahabub,  C201032
int main()
{
    int A[201032],N;

    cout<<"How many elements?: ";
    cin>>N;

    cout<<"Enter the array elements: ";
    for(int i=0; i<N; i++)
        cin>>A[i];
    
    qsort(A,N,sizeof(int),compareTo);

    cout << endl << "After sorting: ";
    for (int i=0; i<N; i++)
        cout << A[i] << "  ";

    return 0;
}
