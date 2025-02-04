#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	cin>>n;
	lli k;
	cin>>k;
	lli ans=0;
	stack <pair<lli,lli>>parts;
	parts.push({1,n});
	while(parts.size()>0){
	lli l=parts.top().first;
	lli r=parts.top().second;
	parts.pop();
	lli len=r-l+1;
	if (len<k) continue;
	lli m=(l+r)/2;
	 if ((len) % 2 == 1) {
	 ans+=m;
	  if (l <= m - 1)parts.push({l,m-1});
	 if (m + 1 <= r) parts.push({m+1,r});
	}else{
	 parts.push({l,m});
	 parts.push({m+1,r});
	}
}
cout<<ans<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}