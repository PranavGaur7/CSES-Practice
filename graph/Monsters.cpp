#include<bits/stdc++.h>
using namespace std;

vector<int> drow{1,0,-1,0};
vector<int> dcol{0,-1,0,1};
vector<char> dstr{'D','L','U','R'};

string res;

void backtrack(int x,int y,vector<vector<char>>& steps){
    if(steps[x][y]=='A') return;
    char ch = steps[x][y];
    res+=ch;
    if(ch=='L') backtrack(x,y+1,steps);
    else if(ch=='R') backtrack(x,y-1,steps);
    else if(ch=='U') backtrack(x+1,y,steps);
    else if(ch=='D') backtrack(x-1,y,steps);
}

vector<vector<int>> mostorFind(vector<string> mp,int n,int m,queue<pair<pair<int,int>,int>>& qA){
    vector<vector<int>> mostersSteps(n,vector<int>(m,1e9));
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mp[i][j]=='M') {
                q.push({{i,j},0});
                // cout<<i<<" "<<j<<endl;
                mostersSteps[i][j]=0;
            };
            if(mp[i][j]=='A') qA.push({{i,j},0});
        }
    }
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        // cout<<x<<" "<<y<<" "<<mostersSteps[x][y]<<endl;
        q.pop();
        for(int i = 0;i<4;i++){
            int r = x+drow[i];
            int c = y+dcol[i];
            if(r>=0 && r<n && c>=0 && c<m && mostersSteps[r][c]==1e9 && mp[r][c]=='.'){
                mostersSteps[r][c]=d+1;
                q.push({{r,c},d+1});
            }
        }
    }
    return mostersSteps;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> mp(n);
    for(auto &it:mp) cin>>it;

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> mostorSteps = mostorFind(mp,n,m,q);
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<mostorSteps[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<char>> v(n,vector<char>(m,'.'));
    v[q.front().first.first][q.front().first.second] = 'A';
    int resx=-1,resy=-1;
    bool found = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(x==n-1 || y==m-1 || x==0 || y==0){
            found = 1;
            resx=x;
            resy=y;
            break;
        }
        for(int i = 0;i<4;i++){
            int r = x+drow[i];
            int c = y+dcol[i];
            char dir = dstr[i];
            if(r>=0 && r<n && c>=0 && c<m && v[r][c]=='.' && mp[r][c]=='.' && mostorSteps[r][c]>d+1){
                v[r][c]=dir;
                q.push({{r,c},d+1});
            }
        }
    }
    if(!found) 
        cout<<"NO"<<endl;
    else{
        backtrack(resx,resy,v);
        reverse(res.begin(),res.end());
        cout<<"YES"<<endl<<res.size()<<endl<<res<<endl;
    }
    return 0;
}