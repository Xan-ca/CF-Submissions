#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,pos=0,neg=0,zer=0;
    cin>>n;
    vector<ll>v(n);
    vector<pair<ll,ll>>res;
    for(auto &it:v)cin>>it;
    for(auto it:v)(it==1)?pos++:(it==-1)?neg++:zer++;
    if((neg+pos)%2==1){
    cout<<-1<<endl;
    return;
    }
    if(neg==pos){
    for(ll i=0;i<n;i++) res.push_back({i+1,i+1});
    }
     if(neg>pos){

        for(ll i=0,j=1;i<n-1,j<n;i){
        	if((v[j]==-1 && j>0) && pos!=neg){
        		res.push_back({i+1,j+1});
        		if(j==n-2){
        			res.push_back({j+2,j+2});
        			break;
        		}
        		i+=2,j+=2;
        		neg--;
        		pos++;
        	}else{
        		res.push_back({i+1,i+1});
        		if(j==n-1){
        			res.push_back({j+1,j+1});
        			break;
        		}
        		i++,j++;
        	}
        }
        }
     else if(pos>neg){
        for(ll i=0,j=1;i<n-1,j<n;i){
        	if((v[j]==1 && j>0) && pos!=neg){
        		res.push_back({i+1,j+1});
        		
        		if(j==n-2){
        			res.push_back({j+2,j+2});
        			break;
        		}
        		i+=2,j+=2;
        		pos--;
        		neg++;
        	}else{
        		res.push_back({i+1,i+1});
        		if(j==n-1){
        			res.push_back({j+1,j+1});
        			break;
        		}
        		i++,j++;
        	}
        }
     }
     cout<<res.size()<<endl;
     for(auto it:res)cout<<it.first<<" "<<it.second<<endl;

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