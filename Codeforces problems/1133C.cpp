#include <bits/stdc++.h>
using namespace std ; 
#define ll long long
#define rep(i ,a ,b) for(int  i = a ; i<b ; i++)
#define ios        	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
	ll n ; 
	cin>>n ; 
	vector <int> v ; 
	rep(i,0,n)
	{
		ll x ; 
		cin>>x ; 
		v.push_back(x);
	}
	int j  = 0 ; 
	int ans =  0  ; 
	sort(v.begin(), v.end());
	rep(i,0,n)
	{	
		while(j<n && v[j]-v[i]<=5)
		{
			j++ ;
			ans = max(ans ,j-i);
		}
	}
	cout<<ans<<endl ; 


}