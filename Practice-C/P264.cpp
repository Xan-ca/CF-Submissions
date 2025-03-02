#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,m;
   cin>>n>>m;
   vector<pair<ll,ll>>v(n+m+1);
   vector<ll>res(n+m+1,0);
   vector<char>c(n+m+1,'a');
   for(ll i=0;i<n+m+1;i++)cin>>v[i].first;
   	for(ll i=0;i<n+m+1;i++)cin>>v[i].second;
   ll forcedp=-1;
   ll forcedt=-1;
   ll pskill=0;
   ll tskill=0;
   ll f=n+m;
   for(ll i=0;i<f;i++){

   	if(n>0 && v[i].first>v[i].second){
   		c[i]='p';
   		n--;
   		pskill+=v[i].first;
   		continue;
   	} 
   	if(m>0 && v[i].first<v[i].second){
   		c[i]='t';
        m--;
        tskill+=v[i].second; 
        continue;
   	}
   	if(n==0){

   		 m--;
   		 c[i]='t';
       tskill+=v[i].second; 
       if(forcedt==-1 && v[i].first>v[i].second){
       	forcedt=i;
       }
   	}
   	else if(m==0){
         n--;
         c[i]='p';
         pskill+=v[i].first;
       if(forcedp==-1 && v[i].first<v[i].second){
       	forcedp=i;
       }
   	}
   //	cout<<n<<m<<endl;
   	 

   }
   // cout<<pskill<<" "<<tskill<<endl;

   // for(char it:c)cout<<it;

   // 	cout<<endl;
   res[f]=pskill+tskill;
  
     if(forcedp==forcedt && forcedp==-1){
     	for(ll i=0;i<f;i++){
   	 ll t=0,p=0;
   
   	if(c[i]=='t'){
      t=tskill-v[i].second+v[f].second;
      p=pskill;
   	}
   else	if(c[i]=='p'){
      p=pskill-v[i].first+v[f].first;
      t=tskill;
   	}
   	res[i]=p+t;
   }
     }
   
   
   if(forcedt>=0 && forcedp==-1){
   	for(ll i=0;i<f;i++){
   	 ll t=0,p=0;
   
   	if(c[i]=='t'){
      t=tskill-v[i].second+v[f].second;
      p=pskill;
   	}
   else	if(c[i]=='p'){
       t=tskill-v[forcedt].second+v[f].second;
       p=pskill-v[i].first+v[forcedt].first;
   	}
   	res[i]=p+t;
   }
   }
   
if(forcedt==-1 && forcedp>=0){
	for(ll i=0;i<f;i++){
   	 ll t=0,p=0;
   
   	if(c[i]=='p'){
      p=pskill-v[i].first+v[f].first;
      t=tskill;
   	}
   else	if(c[i]=='t'){
       p=pskill-v[forcedp].first+v[f].first;
       t=tskill-v[i].second+v[forcedp].second;
   	}
   	res[i]=p+t;
   }
}
for(auto it:res)cout<<it<<" ";
	cout<<endl;
   

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}