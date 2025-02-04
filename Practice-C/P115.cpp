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
	map<int,int>mp1,mp0;
	vector<vector<lli>>vec;
	for(int i=0;i<n;i++){
		lli a,b;
		cin>>b>>a;
		vec.push_back({a,b});
		if(a==1){
			mp1[b]==1;
		}else{
			mp0[b]==1;
		}
	}
	lli res=0;
	for(auto it:vec){
       if(it[0]==0){
       	if(mp1.find(it[1])!=mp1.end())res+=n-2;
       	if(mp1.find(it[1]+1)!=mp1.end()&&mp1.find(it[1]-1)!=mp1.end())res+=1;
       }
       else{
       	//if(mp0.find(it[1])!=mp0.end())res+=n-2;
       	if(mp0.find(it[1]+1)!=mp0.end()&&mp0.find(it[1]-1)!=mp0.end())res+=1;
       }
	};
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}