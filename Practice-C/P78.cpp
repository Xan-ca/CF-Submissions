#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
lli x,n;
cin>>n>>x;
int res=0;
for(lli a=1;a<x;a++){
	for(lli b=1;a+b<x && a*b<n;b++){
		if(min((n-(a*b))/(a+b),(x-(a+b)))>0){
			res+=min((n-(a*b))/(a+b),(x-(a+b)));
		};
	};
};
cout<<res<<endl;
	
};
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
};