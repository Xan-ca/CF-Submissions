#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 struct dsu {
   public:
     dsu() : _n(0) {}
     explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}
 
     int merge(int a, int b) {
         assert(0 <= a && a < _n);
         assert(0 <= b && b < _n);
         int x = leader(a), y = leader(b);
         if (x == y) return x;
         if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
         parent_or_size[x] += parent_or_size[y];
         parent_or_size[y] = x;
         return x;
     }
 
     bool same(int a, int b) {
         assert(0 <= a && a < _n);
         assert(0 <= b && b < _n);
         return leader(a) == leader(b);
     }
 
     int leader(int a) {
         assert(0 <= a && a < _n);
         if (parent_or_size[a] < 0) return a;
         return parent_or_size[a] = leader(parent_or_size[a]);
     }
 
     int size(int a) {
         assert(0 <= a && a < _n);
         return -parent_or_size[leader(a)];
     }
 
     std::vector<std::vector<int>> groups() {
         std::vector<int> leader_buf(_n), group_size(_n);
         for (int i = 0; i < _n; i++) {
             leader_buf[i] = leader(i);
             group_size[leader_buf[i]]++;
         }
         std::vector<std::vector<int>> result(_n);
         for (int i = 0; i < _n; i++) {
             result[i].reserve(group_size[i]);
         }
         for (int i = 0; i < _n; i++) {
             result[leader_buf[i]].push_back(i);
         }
         result.erase(
             std::remove_if(result.begin(), result.end(),
                            [&](const std::vector<int>& v) { return v.empty(); }),
             result.end());
         return result;
     }
 
   private:
     int _n;
     // root node: -1 * component size
     // otherwise: parent
     std::vector<int> parent_or_size;
 };
void Solve() 
{
    ll n,m;
    cin>>n>>m;

    dsu A(n+1);
    for(ll i=0;i<m;i++){
    	ll temp1,temp2;
    	cin>>temp1>>temp2;
    	A.merge(temp1,temp2);
    }
    auto b=A.groups();
    cout<<b.size()-2<<endl;
    for(ll i=2;i<b.size();i++){
    	cout<<b[1][0]<<" "<<b[i][0]<<endl;
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
    
   // cin >> t;
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