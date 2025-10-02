#include<bits/stdc++.h>
using namespace std;
#define LOG 31
int dp[LOG][(int)1e6];

void Precompute(vector<int>& tele,int n){
    for(int i =0;i<n;i++) dp[0][i]=tele[i];

    for(int i = 1;i<LOG;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int query(int node,int dist){
    for(int i = LOG-1;i>=0;i--){
        if(dist&(1<<i)){
            node = dp[i][node];
        }
    }
    return node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> tele(n);
    for(auto &it:tele){
        cin>>it;
        it--;
    }
    // memset(dp,sizeof(dp),-1);
    Precompute(tele,n);
    while(q--){
        int x,k;
        cin>>x>>k;
        cout<<query(x-1,k)+1<<endl;
    }
    return 0;
}