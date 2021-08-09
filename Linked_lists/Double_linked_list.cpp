#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
    public:
        ll data;
        Node* prev;
        Node* next;
};
Node* insert_at_beg(Node* head,ll d)
{
    Node* k=new Node();
    if(head==NULL)
    {
        k->next=k->prev=NULL;
        k->data=d;
        return k;
    }
    k->data=d;
    k->next=head;
    k->prev=NULL;
    head->prev=k;
    head=k;
    return head;
}

Node* insert_at_end(Node* head,ll d)
{
    Node* z=head;
    Node* k=new Node();
    if(head==NULL)
    {
        k->data=d;
        k->next=k->prev=NULL;
        return k;
    }
    Node* t=head;
    
    while(t->next!=NULL)
    {
        t=t->next;
    }
    k->data=d;
    k->prev=t;
    t->next=k;
    k->next=NULL;
    return z;
}

Node* insert_at_nth_pos(Node* head,ll d,ll pos)
{
    Node* z=head;
    Node* k= new Node();
    k->data=d;
    if(pos==1)
    {
        if(head==NULL)
        {
            k->next=NULL;
            k->prev=NULL;
            return k;
        }
        k->prev=NULL;
        k->next=head;
        head->prev=k;
        head=k;
        return head;
    }
    for(int i=0;i<pos-2;i++)
    {
        head=head->next;
    }
    k->next=head->next;
    head->next->prev=k;
    k->prev=head;
    head->next=k;
    return z;
}

Node* delete_at_nth_pos(Node* head,ll pos)
{

    Node* z = head;
    Node* t= head;
    if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        free(t);
        return head;
    }
    
    for(ll i=0;i<pos-2;i++)
    {
        t=t->next;
    }
    Node* t1 = t->next;
    if(t1->next==NULL) //to delete the last postion
    {
        t->next==NULL;
        free(t1);
    }
    else
    {
        t->next=t1->next;
        t1->next->prev=t;
        free(t1);
    }
    return z;
}

Node* print(Node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}

Node* print_back(Node* head)
{
    while (head->next!=NULL)
    {
        // cout<<head->data<<" ";
        head=head->next;
    }
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->prev;
    }   
}
int main()
{
    Node* head=NULL;
    head=insert_at_beg(head,5);
    head=insert_at_beg(head,4);
    head=insert_at_beg(head,3);
    head=insert_at_beg(head,10);

   

    head=insert_at_end(head,1);
    head=insert_at_end(head,2);
    head=insert_at_end(head,3);   

    head=insert_at_nth_pos(head,6,5);
    head=insert_at_nth_pos(head,7,1);
    head=insert_at_nth_pos(head,8,7);

    print(head);
    cout<<"\n";
    
    head=delete_at_nth_pos(head,1);
    head=delete_at_nth_pos(head,10); 
    

    // head=reverse_linked_list(head);
    print(head);
    cout<<"\n";
    print_back(head);
}
