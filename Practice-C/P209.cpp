#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*start with the biggest element that way you can check if you can get 
 you want or no as you start with largest you have more choices to fill the table
 as if choose 5 you can fill 5 4 3 2 all satisfied this way its guaranteed to give you a solution */
void Solve() 
{
    ll n=0,m=0,k=0;
    cin>>n>>m>>k;
    //cerr<<n<<m<<k;
    vector<ll>col(k,0);
    vector<ll>coln,colm;
    for(ll i=0;i<k;i++)cin>>col[i];
    	sort(col.rbegin(),col.rend());
   	cerr<<k;
    for(ll i=0;i<k;i++){
    ll cn=(col[i]/n);
    ll cm=(col[i]/m);
   if(cn>1)coln.push_back(cn);
   if(cm>1)colm.push_back(cm);
    }
   //cout<<colm.size()<<endl;
    
    ll sumn=0,extrn=0;
    for(ll i=0;i<coln.size();i++){
    	
    		sumn+=2;
    		extrn+=coln[i]-2;
             
    	if(sumn<=m && sumn+extrn>=m){
    		cout<<"YES"<<endl;
    		return;

    	}
    }
    ll summ=0,extrm=0;
    for(ll i=0;i<colm.size();i++){
    	
    		summ+=2;
    		extrm+=colm[i]-2;
    	
    	if(summ<=n && summ+extrm>=n){
    		cout<<"YES"<<endl;
    		return;

    	}
    }
cout<<"NO"<<endl;
return;


}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 0;
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