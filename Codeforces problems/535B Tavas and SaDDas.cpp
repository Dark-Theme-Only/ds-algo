// https://codeforces.com/problemset/problem/535/B

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;

	int size = log10(n) + 1;

	ll ans = 2 * (pow(2, size - 1) - 1);

	ll temp = 1;
	ll p = 1;
	while (n != 0) {
		int digit = n % 10;
		if (digit == 7) {
			temp += p;
		}

		n /= 10;
		p *= 2;
	}

	cout << ans + temp  << endl;

}
