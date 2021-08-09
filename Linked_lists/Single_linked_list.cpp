#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
    public:
        ll data;
        Node* next;
};
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
Node* insert_at_beg(Node* head,ll d)
{
    Node* k = new Node();
    k->data=d;
    // if(head==NULL)
    // {
    //     return k;
    // }
    k->next=head;
    head=k;
    return head;
}

Node* insert_at_end(Node* head,ll d)
{
    Node* z=head;
    Node* k= new Node();
    k->data=d;
    k->next=NULL;
    if(head==NULL) return k;
    else{
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=k;
    }
    return z;
}

Node* insert_at_nth_pos(Node* head,ll d,ll pos)
{
    Node* z=head;
    Node* k = new Node();
    k->data=d;
    k->next=NULL;
   
    if(pos==1)
    {
         if(head==NULL)
        {
            return k;
        }
        else{
            k->next=head;
            head=k;
            return head;
        }
    }
    else{
        for(ll i=0;i<pos-2;i++)
        {
            head=head->next;
        }
        k->next=head->next;
        head->next=k;
    }
    return z;
}

Node* delete_at_nth_pos(Node* head,ll pos)
{
    Node* z=head;
    if(pos==1)
    {
        Node* t=head;
        head=head->next;
        free(t);
        return head;
    }
    else{
        Node* t=head;
        Node* t1=NULL;
        for(ll i=0;i<pos-2;i++)
        {
            t=t->next;
        }
        t1=t->next;
        t->next=t1->next;
        free(t1);
    }
    return z;
}
Node* reverse_linked_list(Node* head)
{
    Node* t=head;
    Node* t1=NULL;
    Node* t2=NULL;
    while(t!=NULL)
    {
        t2=t->next;
        t->next=t1;
        t1=t;
        t=t2;
    }
    return t1;
}
int main()
{
    Node* head=NULL;
    head=insert_at_beg(head,5);
    head=insert_at_beg(head,4);
    head=insert_at_beg(head,3);

    head=insert_at_end(head,1);
    head=insert_at_end(head,2);
    head=insert_at_end(head,3);

    head=insert_at_nth_pos(head,6,5);
    head=insert_at_nth_pos(head,7,1);
    head=insert_at_nth_pos(head,8,7);

    head=delete_at_nth_pos(head,1);
    head=delete_at_nth_pos(head,8);
    print(head);
    
    head=reverse_linked_list(head);
    print(head);
}