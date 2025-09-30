#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> res;
void toh(int n,int from,int to,int mid){
    if(n==1) {
        res.push_back({from,to});
        return ;
    }
    toh(n-1,from,mid,to);
    res.push_back({from,to});
    toh(n-1,mid,to,from);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    toh(n,1,3,2);
    cout<<res.size()<<endl;
    for(auto it:res){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}