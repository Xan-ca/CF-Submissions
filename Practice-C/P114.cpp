#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	string s;
	cin>>s;
	lli n=s.size();
	for(int i=n;i>=0;i--){
		for(int j=1;j<i;j++){
          for(int k=j;k<=n-i;k+=j){
          	
          	if(s.substr(k,i)==s.substr(0,i)){
          		
          		if(k+i-1==n-1){
          			cout<<"YES"<<endl;
          			cout<<s.substr(0,i)<<endl;
          			return;
          		}
          	}
          		else break;
          	}
          }  
		}
		cout<<"NO"<<endl;
	}

int main(){
	lli t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}