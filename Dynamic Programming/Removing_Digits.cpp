#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int res = 0;
    while(n>0){
        int m = n;
        int mx = 0;
        while(m>0){
            mx = max(mx,m%10);
            m/=10;
        }
        n-=mx;
        res++;
    }
    cout<<res<<endl;
    return 0;
}