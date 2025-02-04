#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli k,l1,r1,l2,r2;
	cin>>k>>l1>>r1>>l2>>r2;
    lli res=0;
	for(lli i=0;pow(k,i)<=r2;i++){
     lld a=l2/pow(k,i);
     lld b=r2/pow(k,i);
     
     lld c=l1;
     lld d=r1;
     if (a > b) swap(a, b);
     if (c > d) swap(c, d);

    
    lld start = max(a, c);
    lld end = min(b, d);

     dddeeeeee	gfVCVCCCCCCCCCCCCCCCCV 	CVVV	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  b
    lli count=floor(end)-ceil(start)+1;
  
    if (ceil(start) > floor(end)) count=0;
     res+=count;
	
}
cout<<res<<endl;
return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}