#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll res = INT_MIN,sum =0;
    while(n--){
        ll x;
        cin>>x;
        sum+=x;
        res = max(res,sum);
        if(sum<0) sum=0;
    }
    cout<<res<<endl;
    return 0;
}