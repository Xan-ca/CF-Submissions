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
	lli count=0,res=0;
	vli v(n),s(n);
	for(lli i=0;i<n;i++){
		cin>>v[i];
	}
	s[0]=v[0];
	for(lli i=1;i<n;i++){
        s[i]=s[i-1]+v[i];
	}
	sort(s.begin(),s.end()-1);
	
	for(lli i=0;i<n-1;i++){
      if(s[i]>s[n-1]){
      	break;
      }
      res+=s[n-1]-s[i];
	}
	res+=s[n-1];
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}