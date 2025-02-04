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
	vli vec(n);
	lli idx=-1;
    for(int i=0;i<n;i++){
    lli inp;
    cin>>inp;
    vec[i]=inp;
    if(inp!=1 && inp!=-1){
        idx=i;
    }
    }
    lli mx1=0,mn1=0,mx2=0,mn2=0;
    lli sum1=0,sum2=0,negsum1=0,negsum2=0;
    for(int i=0;i<idx;i++){
     sum1+=vec[i];
     negsum1+=-vec[i];
     if(sum1<0)sum1=0;
     if(negsum1<0)negsum1=0;
     if(sum1>mx1)mx1=sum1;
     if(negsum1>mn1)mn1=negsum1;
    }
    for(int i=idx+1;i<n;i++){
     sum2+=vec[i];
     negsum2+=-vec[i];
     if(sum2<0)sum2=0;
     if(negsum2<0)negsum2=0;
     if(sum2>mx2)mx2=sum2;
     if(negsum2>mn2)mn2=negsum2;
    }
    mn1=-mn1;
    mn2=-mn2;
    //cout<<mx1<<mn1<<" "<<mx2<<mn2<<endl;
    sum1=0,negsum1=0,sum2=0,negsum2=0;
    int mx3=0,mn3=0,mx4=0,mn4=0;

    for(int i=idx-1;i>=0;i--){
       sum1+=vec[i];
       negsum1+=-vec[i];
       if(sum1>mx3)mx3=sum1;
       if(negsum1>mn3)mn3=negsum1;
    }
    for(int i=idx+1;i<n;i++){
       sum2+=vec[i];
       negsum2+=-vec[i];
       if(sum2>mx4)mx4=sum2;
       if(negsum2>mn4)mn4=negsum2;
    }
    mn3=-mn3;
    mn4=-mn4;
    set<int> s;
    for(int i=mn1;i<=mx1;i++)s.insert(i);
    for(int i=mn2;i<=mx2;i++)s.insert(i);
    if(idx!=-1){
    lli m=max(max(vec[idx]+mx3,vec[idx]+mx4),vec[idx]+mx3+mx4);
    lli n2=min(min(vec[idx]+mn3,vec[idx]+mn4),vec[idx]+mn3+mn4);
    for(int i=n2;i<=m;i++)s.insert(i);
    }
    cout<<s.size()<<endl;
    for(auto it:s)cout<<it<<" ";
    cout<<endl;
    return;
    
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}