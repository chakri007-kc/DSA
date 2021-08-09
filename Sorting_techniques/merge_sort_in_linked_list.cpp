#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node{
    public:
        ll data;
        Node* next;     
};

Node* merge(Node* first,Node* second){
    Node* k=NULL;
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data <= second->data)
    {
        k=first;
        k->next=merge(first->next,second);
    }
    else{
        k=second;
        k->next=merge(first,second->next);
    }
    return k;
}

void middle(Node* current, Node** first,Node** second){
    Node* slow=current;
    Node* fast=current->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *first=current;
    *second=slow->next;
    slow->next=NULL;
    
}
void merge_sort(Node** head){
    Node* current=*head;
    Node* first=NULL;
    Node* second=NULL;
    if(current==NULL || current->next==NULL) return;
    middle(current,&first,&second);
    merge_sort(&first);
    merge_sort(&second);
    *head=merge(first,second);
}

Node* insert(Node* head,ll d)
{
    Node* k =new Node();
    k->data=d;
    k->next=head;
    head=k;
    return head;
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    Node* head=NULL;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll k;
        cin>>k;
        head=insert(head,k);
    }
    merge_sort(&head);
    print(head);
}