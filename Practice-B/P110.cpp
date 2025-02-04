#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli h1,h2;
	lli d,n;
	cin>>h1>>h2>>d>>n;
	int days=0;
	if(n>=d){
	if(h1+(d*8)<h2)cout<<-1<<endl;
	else {
		cout<<0<<endl;}
	return;
	}
	else{
	h1 =h1+(d*8);
	if(h1<h2){
	days+=ceil(double(h2-h1)/double((d*12)-(n*12)));
	cout<<days<<endl;
	}else{
	cout<<0<<endl;
	}
	}
}
int main(){
	lli t;
	t=1;
	while(t--)solve();
	return 0;
}