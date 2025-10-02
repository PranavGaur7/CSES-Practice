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

    vector<pair<int,int>> vec;
    for(int i = 0;i<n;i++) vec.push_back({arr[i],i});

    bool found = 0;
    sort(vec.begin(),vec.end());
    for(ll i = 0;i<n;i++){
        if(i>0 && vec[i].first==vec[i-1].first) continue;
        for(ll j = i+1;j<n;j++){
            if(j>i+1 && vec[j]==vec[j-1]) continue;
            ll sum = x-vec[i].first-vec[j].first;
            ll l=j+1,r=n-1;
            while(l<r){
                if(vec[l].first+vec[r].first==sum){
                    found = 1;
                    cout<<vec[i].second+1<<" "<<vec[j].second+1<<" "<<vec[l].second+1<<" "<<vec[r].second+1<<endl;
                }
                else if(vec[l].first+vec[r].first>sum) r--;
                else l++;

                if(found) break;
            }
            if(found) break;
        }
        if(found) break;
    }
    if(!found) cout<<"IMPOSSIBLE"<<endl;
    return 0;
}