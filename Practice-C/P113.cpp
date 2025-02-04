#include<bits/stdc++.h>
using namespace std;
#define inf 10000000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	cin>>n;
	vli v(n);
	
	set<long long int>st;
	map <lli,lli> mp;
	for(lli i=0;i<n;i++)cin>>v[i];
	for(lli i=0;i<n;i++){
        mp[v[i]]++;
        st.insert(v[i]);	
	}
	vli sat;
	for (auto it:st)sat.push_back(it);
	vli res;
	vli residue;
	lli j=0,mi=inf;
	lli k=0;
	for(lli i=0;i<n;i++){
	lli curr=sat[k];
	if(v[i]==curr){
		res.push_back(v[i]);
	}else{
		residue.push_back(v[i]+1);
		mi=min(mi,v[i]);
	}
	mp[v[i]]--;
	while( k<st.size() && mp[curr]<=0)
	{
	k++;
	curr=sat[k];
    }
	
	//cout<<mi<<endl;
	if(mi+1<curr){
		for(i=i+1;i<n;i++)residue.push_back(v[i]+1);
		break;
	}
	
	}
	sort(residue.begin(),residue.end());
	for(auto it: res)cout<<it<<" ";
	for(auto it: residue)cout<<it<<" ";
		cout<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}