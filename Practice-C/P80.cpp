#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<-1<<endl;
		return;
	}
	if(s.size()==2){
		if(s[0]!=s[1]){
			cout<<-1<<endl;
			return;
		}else{
			cout<<s.substr(0,2)<<endl;
			return;
		}
	}
	for(int i=0;i<s.size()-2;i++){
		if(s[i]==s[i+2]){
			if(s[i]==s[i+1]){
				cout<<s.substr(i,2)<<endl;
				return;
			}else if(s[i+1]==s[i+2]){
				cout<<s.substr(i+1,2)<<endl;
				return;
			}
			else continue;
		}
		else{
			if(s[i]==s[i+1]){
				cout<<s.substr(i,2)<<endl;
				return;
			}else if(s[i+1]==s[i+2]){
				cout<<s.substr(i+1,2)<<endl;
				return;
			}
			else{
				cout<<s.substr(i,3)<<endl;
				return;
			}
		}

	}
	cout<<-1<<endl;
	return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}