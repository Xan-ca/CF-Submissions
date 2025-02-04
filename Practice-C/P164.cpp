#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll get(ll x) {
    return x * (x + 1) / 2;
}
bool f(ll mid, ll k, ll x) {
    if(mid > k) {
        return (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
    } else {
        return (get(mid) >= x);
    }
}
int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        ll k, x;
        cin >> k >> x;
        ll lo = 0 , hi = 2 * k;
        while (hi > lo + 1) {
            ll mid = lo + (hi - lo)/2;
            if(f(mid, k, x)){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if(hi>(2 * k)-1){
        	cout<<(2 * k)-1<<endl;
        } else cout << hi << endl;
    }
}