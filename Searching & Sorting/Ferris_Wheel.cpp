#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,max_weight;
    cin>>n>>max_weight;
    vector<int> weight(n);
    for(auto &it:weight) cin>>it;
    sort(weight.begin(),weight.end());
    int l = 0,r=n-1;
    int res = 0;
    while(l<r){
        if(weight[l]+weight[r]>max_weight){
            res++;
            r--;
        }
        else{
            res++;
            l++;
            r--;
        }
    }
    if(l==r) res++;
    cout<<res<<endl;
    return 0;
}