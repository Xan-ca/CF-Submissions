#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int on, int om, int n,int m,int c){
    if(m<=7||n<=7)return 0;
    //if(m==8||n==8)return 1;
if(c==0){
    return solve(on,om,n-1,m-1,1);
}else{
    if(on==n && om==m)return min(n-7,m-7)+solve(on,om,n-2,m-2,c);
    
    else return min(on-7,m-7)+min(om-7,n-7)+solve(on,om,n-2,m-2,c);
}
}
int main(){
    int n,m,c;
    while(cin>>n>>m>>c){
       cout<< solve(n,m,n,m,c)<<endl;
    }
}