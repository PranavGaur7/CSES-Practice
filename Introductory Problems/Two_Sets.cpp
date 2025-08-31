#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll sum = (1LL*n*(n+1))/2;
    if(sum&1){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<ll> v1,v2;
    ll sm1 = sum/2,sm2=sum/2;
    for(int i = n;i>=1;i--){
        if(sm1>=i){
            sm1-=i;
            v1.push_back(i);
        }
        else if(sm2>=i){
            sm2-=i;
            v2.push_back(i);
        }
    }
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    if(sm1==0 && sm2==0){
        cout<<"YES"<<endl;
        cout<<v1.size()<<endl;
        for(auto it:v1) cout<<it<<" ";
        cout<<endl;
        cout<<v2.size()<<endl;
        for(auto it:v2) cout<<it<<" ";
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}