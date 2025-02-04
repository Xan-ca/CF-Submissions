#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli vworks(lli val,vli&v,lli k,lli n){
	lli res=0;
for(lli i=0;i<n;i++){
	if(val>v[i]){
		res-=(val-v[i]);
		//cout<<v[i]<<endl;
	}
}
res+=k;
return res;
}
void solve(){
lli n,k;
cin>>n>>k;
vli v(n);
for(lli i=0;i<n;i++)cin>>v[i];
lli lo=0,hi=1e13;
lli mid=(hi+lo)/2;
lli rem=0;
while(hi-lo>0){
	mid=(hi+lo)/2;
	rem=vworks(mid,v,k,n);
	//cout<<vworks(mid,v,k,n)<<endl;;
    if(rem>=0){
    	lo=mid+1;
    }else{
    	hi=mid;
    }
}
//cout<<hi-1<<endl;
rem=vworks(hi-1,v,k,n);
//lli cnt=0;
for(lli i=0;i<n;i++){

if(v[i]<hi-1)v[i]=hi-1;

}
lli cnt=0;
for(lli i=0;i<n;i++){
	if(v[i]>=hi)cnt++;
	else break;
}
for(lli j=n-1;j>=0;j--){
	if(v[j]>=hi)cnt++;
	else break;
}
lli ci=0,cj=0,posi=0,posj=n-1;
lli ini=0,inj=0;

for(lli i=0,j=n-1;i<n,j>=0;){
if(rem<=0)break;
while(i<n && ci!=2){
	
	if(v[i]<hi){

		ci++;
		ini=i-posi;
		posi=i;
	}
	i++;
}

while(j>=0 && cj!=2){

	if(v[j]<hi){
		cj--;
		inj=posj-j;
		posj=j;

	}
	j--;
}
if(ini>inj){
	cout<<ini<<" "<<inj<<endl;
	if(rem>=hi-v[i]){
		rem--;
	cnt+=ini;
	ci--;
}else rem=-1;
}else{
	cout<<ini<<" "<<inj<<endl;
	if(rem>=hi-v[j]){
		rem--;
cnt+=inj;
	cj--;	
}
	else rem=-1;
	
}
}
cout<<cnt<<endl;


}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}