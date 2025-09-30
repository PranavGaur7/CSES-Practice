#include<bits/stdc++.h>
using namespace std;

set<string> res;

void f(int ind,int n,string& s){
    if(ind==n-1){
        res.insert(s);
        return;
    }
    for(int i = ind;i<n;i++){
        swap(s[ind],s[i]);
        f(ind+1,n,s);
        swap(s[ind],s[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    f(0,s.size(),s);
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it<<endl;
    return 0;
}