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
	pair<lli,lli>mex_pair={0,0};
	for(int i=0;i<n;i++){
		set<lli>s;
		int sn;
		cin>>sn;
		for(int i=0;i<sn;i++){
			int temp;
			cin>>temp;
			s.insert(temp);
		}
		int a=-1,b=-1;
		for(int i=0;i<=sn+1;i++){
			if(s.find(i)==s.end() && a==-1){
				a=i;
			}else if(a!=-1 && s.find(i)==s.end()){
				b=i;
				break;
			}

		}
		s.clear();
		if(b>mex_pair.second){
		mex_pair={0,b};
	}

	}
	lli ans=0;
	if(k>mex_pair.second){
	ans+=k*(k+1)/2-(mex_pair.second*(mex_pair.second+1)/2);	
	ans+=(mex_pair.second*(mex_pair.second+1));

	}
	if(mex_pair.second>=k)ans+=mex_pair.second*(k+1);
	//cout<<mex_pair.second<<endl;
	cout<<ans<<endl;
	
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}