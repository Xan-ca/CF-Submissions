#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
#define ull unsigned long long

ull fun(ull n){
	return n- (unsigned long long int)(sqrt(n));
}
void solve(){
ull n;
cin>>n;
ull lo=1;
ull hi=1<<63;
cout<<hi<<endl;
while(hi-lo>1){
ull mid=((hi-lo)/2)+lo;
if(fun(mid)>=n){
    hi=mid-1;
}else{
	  lo=mid;
}
}

if(fun(lo+1)==n){
cout<<lo+1;

}
else{
cout<<hi+1;

}
cout<<endl;
return;
	
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}