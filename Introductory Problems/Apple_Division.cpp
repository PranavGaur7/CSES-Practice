#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(int ind, ll sum1, ll sum2, vector<ll> &p)
{
    if (ind < 0)
        return abs(sum1 - sum2);
    ll t1 = f(ind - 1, sum1 + p[ind], sum2, p);
    ll t2 = f(ind - 1, sum1, sum2 + p[ind], p);
    return min(t1, t2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> p(n);
    for (auto &it : p)
    {
        cin >> it;
    }
    cout << f(n - 1, 0, 0, p) << endl;
    return 0;
}
