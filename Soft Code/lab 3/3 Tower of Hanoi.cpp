#include<iostream>
using namespace std;


void Tower(int n,char Beg, char Aux,char End)
{
    if(n==1)
    {
        cout<<"Move Disk "<<n<<" from "<<Beg<<" to "<<End<<endl;
        return;
    }
    
    Tower(n-1,Beg,End,Aux);
    cout<<"Move Disk "<<n<<" from "<<Beg<<" to "<<End<<endl;
    Tower(n-1,Aux,Beg,End);
}

int main()
{
    int n;
    cout<<"Enter no. of disks: ";
    cin>>n;
    Tower(n,'A','B','C');
    
    return 0;
}
