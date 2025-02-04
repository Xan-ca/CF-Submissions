#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(){
    int n;
    cin>>n;
    int result;
    int resp;
    string ans;
    bool back=false;
    for(int i=0;i<n;i++){
        if(back==false){
        cout<<"? "<<ans<<"0"<<endl;
        cout<<flush;
        cin>>resp;
        if(resp ){
          ans+="0";
        }
        else{
          cout<<"? "<<ans<<"1"<<endl; 
          cout<<flush;
          cin>>resp;
          if(resp){
            ans+="1";
          }
          else{
            back=true;
          }
        }
        }if(back==true){
          cout<<"? "<<"0"<<ans<<endl;
        cout<<flush;
        cin>>resp;
        if(resp){
          ans="0"+ans;
        }
        else{
         ans="1"+ans;
        }  
        }
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}