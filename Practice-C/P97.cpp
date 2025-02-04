#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,x,y;
	cin>>n>>x>>y;
    vli v(n);
    lli res=0;
	for(lli i=0;i<n;i++)cin>>v[i];
		sort(v.begin(),v.end());
	lli sum=accumulate(v.begin(),v.end(),0LL);
    for(lli i=0;i<n;i++){
    	lli tempsum=sum-v[i];
    	lli lo=tempsum-y;
    	lli hi=tempsum-x;
    	auto lob=lower_bound(v.begin()+i+1,v.end(),lo);
    	auto hib=upper_bound(v.begin()+i+1,v.end(),hi);
    	lli count1=(v.end()-lob);
    	lli count2=(v.end()-hib);
    	//cout<<lo<<count1<<" "<<hi<<count2<<endl;
         res+=count1-count2 ;
    }
    cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}