#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res;
    for(int i=0;i<n;i++){
        if(n%2==1){
          if(i%2==0){
            res+=s[i];
          }else{
            res=s[i]+res;
          }
        }else{
           if(i%2==0){
           res=s[i]+res;
          }else{
            res+=s[i];
          }
        }
    }
    cout<<res;

}