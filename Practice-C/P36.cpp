#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   
    ll int n=10000000;
    vector<ll int>prime(n+1,0);
    prime[0]=1;
    prime[1]=1;
    vector<pair<ll,ll>>ep;
    int sn=sqrt(n);
    for(ll int i=2;i<=sn;i++){
        if(prime[i]==0){
            for(ll int j=i*2;j<=n;j+=i){
             if(prime[j]==0)prime[j]=1;
            }
        }
    }
    int d1,d2;
    for(ll int i=4;i<=n;i++){
        ll int j=i/2;
        d1=0;
        d2=0;
        while(true){
            while(prime[j+d1]!=0)d1++;
            while(prime[j-d2]!=0)d2++;
            if(d1==d2){
                ep.push_back({j-d2,j+d1});
                break;
            }
           else if(d1>d2)d2++;
            else d1++;
        }
    }
    int k;
    while(cin>>k){
        bool lock =true;

        if(k%2==1){
            cout<<"2 "<<"3"<<" "<<ep[(k-5)/2-2].first<<" "<<ep[(k-5)/2-2].second; 
        }
        else {
            coutcout<<"2 "<<"2 "<<ep[k/2-2].first<<" "<<ep[k/2-2].second;
           lock=false;
        }
        if(lock){
           cout<<"False";
        }
        cout<<endl;
        k--;
    }
    

}