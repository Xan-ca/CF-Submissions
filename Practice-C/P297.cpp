#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<vector<ll>>vec(n);
    for(auto &it:v)cin>>it;
    ll k=0;
    ll prod=1;
    for(ll i=0;i<n;i++){

    	if(v[i]==0){
    		if(vec[k].size()!=0)k++;
    		//vec.push_back({});
    		while(i<n && v[i]==0){
    		prod=1;
    		
    		vec[k].push_back(0);
    		if(vec[k].size()!=0)k++;
    		//vec.push_back({});
    		i++;
    	}
    	}
    	if(i>=n)break;	
    	prod*=v[i];
    	vec[k].push_back(prod);

    }
    cout<<endl;
    for(auto it:vec){
     if(it.size()>0)
     	{for(auto i:it)cout<<i<<" ";
     	cout<<endl;
     }
    }
    ll start=0;
    for(ll i=0;i<n;i++){
    	ll value=1;
    	if(vec[i].size()>0 && v[i][0]!=0){
           for(auto it:vec[i])value*=it;
           if(it<0){
           	ll left=0;
           	ll lefval=1,rightval=1;
           	ll right=vec[i].size()-1;
           	while(left<=right && leftval>0){
           		lefval*=vec[k][left];
           		left++;
           	}
           	while(right>=0 && rightval>0){
           		rightval*=vec[k][right];
           		right--;
           	}
            if(leftval>rightval){
              l=start;
              r=start+vec[i].size()-((vec[i].size()-1)-right);
            }else{
            	r=start+vec[i].size();
            	l=start+left;
            }
            
           }
           if()   
        


    	}else{
    		if(vec[i].size()>0 && v[i][0]==0)start++;
    	}
    }


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
        cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}