#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    unordered_map<int,int>mp;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        mp[t]=i;
    }
    cin>>m;
    int q[m];
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        q[i]=t;
    }
    
    long long int v=0,p=0;
    for(int i=0;i<m;i++){
        if(mp.find(q[i])!=mp.end()){
        v+=mp[q[i]]+1;
        p+=n-mp[q[i]];
        }else{
            v+=n;
            p+=n;
        }
    }
    cout<<v<<" "<<p;
}