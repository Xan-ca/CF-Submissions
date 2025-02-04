#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int q; cin >> q;
    bool otherA = false, otherB = false;
    ll cntA = 0, cntB = 0;
    while(q--) {
        ll d, k; string x; cin >> d >> k >> x;
        for(auto c: x) {
            if(d == 1) {
                if(c != 'a') otherA = 1;
                else cntA += k;
            } else {
                if(c != 'a') otherB = 1;
                else cntB += k;
            } 
        }
        if(otherB) {
            cout << "YES\n";
        } else if(!otherA && cntA < cntB) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}