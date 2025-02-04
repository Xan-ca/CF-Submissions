#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define vli vector<long long>

void solve() {
    lli n, m, k;
    cin >> n >> m >> k;
    vli vn(n), vm(m);

    unordered_set<lli> mp;
    map<lli,lli>copy;
    for (lli i = 0; i < n; i++) cin >> vn[i];
    for (lli i = 0; i < m; i++) cin >> vm[i];
    for (auto it : vm){
    mp.insert(it);	
    copy[it]++;
    }  
    
    

    map<lli, lli> freq; 
    lli match = 0, res = 0;

    
    for (lli j = 0; j < m; j++) {
        if (mp.count(vn[j])) {
            if (freq[vn[j]] <copy[vn[j]]) match++;
            freq[vn[j]]++;
        }
    }
    
if (match>=k) res++;
    
    for (lli i = 1, j = m; j < n; i++, j++) {
       
        if (mp.count(vn[i-1])) {
            freq[vn[i-1]]--;
            if ( freq[vn[i-1]] <copy[vn[i-1]] ) match--;
        }
        
        if (mp.count(vn[j])) {
            if (freq[vn[j]] <copy[vn[j]]) match++;
            freq[vn[j]]++;
        }
        
        if (match >= k) res++;
    }

    cout << res << endl;
}

int main() {
    lli t;
    cin >> t;
    while (t--) solve();
    return 0;
}
