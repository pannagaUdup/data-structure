#include <iostream>
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
NODE insr(NODE first,int data)
{
    NODE temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    NODE cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=NULL;
    return first;
}
NODE inspos(NODE first,int data,int pos)
{
    NODE temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    else if(pos==1)
    {
        temp->link=first;
        return temp;
    }
    else{
        NODE cur=first;
        NODE prev=NULL;
        while(pos!=1)
        {
            prev=cur;
            cur=cur->link;
            pos--;
        }
        temp->link=cur;
        prev->link=temp;
        return first;
    }
}

NODE delf(NODE first)
{
    NODE temp;
    if(first==NULL)
        cout<<"empty list"<<endl;
    else{
        temp=first;
        first=first->link;
        cout<<"deleated item is "<<temp->info<<endl;
        temp->link=NULL;
        free(temp);
    }return first;
}
NODE delr(NODE first)
{
    NODE temp;
    NODE prev;
    if(first==NULL)
        cout<<"empty list"<<endl;
    else{
        temp=first;
        while(temp->link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        cout<<"deleated item is "<<temp->info<<endl;
        prev->link=NULL;
        free(temp);
    }return first;
}
NODE delpos(NODE first,int pos)
{
    NODE prev;
    NODE cur=first;
    if(first==NULL)
        cout<<"empty list"<<endl;
        else if(pos==1)
        {
            first=first->link;
            cur->link=NULL;
            free(cur);
        }
    else{
       while(pos!=1)
       {
           prev=cur;
           cur=cur->link;
           pos--;
       }
       prev->link=cur->link;
       free(cur);
       cur=NULL;
    }return first;
}
void display(NODE first)
{
    if(first==NULL)
        cout<<"empty list"<<endl;
    else{
        NODE temp=first;
        cout<<"elements are "<<endl;
        while(temp!=NULL)
        {
            cout<<temp->info<<endl;
            temp=temp->link;
        }
    }
}
NODE rev(NODE first)
{
    NODE cur=first;
    NODE prev=NULL;
    NODE next=cur->link;
    if(first==NULL)
        cout<<"empty list"<<endl;
    else{
        while(cur!=NULL)
        {
            next=cur->link;
            cur->link=prev;
            prev=cur;
            cur=next;
        }
    }return prev;
}
    int main()
{
    int choice,data,pos;
    NODE first=NULL;
    while(1)
    {
        cout<<"1.insert front 2. insert rear 3.del front 4.del rear 5.display 6.reverse 7.exit 8.inspos 9.delpos"<<endl;
         cout<<"insert choice"<<endl;
         cin>>choice;
         switch(choice)
         {
         case 1:cout<<"enter item to add"<<endl;
         cin>>data;
         first=insf(first,data);
         break;
         case 2:cout<<"enter item to add"<<endl;
         cin>>data;
         first=insr(first,data);
         break;
         case 3:
            first=delf(first);
            break;
            case 4:
            first=delr(first);
            break;
         case 5:
            display(first);
            break;
         case 6:
            first=rev(first);
            break;
         case 7:
            exit(0);
         case 8:
             cout<<"enter data to add"<<endl;
             cin>>data;
             cout<<"enter position to add data"<<endl;
             cin>>pos;
            first=inspos(first,data,pos);
            break;
            case 9:
             cout<<"enter position to delete data"<<endl;
             cin>>pos;
            first=delpos(first,pos);
            break;
         default:
            cout<<"invalid choice"<<endl;
         }
    }
   return 0;
}
