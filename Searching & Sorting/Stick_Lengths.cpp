#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll check(vector<ll>& arr,ll x){
    ll res = 0;
    for(auto it:arr) res+=abs(it-x);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &it:arr) {
        cin>>it;
    }
    sort(arr.begin(),arr.end());
    cout << check(arr, arr[n/2]);
    return 0;
}