#include <bits/stdc++.h>
using namespace std;
/**
int f(int ind, int total_price, vector<int> &price, vector<int> &page)
{
    if (ind == 0)
    {
        if (price[0] <= total_price)
            return page[0];
        return 0;
    }
    int nt = f(ind - 1, total_price, price, page);
    int t = 0;
    if (total_price >= price[ind])
        t = page[ind] + f(ind - 1, total_price - price[ind], price, page);
    return max(t, nt);
} 
**/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, max_price;
    cin >> n >> max_price;
    vector<int> price(n), page(n);
    for (auto &it : price)
        cin >> it;
    for (auto &it : page)
        cin >> it;


    vector<vector<int>> dp(n, vector<int>(max_price + 1, 0));

    for (int total_price = 0; total_price <= max_price; total_price++)
        dp[0][total_price] = ((price[0] <= total_price) ? page[0] : 0);

    for (int ind = 1; ind < n; ind++)
    {
        for (int total_price = 0; total_price <= max_price; total_price++)
        {
            int nt = dp[ind - 1][total_price];
            int t = 0;
            if (total_price >= price[ind])
                t = page[ind] + dp[ind - 1][total_price - price[ind]];
            dp[ind][total_price] = max(t, nt);
        }
    }
    cout << dp[n - 1][max_price];
    return 0;
}