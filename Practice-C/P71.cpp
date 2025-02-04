#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int solve(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll res=((n)*(n+1))/2;
	ll opt=n-1;
	ll cnt=0;
	for(ll i=n-1;i>=1;i--){
	if(opt<=0){
			break;
	}
	if(s[i]=='1' && opt>0){
		//cout<<i+1;
	res-=i+1;
	}
	if(i-1>=0 && (s[i]=='1' )){

      opt-=2;
      cnt++;
	}
	if(i-1>=0 && s[i]=='0'){
		if(cnt>0){
			cnt--;
		}else{
		opt-=1;	
		}
	
	}
	}0
	cout<<res<<endl;
	return 0;

}
int main(){
	ll t;
	cin>>t;
	while(t--){
	solve();
	}
}