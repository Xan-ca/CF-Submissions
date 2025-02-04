#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
bool sol(lli a,lli b){
	if(a==b)return true;
	if(a%3!=0)return false;
	if(a==0)return false;
	return(sol((a/3)*2,b)||sol((a/3),b));
}
void solve(){
lli a ,b;
	cin>>a>>b;
	if(a%3==0){
	if(sol((a/3)*2,b)){
	cout<<"YES"<<endl;
	return;
	}
	if(sol((a/3),b)){
	cout<<"YES"<<endl;
	return;
	}
	}
	else{
	if(a==b){
	cout<<"YES"<<endl;
	return;
	}else{
	cout<<"NO"<<endl;
	return;
	}
	}
	cout<<"NO"<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}