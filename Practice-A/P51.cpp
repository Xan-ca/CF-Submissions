#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(){
    int xq,yq,n;
    cin>>n>>xq>>yq;
    string s;
    cin>>s;
    int x=0,y=0;
    vector<pair<int,int>pos;
    for(int j=0;j<1000;j++){
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            ++y;
        }
        if(s[i]=='E'){
            ++x;
        }
        if(s[i]=='W'){
            --y;
        }
        if(s[i]=="S"){
            --x;
        }
        if(x==xq && y==yq){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    
    }
    cout<<"NO";
    return 0;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}