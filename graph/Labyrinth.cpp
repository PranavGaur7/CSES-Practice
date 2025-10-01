#include<bits/stdc++.h>
using namespace std;

class Data{
    public:
    int row;
    int col;
    Data(int row,int col): row(row), col(col) {}
};

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> mp(n);
    for(auto &it:mp) cin>>it;
    queue<Data> q;
    vector<vector<char>> v(n,vector<char>(m,'.'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mp[i][j]=='A'){
                q.push(Data(i,j));
                v[i][j]='A';
                break;
            }
        }
        if(q.size()==1) break;
    }
    int resx=-1,resy=-1;
    bool found = 0;
    while(!q.empty()){
        Data node = q.front();q.pop();
        int x = node.row;         
        int y = node.col;          
        if(mp[x][y]=='B') {
            resx=x;
            resy=y;
            found=1;
            break;
        }
        for(int i = 0;i<4;i++){
            int r = x+drow[i];
            int c = y+dcol[i];
            char dir = dstr[i];
            if(r>=0 && r<n && c>=0 && c<m && v[r][c]=='.' && mp[r][c]!='#'){
                q.push(Data(r,c));
                v[r][c]=dir;
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