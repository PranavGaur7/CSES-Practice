#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll ct = log(n)/log(5);
    ll x = 1;
    int res = 0;
    for(int i = 1;i<=ct;i++){
        x*=5;
        res+=(n/x);
    }
    cout<<res<<endl;
    return 0;
}