#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int info;
    struct node *link;      //self referencing of pointer
};
typedef struct node *NODE;    //creating struct node *=NODE
NODE insert_front(int data,NODE first)
{
    NODE temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->info=data;
    temp->link=first;
    return temp;
}
NODE insert_rear(int data,NODE first)
{
    NODE temp;
    NODE temp2=(struct node*)malloc(sizeof(struct node));
    temp=first;
    while(temp->link!=NULL)
        temp=temp->link;
    temp2->info=data;
    temp2->link=NULL;
    temp->link=temp2;
    return first;
}
NODE delete_front(NODE first)
{
    if(first==NULL)
      {
          cout<<"empty node "<<endl;
          return first;
      }
    else
    {
        NODE temp=first;
        temp=temp->link;
        cout<<"item eliminated is "<<first->info<<endl;
        free(first);
        return temp;
    }
}
NODE delete_rear(NODE first)
{
    NODE temp,temp2;
    if(first==NULL)
        cout<<"linked list is empty"<<endl;
      else
     {
       temp=first;
       while(temp->link!=NULL)
       {
           temp2=temp;
           temp=temp->link;
       }
       cout<<"deleted element is "<<temp->info<<endl;
       temp2->link=NULL;
       free(temp);
       return first;
    }

}
void display(NODE first)
{
    NODE temp;
    if(first==NULL)
       {
           cout<<"empty node"<<endl;;
       }
    else{
        temp=first;
        cout<<"contents of linked list"<<endl;
        while(temp!=NULL)
        {
        cout<<temp->info<<endl;
        temp=temp->link;
        }
    }
}
int main()
{
    NODE first=NULL;
        int choice,item;
    while(true)
    {
        cout<<"1.push front 2.push rear 3.delete front 4.delete rear 5.display 6.exit"<<endl;
        cout<<"enter choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"enter item to add"<<endl;
            cin>>item;
            first=insert_front(item,first);           //initialising first to temp
            break;
        case 2:
            cout<<"enter item to add from end"<<endl;
            cin>>item;
            first=insert_rear(item,first);
            break;
        case 3:
            first=delete_front(first);
            break;
        case 4:
            first=delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"invalid choice"<<endl;
        }
    }
    return 0;
}
