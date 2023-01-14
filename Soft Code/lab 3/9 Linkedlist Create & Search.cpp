//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct linked_list
{
    int num;
    struct linked_list *next;
};


typedef struct linked_list node;

int main()
{
    int n,i,item;
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    ptr=start;

    printf("How many elements: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        printf("input a number: ");
        scanf("%d",&ptr->num);
        if(i!=n)
        {
            ptr->next=(node *)malloc(sizeof(node));
            ptr=ptr->next;
        }
    }


    ptr->next=NULL;
    int count= 0;
    printf("\nElements in the Link list are: \n");
    ptr=start;
    while(ptr!=NULL)
    {

        printf("%d ",ptr->num);
        ptr= ptr->next;
    }

    ptr= start;

    cout << endl << "Enter The Searching Item : ";
    cin >> item;

    int loc= 0;
    while(ptr!=NULL)
    {

        count++;

        if(item==ptr->num)
        {
            loc= count;
            break;
        }

        ptr= ptr->next;
    }

    if(loc==0)
        cout << "Item is not found here!" << endl;
    else
        cout << loc << " is the position of the searching Item " << item << endl;

    return 0;
}

