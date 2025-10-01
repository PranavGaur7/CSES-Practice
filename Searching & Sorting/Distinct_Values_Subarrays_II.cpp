#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> x(n);
    for(auto &it:x) cin>>it;
    ll i = 0,res=0,ct=0;
    map<ll,ll> mp;
    for(ll j = 0;j<n;j++){
        mp[x[j]]++;
        if(mp[x[j]]==1) ct++;
        while(ct>k){
            if(mp[x[i]]==1) ct--;
            mp[x[i]]--;
            i++;
        }
        res+=(j-i+1);
    }
    cout<<res<<endl;
    return 0;
}