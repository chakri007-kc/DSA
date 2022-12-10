#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int w=1;
class Tree{
    public:
        int uid;
        int ma;
        bool isLocked;
        int dec_locked,anc_locked;
        Tree* parent;
        vector<Tree*> links;
        Tree(Tree* p){
            uid=-1;
            ma=w++;
            isLocked=false;
            dec_locked=0;
            anc_locked=0;
            parent=p;
        }
};

// void print(Tree* t){

//     cout<<t->ma<<" : ";
//     for(auto i:t->links){
//         cout<<i->ma<<" ";
//     }
//     cout<<"\n";

//     for(auto i:t->links){
//         print(i);
//     }
// }

// void print(Tree* t){
//     queue<Tree*>q;
//     q.push(t);
//     while(!q.empty()){
//         Tree* temp = q.front();
//         q.pop();
//         cout<<temp->ma<<" : ";
//         for(int i=0;i<temp->links.size();i++){
//             Tree* u = temp->links[i];
//             cout<<u->ma<<" ";
//             q.push(u);
//         }
//         cout<<"\n";
//     }
// }



bool lock(Tree* t,int id){
    if(t->isLocked==true || t->dec_locked>0) return false;
    
    Tree* x = t->parent;
    while(x!=NULL){
        if(x->isLocked) return false;
        x=x->parent;
    }

    Tree* temp = t->parent;
    while(temp!=NULL){
        temp->dec_locked++;
        temp=temp->parent;
    }

    t->isLocked=true;
    t->uid=id;
    return true;
}

bool unlock(Tree* t,int id){
    if(!t->isLocked || t->uid!=id) return false;

    Tree* temp = t->parent;
    while(temp!=NULL){
        temp->dec_locked--;
        temp=temp->parent;
    }

    t->isLocked=false;
    return true;
}

bool check_decendants(Tree* t,int id,vector<Tree*>&v){
    queue<Tree*>q;
    q.push(t);
    while(!q.empty()){
        Tree* temp = q.front();
        if(temp->isLocked==true){
            if(temp->uid!=id) return false;
            v.push_back(temp);
        } 
        q.pop();
        for(auto i:temp->links){
            q.push(i);
        }
    }
}

bool upgrade(Tree* t,int id){
    if(t->isLocked || t->dec_locked==0) return false;

    Tree* x = t->parent;
    while(x!=NULL){
        if(x->isLocked) return false;
        x=x->parent;
    }

    vector<Tree*>v;
    if(check_decendants(t,id,v)){
        for(auto i:v){
            unlock(i,id);
        }
    }
    else return false;

    lock(t,id);
    return true;
}



int main(){
    int n,m,q;
    cin>>n>>m>>q;

    Tree* t = new Tree(NULL);
    string x;
    cin>>x;
    unordered_map<string,Tree*>mp;
    mp[x]=t;
    queue<Tree*>que;
    que.push(t);
    int k=1;

    while(!que.empty()){
        Tree* temp = que.front();
        que.pop();
        while(k<n && temp->links.size()<m){
            string s;
            cin>>s;
            Tree* u = new Tree(temp);
            temp->links.push_back(u);
            que.push(u);
            mp[s]=u;
            k++;
        }
    }

    // print(t);

    for(int i=0;i<q;i++){
        int op,id;
        string name;
        cin>>op>>name>>id;
        bool flag;
        if(op==1){
            flag=lock(mp[name],id);
        }
        else if(op==2){
            flag=unlock(mp[name],id);
        }
        else{
            flag=upgrade(mp[name],id);
        }

        if(flag) cout<<"true\n";
        else cout<<"false\n";
    }
}