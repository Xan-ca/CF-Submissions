#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,k;
	cin>>n>>k;
	string v;
	vli s(n);
	cin>>v;
	lli p=0,ne=0;
	for(lli i=n-1;i>=0;i--){
     if(v[i]=='1')p++;
     else ne++;
     s[i]=p-ne;

	}
	
	sort(s.begin()+1,s.end());
	lli res=0;
	lli sum=0;
	for(lli i=n-1;i>=0;i--){
	if(sum>=k){
	cout<<n-i<<endl;
	return;
	}
	sum+=s[i];

	}
	cout<<-1<<endl;
	return;

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}