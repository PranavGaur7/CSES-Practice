#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> des(n),apa(m);
    for(auto &it:des) cin>>it;
    for(auto &it:apa) cin>>it;
    sort(des.begin(),des.end());
    sort(apa.begin(),apa.end());
    int i = 0,j=0,res=0;
    while(i<n && j<m){
        int mx= des[i]+k,mn=des[i]-k;
        if(apa[j]<=mx && apa[j]>=mn){
            res++;
            i++;
            j++;
        }
        else if(mx<apa[j]) i++;
        else if(mn>apa[j]) j++;
    }
    cout<<res<<endl;
    return 0;
}