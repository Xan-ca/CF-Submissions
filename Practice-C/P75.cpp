#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>


int solve(){
	lli n,k;
	cin>>n>>k;
	set<lli>arr;
	
    lli mx=0,mi=1e6;
	lli mxe=0;
	for(lli i=0;i<n;i++){
		lli temp;
		cin>>temp;
	mxe=max(mxe,temp);
	arr.insert(temp%(2*k));
	}
	
	lli diff=*arr.rbegin()-*arr.begin();
	for(auto it: arr){
		if(it<k){
			mx=max(mx,it);
		}
		if(it>=k){
			mi=min(mi,it);
		}
	}
	//int tem=diff;

	diff=min(diff,(mx+(2*k))-mi);
	if(diff>=k){
		cout<<-1<<endl;
		return 0;
	}
	vli v;
	lli cnt=0;
	lli index;
	for (auto it:arr){
		if(mxe%(2*k)==it){
			index=cnt;
		}
		cnt++;
		v.push_back(it);
	}
	lli siz=v.size();

	lli mmxe=mxe%(2*k);
	bool lock=false;

	for(lli i=0;i<siz;i++){
		if(v[i]<k){
			if(((v[i]+2*k)-mmxe)<k)v.push_back(v[i]+2*k);
			else break;
		}
	}
	int dif=0;
	siz=v.size();
	for(lli i=0;i<siz;i++){
		if(v[i]-mmxe<k){
			dif=v[i]-mmxe;
		}else{
			break;
		}
	}
	
	
	cout<<mxe+dif<<endl;
	//cout<<1<<endl;
	return 0;
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}