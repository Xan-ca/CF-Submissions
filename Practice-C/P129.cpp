#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
    lli k,x,n;
    cin>>k>>x>>n;
    lli y=0,s=0;
    for(lli i=1;i<=x;i++){
    	lli minbet=0;
    	
    	minbet=floor(double(y)/(k-1))+1;
    	if(minbet>n-y){
    		break;
    	}else{
    		s++;
    		y+=minbet;
    	}
      
    }
    //cout<<s<<endl;
    if(s<x){
    	cout<<"no"<<endl;
    }else if((n-y)*k<=n){
    	cout<<"no"<<endl;
    }else{
    	cout<<"yes"<<endl;
    }
    return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}