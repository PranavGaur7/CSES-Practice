#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll power(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res*=a;
        b/=2;
        a*=a;
    }
    return res;
}

ll f(ll n){
    if(n<=9) return n;
    ll digCt = 1;
    ll nineCt = 9;
    while(nineCt*digCt<n){
        n-=(nineCt*digCt);
        nineCt*=10;
        digCt++;
    }
    ll num = power(10,digCt-1)+(n-1)/digCt;
    ll digPos = n%digCt;
    if(digPos!=0) num/=(power(10,digCt-digPos));
    return num%10;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    while(n--){
        ll x;
        cin>>x;
        cout<<f(x)<<endl;
    }
    return 0;
}