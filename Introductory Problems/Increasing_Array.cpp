#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long res = 0;
    long long prev = -1;
    while(n--){
        long long x;
        cin>>x;
        if(prev!=-1 && prev>x) {
            res+=prev-x;
        }
        else prev=x;
    }
    cout<<res<<endl;
    return 0;
}