#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	string s;
	cin>>n>>s;
	int S=0,P=0;
	for(int i=0;i<n;i++){
	if(s[i]=='s')S++;
	if(s[i]=='p')P++;
	}
	//cout<<S<<P<<endl;
	if(S==0||P==0){
	cout<<"YES"<<endl;
	return;
	}else{
	if(S>1&& P>1){
	cout<<"NO"<<endl;
	return;
	}
	else if(S==1 && s[0]=='s'){
      cout<<"YES"<<endl;
      return ;
	}
	else if(P==1 && s[n-1]=='p'){
      cout<<"YES"<<endl;
      return ;
	}
	cout<<"NO"<<endl;
	return;

	}
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}