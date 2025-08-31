#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        if(x>y){
            long long mul = (x-1)*(x-1);
            if(x&1) cout<<(mul)+y<<endl;
            else cout<<(x*x-y+1)<<endl;
        }
        else{
            long long mul = (y-1)*(y-1);
            if(y%2==0) cout<<(mul)+x<<endl;
            else cout<<(y*y-x+1)<<endl;
        }
    }
    return 0;
}