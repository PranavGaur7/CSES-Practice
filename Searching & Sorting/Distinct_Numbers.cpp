#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> x(n);
    for(auto& it:x) cin>>it;
    sort(x.begin(),x.end());
    int res = 0;
    for(int i = 0;i<n;i++){
        if(i>0 && x[i]==x[i-1]) continue;
        res++;
    }
    cout<<res<<endl;
    return 0;
}