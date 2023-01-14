#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct linked_list
{
    int info;
    struct linked_list *link;
};

typedef struct linked_list node;
int main()
{
    int n,i,item;
    node *start,*ptr;
    start=(node*)malloc(sizeof(node));
    ptr=start;
    printf("How many elements: ");
    scanf("%d",&n);
    printf("Enter the number: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&ptr->info);
        if(i!=n)
        {
            ptr->link=(node*)malloc(sizeof(node));
            ptr=ptr->link;
        }
    }
    ptr->link=NULL;
    printf("\nElements in the Link list are: \n");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->info);
        ptr= ptr->link;
    }
}
