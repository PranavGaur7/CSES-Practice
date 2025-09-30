#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int N = 1; N <= n; N++)
    {
        int res = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (N >= i)
                res = (res + (dp[N - i]) % mod) % mod;
        }
        dp[N] = res;
    }
    cout << dp[n];
    return 0;
}
