#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mincost(int curr,int k,int removedsum,vector<int>&a,vector<int>&b){
   
if(curr>=size(a))return 0;
int t1=0,t2=0;
if(k<size(b)){
 t1+=mincost(curr, k+1,removedsum,a,b);
 t1+=0;
}
int remov=0;
int addc=0;
for(int i=curr;i<size(a);i++){
    if(k>0 && k-1<size(b) && b[k-1]>=a[i]-removedsum){
        addc++;
        remov=a[i];
    }
}
if(addc==0)return 1e7;
removedsum=remov;
t2+=mincost(curr+addc,k,removedsum,a,b);
t2+=b.size()-k;
return min(t1,t2);
}
void solve(){
   int n;
   int m;
   cin>>n>>m;
   vector<int>a;
   vector<int>b;
   int temp;
   for(int i=0;i<n;i++){
    
     cin>>temp;
     a.push_back(temp);
   }
   for(int i=0;i<m;i++){
  
     cin>>temp;
     b.push_back(temp);
   }
   for(int i=1;i<n;i++){
     a[i]+=a[i-1];
   }
   int k=1;
   int removedsum=0;
   int curr=0;
   cout<<mincost(curr,k,removedsum,a,b)<<endl; 
}
int main(){
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
}