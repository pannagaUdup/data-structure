#include <iostream>
#include <cmath>

using namespace std;

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE first;
NODE insf(NODE first,int data)
{
    NODE temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=first;
    return temp;
}
NODE rev(NODE first)
{
    NODE prev=NULL;
    NODE current=first;
    NODE next=NULL;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void display(NODE first)
{
    NODE temp;
    if(first==NULL)
        cout<<"empty list"<<endl;
    else
    {
        temp=first;
        while(temp!=NULL)
        {
         cout<<temp->info<<endl;
         temp=temp->link;
        }
    }
}
int main(){
    NODE first=NULL;
    first=insf(first,6);
    first=insf(first,7);
    first=insf(first,9);

    display(first);
    cout<<"hello"<<endl;
     display(first);
    first=rev(first);
    cout<<"hello"<<endl;
    display(first);
cout<<"hello"<<endl;
    return 0;
    }
