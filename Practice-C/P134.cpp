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
	vli l(n),r(n),c(n);
    set <int>st;
	vector<pair<lli,lli>> v(n);
	for(lli i=0;i<n;i++)cin>>l[i];
	for(lli i=0;i<n;i++){
		cin>>r[i];
		st.insert(r[i]);
	}
	for(lli i=0;i<n;i++)cin>>c[i];
	
	vli dis;
	sort(r.begin(),r.end());
	sort(l.begin(),l.end());
	for(lli i=n-1;i>=0;i--){
		lli k=*st.lower_bound(l[i]);
		dis.push_back(k-l[i]);
		st.erase(k);
	}
	
	sort(dis.begin(),dis.end());
	sort(c.begin(),c.end());
	lli res=0;
	for(lli i=0,j=n-1;i<n;i++){
		res+=c[j-i]*dis[i];
	}
	cout<<res<<endl;
	
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}