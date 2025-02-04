#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	string s;
	lli n;
	cin>>n;
	cin>>s;
	if(n==2){
		cout<<((s[0]-'0')*10)+s[1]-'0'<<endl;
		return;
	}
	lli res=1e7;
	//lli n=s.size();
	for(int i=0;i<n-1;i++){
	lli m1=0,m2=0;
	for(int j=0;j<i;j++){
      if(s[j]=='0'){
      cout<<0<<endl;
      return;
      }
      if(s[j]=='1'&& m1>0){
      	m1=m1;
      }
      else{
      m1+=s[j]-'0';
      }
	}
	for(int k=i+2;k<n;k++){
        if(s[k]=='0'){
          cout<<0<<endl;
          return;
      }
      if(s[k]=='1'&& m2>0)m2=m2;
      else{
      m2+=s[k]-'0';
      }
	}

	lli m=((s[i]-'0')*10)+s[i+1]-'0';
	if(m==0){
          cout<<0<<endl;
          return;
      }
	if(m1==1||m==1){
	m=max(m,m1);
	}else{
	m+=m1;
	}
	if(m2==1||m==1)m=max(m,m2);
	else{
	m+=m2;
	}
	//cout<<m1<<m<<m2<<endl;
	res=min(m,res);
	}
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}