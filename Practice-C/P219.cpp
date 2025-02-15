#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
set<pair<ll,ll>>pwst;
vector<pair<ll,ll>>v;
void initpowerfactorial(vector <ll> &fact,ll i,ll n,ll curr,ll cnt){
    if(i==n)return;
    if(curr<=1e12)pwst.insert({curr,cnt});
    initpowerfactorial(fact,i+1,15,curr,cnt);
    initpowerfactorial(fact,i+1,15,curr+fact[i],cnt+1);
}

void init(){
	vector<ll>fact(14);
	fact[0]=1;
	for(ll i=1;i<14;i++){
       fact[i]=fact[i-1]*(i+1);
	}       
 initpowerfactorial(fact,1,15,0,0);
  set<pair<ll,ll>>::iterator itr;
  for (itr = pwst.begin();itr != pwst.end(); itr++) 
  { 
    //cout<<(*itr).first<<" "<<(*itr).second<<endl;
    v.push_back({(*itr).first,(*itr).second});
  }

   
}
ll countSetBits(ll n)
{
    ll count =0;
    while (n) {
        count += (n % 2);
        n/=2;
    }
    return count;
}
void Solve() 
{
  
  ll n;
  cin>>n;
  ll res=INF;
 // cout<<countSetBits(13);
  for(ll i=0;i<v.size();i++){

    if(v[i].first<=n)res=min(countSetBits(n-v[i].first)+v[i].second,res);
  }
  cout<<res<<endl;
  return;
}  

 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    init();
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