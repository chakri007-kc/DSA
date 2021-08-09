#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k=n;
    //  bitset<64> b(n);
    string str = bitset<64>(n).to_string();
    int c=1;
    while(n!=0)
    {
        if(n%2==0) c++;
        if(n%2==1) break;
        n=n/2;
    }
    cout<<c<<"\n";

/////////////////(or)/////////////////

   
    // cout<<b<<"\n";

    unsigned long k1= bitset<64>(str).to_ulong();
    cout<<k1<<"\n";
    
    string mask=bitset<64>(1).to_string();
    int z=stoi(str);
    int m=stoi(mask);
    int count=1;
    while(z!=0)
    {
        if(z&m) break;
        z=z>>1;
        count++;
    }
    cout<<count<<"\n";
    // cout<<z<<"\n"<<m<<"\n";
    
    cout<<str<<"\n";
    
//////////////////////////////////////////


    int m1=1;
    int c1=1;
    while(k!=0)
    {
        if(k&m) break;
        k>>=1;
        c1++;
    }
    cout<<c1<<"\n";


}

