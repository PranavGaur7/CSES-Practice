#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(auto &it:arr) cin>>it;
    map<ll,ll> mp;
    ll res=0,sum=0;
    mp[0]=1;
    for(auto it:arr){
        sum+=it;
        // cout<<sum<<" "<<sum-x<<endl;
        if(mp.find(sum-x)!=mp.end()) res+=mp[sum-x];
        mp[sum]++;
    }
    cout<<res<<endl;
    return 0;
}