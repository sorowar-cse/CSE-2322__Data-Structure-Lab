#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int A[1000], B[1000],C[1000000],N,R,S;

void MergingSort()
{
    int NA=1,NB=1,Ptr=1;
    while(NA<=R && NB<=S)
    {
        if(A[NA]< B[NB])
        {
            C[Ptr]=A[NA];
            Ptr++;
            NA++;
        }
        //Author: Sorowar Mahabub,  C201032
        else
        {
            C[Ptr]=B[NB];
            Ptr++;
            NB++;
        }
    }

    if(NA>R)
    {
        for(int k=0; k<=S-NB; k++)
        {
            C[Ptr+k]=B[NB+k];
        }
    }
    //Author: Sorowar Mahabub,  C201032
    else
    {
        for(int k=0; k<=R-NA; k++)
        {
            C[Ptr+k]=A[NA+k];
        }
    }
}

//Author: Sorowar Mahabub,  C201032
void display()
{   N= R+S;
    cout << "\nMerged Array Elements : ";
    for(int i=1; i<=N; i++)
        cout << C[i] << " ";
    cout << endl;
}

//Author: Sorowar Mahabub,  C201032
int main()
{
    cout << "How Many elements (Array A): ";
    cin>>R;

    cout << "Enter sorted elements: ";
    for(int i=1; i<=R; i++)
        cin>>A[i];


    cout << "How Many elements (Array B): ";
    cin>>S;

    cout<<"Enter sorted elements: ";
    for(int i=1; i<=S; i++)
        cin>>B[i];

    //Author: Sorowar Mahabub,  C201032
    MergingSort();
    display();
    return 0;

}


