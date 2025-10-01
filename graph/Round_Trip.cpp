#include<bits/stdc++.h>
using namespace std;

vector<int> res;
bool dfs(int node,int parent,vector<int>& v,vector<vector<int>>& mp){
    v[node]=1;
    res.push_back(node);
    for(auto it:mp[node]){
        if(v[it]==0) {
            // cout<<node<<" "<<it<<endl;
            if(dfs(it,node,v,mp)) return 1;
        }
        else if(it!=parent){
            // cout<<node<<" "<<it<<endl;
            res.push_back(it);
            return 1;
        }
    }
    res.pop_back();
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        mp[x-1].push_back(y-1);
        mp[y-1].push_back(x-1);
    }
    vector<int> v(n,0);
    bool x=0;
    for(int i = 0;i<n;i++){
        if(!v[i]){
            x = dfs(i,-1,v,mp);
        }
        if(x) break;
    }
    if(!x) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> ans;
        int pivot = res.back();
        ans.push_back(pivot+1);
        for(int i = res.size()-2;i>=0;i--){
            ans.push_back(res[i]+1);
            if(res[i]==pivot) break;
        }
        cout<<ans.size()<<endl;
        for(auto it:ans) cout<<it<<" ";
    }
    return 0;
}