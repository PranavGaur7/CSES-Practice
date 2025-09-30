#include<bits/stdc++.h>
using namespace std;

vector<string> f(int n){
    if(n==1){
        return {"0","1"};
    }
    vector<string> vec = f(n-1);
    vector<string> res;
    int m = vec.size();
    for(int i = 0;i<m;i++){
        res.push_back("0"+vec[i]);
    }
    for(int i = 0;i<m;i++){
        res.push_back("1"+vec[m-i-1]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> res = f(n);
    for(auto it:res){
        cout<<it<<endl;
    }
    return 0;
}