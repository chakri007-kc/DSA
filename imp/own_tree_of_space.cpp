#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int w=1;
class Tree{
    public:
        bool isLocked;
        int anc_locked,dec_locked;
        int uid;
        int ma;
        Tree* parent;
        vector<Tree*>links;
        // Tree(){
        //     isLocked=false;
        //     anc_locked=0;
        //     dec_locked=0;
        //     uid=-1;
        //     ma=w++;
        //     parent=NULL;
        // }
        Tree(Tree* p){
            isLocked=false;
            anc_locked=0;
            dec_locked=0;
            uid=-1;
            ma=w++;
            parent=p;
        }
};

void print(Tree* t){
    queue<Tree*>q;
    q.push(t);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        for(auto i:temp->links){
            cout<<temp->ma<<" -> "<<i->ma<<" ";
            q.push(i);
        }
    }
}

void change_decendants(Tree* t,int d){
    for(auto i:t->links){
        i->anc_locked+=d;
        change_decendants(i,d);
    }
}

bool lock(Tree* t,int id){
    if(t->isLocked || t->anc_locked!=0 || t->dec_locked!=0) return false;

    Tree* x = t->parent;
    while(x!=NULL){
        x->dec_locked++;
        x=x->parent;
    }

    change_decendants(t,1);
    t->isLocked=true;
    t->uid=id;
    return true; 
}


bool unlock(Tree* t,int id){
    if(!t->isLocked || t->uid!=id) return false;
    Tree* x = t->parent;
    while(x!=NULL){
        x->dec_locked--;
        x=x->parent;
    }
    
    change_decendants(t,-1);
    t->isLocked=false;
    return true;
}

bool check_decendants(Tree* t,int id, vector<Tree*>&v){
    if(t->isLocked){
        if(t->uid!=id) return false;
        v.push_back(t);
    }
    if(t->dec_locked==0) return true; 
    bool x=true;
    for(auto i:t->links){
        x &= check_decendants(i,id,v);
        if(x==false) return false;
    }
    return x;
}

// bool check_decendants(Tree* t,int id,vector<Tree*>&v){
//     queue<Tree*>q;
//     q.push(t);
//     while(!q.empty()){
//         Tree* temp = q.front();
//         if(temp->isLocked){
//             if(temp->uid!=id) return false;
//             v.push_back(temp);
//         }
//         q.pop();
//         for(auto i:temp->links){
//             q.push(i);
//         }
//     }

//     return true;
// }

bool upgrade(Tree* t,int id){
    if(t->isLocked) return false;
    if(t->anc_locked!=0) return false;
    if(t->dec_locked==0) return false;

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
    unordered_map<string, Tree*>mp;

    string d;
    cin>>d;
    cout<<d<<" ";
    int k=1;
    mp[d]=t;
    queue<Tree*>que;
    que.push(t);

    while(!que.empty()){
        Tree* temp = que.front();
        // cout<<temp->ma<<"\n";
        que.pop();
        while(k<n && temp->links.size()<m){
            string s;
            cin>>s;
            Tree* u = new Tree(temp);
            temp->links.push_back(u);
            que.push(u);
            mp[s]=u;
            // cout<<s<<" "<<mp[s]->ma<<"\n";
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