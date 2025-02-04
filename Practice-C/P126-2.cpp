#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int
main ()
{
  ios::sync_with_stdio (false);
  cin.tie (nullptr);
  ll tt = 1;
  cin >> tt;
  while (tt--)
    {
      ll n, m, k;
      cin >> n >> m >> k;
      ll a[n];
      for (int i = 0; i < n; i++)
        {
          cin >> a[i];
        }
      map < ll, ll > mp;
      ll temp;
      map < ll, ll > copy;
      for (int i = 0; i < m; i++)
        {
          cin >> temp;
          mp[temp]++;
          copy[a[i]];
        }
      map < ll, ll > pp;
      ll sum = 0;
      ll ans = 0;
      for (int i = 0; i < m; i++)
        {
          if (mp[a[i]] != 0)
            {
              if (pp[a[i]] < mp[a[i]])
                {
                  pp[a[i]]++;
                  sum ++;
                }
            }
        }
    //     for(auto x:pp)cout<<x.second<<" ";
    //     cout<<endl;
    //   cout<<sum<<endl;
      for (int i = 0; i < m; i++)
        {
          if (mp[a[i]] != 0)
            {
              copy[a[i]]++;
            }
        }
       // cout<<copy[9]<<endl;
      if (sum >= k)
        {
          ans++;
        }
      ll sum1;
 
      for (int i = m; i < n; i++)
        {
          if (mp[a[i - m]] != 0)
            {
              sum--;
              copy[a[i - m]]--;
 
              if (copy[a[i - m]] >= mp[a[i-m]])
                sum++;
            }
 
 
          if (mp[a[i]] != 0)
            {
                 copy[a[i]]++;
              if (copy[a[i]] <= mp[a[i]])
                {
                  sum++;
                }
            
            }
       //   cout<<i-m<<" "<<sum<<endl;
          if (sum >= k)
            ans++;
 
        }
 
      cout << ans << endl;
    }
 
 
  return 0;
}