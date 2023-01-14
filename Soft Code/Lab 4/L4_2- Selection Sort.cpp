//#include <bits/stdc++.h>

#include<iostream>
using namespace std;


void SelectionSort(int *array, int size)
{
    int i, j, imin;
    for(i = 0; i<size-1; i++)
    {
        imin = i;
        for(j = i+1; j<size; j++)
            if(array[j] < array[imin])
                imin = j;

        int temp;
        temp = array[i];
        array[i] = array[imin];
        array[imin]= temp;

    }
}


int main()
{
    int n;
    cout << "Enter How many elements: ";
    cin >> n;
    int arr[n+32];
    cout << "Enter your elements: ";
    for(int i= 0; i<n; i++)
        cin >> arr[i];

    //Author: Sorowar Mahabub,  C201032

    cout << endl;
    cout << "Array is Sorted & sorted elements are: ";
    SelectionSort(arr, n);


    for(int i= 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}