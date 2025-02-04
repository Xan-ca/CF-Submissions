#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        string res;
        int mx=max(s1.size(),s2.size());
        int carry=0,curr1=0,curr2=0;
        for(int i=0;i<=mx;i++){
            if(0==carry && i==mx){
                break;
            }
            if(i<s1.size()){
                curr1=s1[i]-'0';
            }
            else {
                curr1=0;
            }
           if(i<s2.size()){
               curr2=s2[i]-'0';
           }
            else {
                curr2=0;
            }
            //cout<<curr1<<" "<<curr2<<endl;
            res+=((curr1+curr2+carry)%10)+'0';
            carry=(curr1+curr2+carry)/10;
            //cout<<carry<<endl;
        }
        bool key=true;
        for(int i=0;i<res.size();i++){
            if(key&& res[i]=='0'){
                continue;
            }else{
                cout<<res[i];
                key=false;
            }
        }
        cout<<endl;
    }
   return 0;
}