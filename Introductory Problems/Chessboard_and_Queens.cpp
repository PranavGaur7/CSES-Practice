#include<bits/stdc++.h>
using namespace std;
vector<bool> tdiaBuf(16,0),bdiaBuf(16,0),rowBuf(8,0);

bool check(int r,int c){
    return !rowBuf[r] && !tdiaBuf[7+c-r] && !bdiaBuf[r+c]; 
}
int res;
void nQueen(int col,vector<string>& mat){
    if(col==8) {
        res++;
        return;
    }
    for(int row = 0;row<8;row++){
        if(check(row,col) && mat[row][col]!='*'){
            rowBuf[row]=1;
            tdiaBuf[7+col-row]=1;
            bdiaBuf[row+col]=1;
            mat[row][col]='Q';
            nQueen(col+1,mat);
            rowBuf[row]=0;
            tdiaBuf[7+col-row]=0;
            bdiaBuf[row+col]=0;
            mat[row][col]='.';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> mat(8);
    for(auto &it:mat) cin>>it;
    res=0;
    nQueen(0,mat);
    cout<<res<<endl;
    return 0;
}