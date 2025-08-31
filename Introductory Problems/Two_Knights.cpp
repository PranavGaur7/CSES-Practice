#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        ll tot = (1LL*(i*i)*(i*i-1))/2;
        ll fight = 1LL*4*(i-1)*(i-2);
        cout<<tot-fight<<endl;
    }
    return 0;
}