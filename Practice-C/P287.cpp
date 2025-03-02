#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // find count of each char
 // find how many char of each lenthg required for 1 to 26 numbers of char
 // find min for each numbers of char;
void Solve() 

{ 
   ll n;
   cin>>n;  
   string s;
   cin>>s;
   vector<ll>v(26,0);
   for(ll i=0;i<n;i++){
     v[s[i]-'a']++;
   } 
   
   vector<ll>pos(26,0);
   for(ll i=0;i<26;i++)pos[i]=i;

   	auto cstmsort=[&](ll a, ll b)-> bool{
      return v[a]>v[b];
   	};
   	sort(all(pos),cstmsort);

   	sort(v.rbegin(),v.rend());

   auto countchanges=[&](ll count)->ll{
     ll ret=0;
     ll maxchars=n/count;
     for(ll i=0;i<26;i++){
     if(i<count)ret+=(v[i]>maxchars)?v[i]-maxchars:0;
     if(i>=count)ret+=v[i];
     }
     return ret;
   };
   ll change_elem=0,changes=INF;

   for(ll i=1;i<=26;i++){
    if(n%i==0){
    if(countchanges(i)<changes){
     changes=countchanges(i);
     change_elem=i;
    }
    }
   }
   vector<pair<char,ll>>extra,less;
    ll maxchars=n/change_elem;
   for(ll i=0;i<26;i++){
     if(i<change_elem){
     	if(v[i]>maxchars){
     		extra.push_back({'a'+pos[i],v[i]-maxchars});
     	}else if(v[i]<maxchars){
            less.push_back({'a'+pos[i],maxchars-v[i]});
     	}
     }
     if(i>=change_elem)extra.push_back({'a'+pos[i],v[i]});;
     }
     
         
     
     ll lsptr=0,exptr=0;
     
    for(ll j=0;j<26;j++){
    	for(ll i=0;i<n;i++){
     	if(exptr<extra.size() &&extra[exptr].second<=0 )exptr++;
     	if(lsptr<less.size() && less[lsptr].second<=0 )lsptr++;
     	if(lsptr>=less.size() || exptr>=extra.size())break;
        if(s[i]==extra[exptr].first){
           s[i]=less[lsptr].first;
           extra[exptr].second--;
           less[lsptr].second--;
        }
     }if(lsptr>=less.size() || exptr>=extra.size())break;
    } 
     

   cout<<changes<<endl;
   cout<<s<<endl;
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