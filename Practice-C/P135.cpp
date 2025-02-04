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
string s,res;
cin>>s;
char prev='0';
vli pos;
for(lli i=n-1;i>=0;i--){
	if(s[i]>=prev){
	res=s[i]+res;
	prev=s[i];
	pos.push_back(i);
	}

}
//cout<<res<<endl;

for(lli i=0;i<pos.size()/2;i++){
	swap(s[pos[i]],s[pos[pos.size()-1-i]]);
}
if(is_sorted(s.begin(),s.end())){
	for(lli i=0;i<res.size()-1;i++){
	if(res[i]!=res[i+1]){
     cout<<res.size()-i-1<<endl;
     return;
	}
}
cout<<0<<endl;
}else{
	cout<<-1<<endl;
}

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}