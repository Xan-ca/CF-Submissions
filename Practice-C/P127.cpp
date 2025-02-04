#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,m,k;
	cin>>n>>m>>k;
	lli days=ceil(double(k)/m);
	vli sv(n),v(n);
	for(lli i=0;i<n;i++){
		lli temp;
		cin>>temp;
		sv[i]=temp;
		v[i]=temp;
	}
	sort(sv.begin(),sv.end());
	map<lli,lli>mp;
	for(lli i=0;i<days;i++)mp[sv[i]]++;
    vli dayv;
	for(lli i=0;i<n;i++){
		if(mp[v[i]]>0){
			dayv.push_back(v[i]);
			mp[v[i]]--;
		}
	}
	lli remd=k%m;
	if(remd)remd=(m)-remd;
    for(lli i=0;i<days;i++){
       dayv[i]+=i*m;
    }
    lli res=0;
    lli red=0,mxred=0;
    for(lli i=0;i<days;i++){
    	res+=dayv[i]*m;
    	red=(dayv[i]+(m*(days-1-i)));
    	mxred=max(red,mxred);
    }
    //cout<<days<<remd<<endl;
    cout<<res-(remd*mxred)<<endl;


}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}