#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
    lli n,k;
    cin>>n>>k;
    vli a(n);
    vli b(n);
    vector<vector<lli>>v(2*n,vector<lli>(3));
    vector <lli>imp(2*n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(lli i=0;i<n;i++)imp[i]=a[i];
    for(lli i=n;i<2*n;i++)imp[i]=b[i-n];
    //for(auto it:imp)cout<<it<<endl;
    sort(imp.begin(),imp.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(lli i=0;i<2*n;i++){
      auto count1=lower_bound(a.begin(),a.end(),imp[i]);
      auto count2=lower_bound(b.begin(),b.end(),imp[i]);
      lli aba=count1-a.begin();
      lli ntby=count2-b.begin();
      lli buy=n-ntby;
      lli negrv=aba-ntby;
      v[i][0]=negrv;
      v[i][1]=buy;
      v[i][2]=imp[i];
      //cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
    }
    lli res=0;
    sort(v.begin(),v.end());
    for(lli i=0;i<2*n;i++){
       if(v[i][0]>k)break;
       res=max(res,v[i][1]*v[i][2]);
    }
    cout<<res<<endl;

    
}
int main(){
    lli t;
    cin>>t;
    while(t--)solve();
    return 0;
}