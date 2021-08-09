#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bitset<64> b(n);
    cout<<b<<"\n";

    string str=bitset<64>(n).to_string();
    cout<<str<<endl;

    unsigned long k= bitset<64>(str).to_ulong();
    cout<<k<<"\n";

    int z=0b0101;
    cout<<z<<"\n";
    return 0;
}