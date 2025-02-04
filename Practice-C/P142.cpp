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
	vli v(n);
	lli res=0,cnt=0;
	for(lli i=0;i<n;i++)cin>>v[i];
	map<int,int>mp;
	for(lli i=0;i<n;i++){
	if(mp.find(v[i])==mp.end()){
	cnt++;
	res+=cnt;
    mp[v[i]]=cnt;
	}else{
	res+=cnt;
	res-=mp[v[i]];
	mp[v[i]]=cnt;
	}
	}

	
		cout<<res<<endl;

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}