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
	vli v(n+1,0);
	for(lli i=1;i<=n;i++)cin>>v[i];
	for(lli i=1;i<=n;i++){
	lli prev=i+v[i];
    if(prev>n){
    prev=prev-n;
    }
    if(prev==v[i]){
    cout<<"YES"<<endl;
    }
	}
	cout<<"NO"<<endl;
	return;

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}