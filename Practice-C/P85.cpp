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
	int ab=0,ba=0;
	vli pos1,pos2;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='B'&& s[i+1]=='A'){
			ab++;
			pos1.push_back(i);
			//cout<<i;
		}

		if(s[i]=='A'&& s[i+1]=='B'){
			ba++;
			pos2.push_back(i);
			//cout<<i;
		}

		if((pos1.size()&&pos2.size())){
			if(abs(pos1[pos1.size()-1]-pos2[0])>=2 ||abs(pos1[0]-pos2[pos2.size()-1])>=2 )
				{cout<<"YES"<<endl;
			return;
		}
		}

	}
	cout<<"NO"<<endl;
}
int main(){
	lli t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}