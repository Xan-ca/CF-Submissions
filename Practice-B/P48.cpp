#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ns;
    cin>>ns;
    while(ns--){
        string s;
        cin>>s;
        if(s.size()!=n){
            cout<<"NO"<<endl;
            continue;
        }
        map<int,char>mp1;
        map<char,int>mp2;
        bool b=true;
        for(int i=0;i<n;i++){
           if(mp1.find(arr[i])!=mp1.end() && mp1[arr[i]]!=s[i]){
            cout<<"NO"<<endl;
            b=false;
            break;
           }
           if(mp2.find(s[i])!=mp2.end() && mp2[s[i]]!=arr[i]){
            cout<<"NO"<<endl;
            b=false;
            break;
           }
           if(mp1.find(arr[i])==mp1.end())mp1[arr[i]]=s[i];
           if(mp2.find(s[i])==mp2.end())mp2[s[i]]=arr[i];
        }
        if(b)cout<<"YES"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}