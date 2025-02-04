#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli countDigits(lli n) {
    if (n == 0) return 1; // Special case for 0
    int count = 0;
    n = abs(n); // Handle negative numbers
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}
lli countzero(lli n){
	int count=0;
	while(n%10==0 && n>0){
		count++;
		n/=10;
	}
	return count;
}
void solve(){
	lli n,m;
	cin>>n>>m;
	vli arr(n);
	for(lli i=0;i<n;i++){
		cin>>arr[i];
	}
	vli zero(n);
	vli count(n);
	for(lli i=0;i<n;i++)
    {
    count[i]=countDigits(arr[i]);
    zero[i]=countzero(arr[i]);
    }
    sort(zero.rbegin(),zero.rend());
    lli res=0,tot=0;
    for(lli i=0;i<n;i++){
       if(i%2==0 && i<n)res+=zero[i];
       tot+=count[i];
    }
    //cout<<tot<<res<<endl;
    if(tot-res>m)cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}