#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	vli v;
	cin>>n;
	set <lli> s;
	lli a;
	for(lli i=0;i<n;i++){
	cin>>a;
	s.insert(a);
	}
	for(auto it :s)v.push_back(it);
	if(v[0]==1){
	lli i=1;
	for(int j=0;j<v.size();j++){
		if(v[j+1]==v[j]+1){
           i=v[j+1];
		}else break;
	}
	//cout<<i<<endl;
	if(i%2==0){
	if(v.size()==i)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
	}
	else{
	if(v.size()==i)cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
	}
	}else cout<<"Alice"<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}