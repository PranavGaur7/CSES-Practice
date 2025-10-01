#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> mp(n);
    while(m--){
        ll st,ed,d;
        cin>>st>>ed>>d;
        mp[st-1].push_back({ed-1,d});
    } 
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    vector<ll> dist(n,LLONG_MAX);
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        auto node = pq.top();pq.pop();
        ll d = node.first;
        ll nod = node.second;
        if(d > dist[nod]) continue;
        for(auto it:mp[nod]){
            ll nxt = it.first;
            ll temp = d+it.second;
            if(temp<dist[nxt]){
                dist[nxt]=temp;
                pq.push({temp,nxt});
            }
        }
    }
    for(auto it:dist) cout<<it<<" ";
    return 0;
}