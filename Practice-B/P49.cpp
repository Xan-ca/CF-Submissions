#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(){
    string s1;
    string s2;
    int j=0;
    bool is=true;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[j] && is){
            j++;
        }
        if(s1[i]=="?" && is){
            s1[i]=s2[j];
            j++;
        }
        if(is==false && s1[i]=="?" ){
            s1[i]=s2[j]
        }
        if(j==s2.size()){
            is==false;
            j=0;
        }
        
    }
    if(!is){
        cout<<"YES"<<endl;
        cout<<s1<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
int main(){
    int t;
    while(t--){
        solve();
    }
}