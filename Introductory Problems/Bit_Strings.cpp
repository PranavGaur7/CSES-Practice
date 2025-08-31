#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a = 2;
    ll ans = 1;
    ll mod = 1e9+7;
    while(n>0){
        if(n&1) ans=(ans*a)%mod;
        n/=2;
        a = (a*a)%mod;
    }
    cout<<ans<<endl;
    return 0;
}