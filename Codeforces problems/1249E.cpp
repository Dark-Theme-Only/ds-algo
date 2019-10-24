#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,c;
  cin >> n >> c;
  ll a[n-1];
  ll b[n-1];
  for (ll i = 0; i < n-1; i++) {
    cin >> a[i];
  }

  for (ll i = 0; i < n-1; i++) {
    cin >> b[i];
  }
  ll dp[n+1][2];
  memset(dp, 10000 , sizeof dp);
  dp[0][0]=0;
  dp[0][1]=c;
  for (ll i = 0; i < n-1; i++) {
    dp[i+1][0] = min(dp[i+1][0], dp[i][0] + a[i]);
    dp[i+1][0] = min(dp[i+1][0], dp[i][1] + a[i]);
    dp[i+1][1] = min(dp[i+1][1], dp[i][1] + b[i]);
    dp[i+1][1] = min(dp[i+1][1], dp[i][0] + b[i] + c);
  }
  for (ll i = 0; i < n; i++) {
    cout << min(dp[i][0], dp[i][1]) << " ";
  }
}
