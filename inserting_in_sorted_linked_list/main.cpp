//
//  main.cpp
//  inserting_in_sorted_linked_list
//
//  Created by Uby H on 15/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first=NULL,*last=NULL;
void create(int x)
{
        Node *t = new Node;
        t->data=x;
        t->next=NULL;
        if(first==NULL)
        {
            first=last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insert(int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    Node *p,*q;
    q=NULL;
    p=first;
    if(p->data>x)
    {
        t->data=x;
        t->next=p;
        first=t;
    }
    else
    {
        while(p&&p->data<x)
        {
            q=p;
            p=p->next;
        }
        t->data=x;
        t->next=q->next;
        q->next=t;
    }
}
int main()
{
    int n,x;
    cout<<"Enter the number of element to be inserted in the linked list : "<<endl;
    cin>>n;
    cout<<"Enter the elements to be inserted"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        create (x);
    }
    cout<<"The original array is given by : "<<endl;
    display(first);
    cout<<"Enter the element to be inserted in the sorted array : "<<endl;
    cin>>x;
    insert(x);
    cout<<"The updated array is given by : "<<endl;
    display(first);
    return 0;
}
