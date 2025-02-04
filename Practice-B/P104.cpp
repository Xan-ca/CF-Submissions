#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,d;
	cin>>n>>d;
	cout<<"1"<<" ";
	if(n==1){
    if(d%3==0)cout<<"3"<<" ";
	if(d==5)cout<<"5"<<" ";
	if(d%7==0)cout<<"7"<<" ";
	if(d%9==0)cout<<"9"<<" ";
	cout<<endl;
	return;
	}
	if(n==2){
	d=d*10+d;
	if(d%3==0)cout<<"3"<<" ";
	if(d%5==0)cout<<"5"<<" ";
	if(d%7==0)cout<<"7"<<" ";
	if(d%9==0)cout<<"9"<<" ";
	cout<<endl;
	return;
	}
	if(n>=3 || d%3==0)cout<<"3"<<" ";
	if(d==5)cout<<"5"<<" ";
	if(n>=3 || d%7==0)cout<<"7"<<" ";
	if(n>=6 || d%9==0 || (n>=3 && d%3==0 ))cout<<"9"<<" ";
	cout<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}