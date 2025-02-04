#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve(){
	lli n;
	cin>>n;
	vli v(n);
	for(int i=0;i<n;i++)cin>>v[i];
    lli j=0;
	for(lli i=0;i<n-1;i++){
		lli temp=gcd(v[i],v[i+1]);
		if(i>0 && temp<gd[i-1]){
			rem++;
			gd[i-1]=gcd(v[i-1],v[i+1]);
		}
	}
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}