#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,m;
	cin>>n>>m;
	vli a(n);
	multiset <int>b;
	a[0]=1;
	for(lli i=1;i<n;i++){
	cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(lli i=0;i<n;i++){
	int temp;
	cin>>temp;
	b.insert(temp);
	}
	for(lli i=0;i<n;i++){
	auto it = b.upper_bound(a[i]);
	  
    if (b.find(*it) != b.end() && *it>a[i]){
      
       b.erase(b.find(*it));
    }
    else{
      break;
    }
	}
	lli res=0;
	res+=b.size();
	
	for(lli i=1;i<n;i++){
		res+=res
	}
	cout<<b.size()<<endl;
	return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}