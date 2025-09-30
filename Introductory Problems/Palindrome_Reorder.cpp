#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();
    map<char,int> mp;
    for(auto it:s) mp[it]++;
    string a="",b="";
    string odd = "";
    for(auto [ch,ct]:mp){
        if(ct&1) {
            if(odd==""){
                while(ct--) odd+=ch;
            }
            else{
                cout<<"NO SOLUTION"<<endl;
                return 0;
            }
        }
        else {
            int x = ct/2;
            while(x--) a+=ch;
            x=ct/2; 
            while(x--) b+=ch;
        }
    }
    reverse(b.begin(),b.end());
    a=a+odd+b;
    cout<<a<<endl;
    return 0;
}