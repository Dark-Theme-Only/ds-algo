#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SIZE 200010
#define MOD 1000000007
#define BIG 998244353
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define mii map<int,int>
#define set_bit __builtin_popcount
#define all(v) v.begin(),v.end()
#define PSET(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>
#define vip vector<pair<int,int> >
#define MSET(table,i) memset(table, i, sizeof(table))
#define pi  3.1415926358
#define minimum(a,n) min_element(a,a+n)-a
#define maximum(a,n) max_element(a,a+n)-a
#define pqbig priority_queue<int>
#define pqsmall priority_queue<int,vector<int>,greater<int> >
#define all(v) v.begin(),v.end()
#define sitr set<int>:: iterator
#define mitr map<int,int>:: iterator
#define tc int tcs;cin>>tcs;while(tcs--)
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ){stringstream ss; ss<< number; return ss.str();}

 
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 

ll n,m;
ll stree[4000000];
ll arr[1000000];


int build(ll ind,ll l,ll r){
	if(l==r){
		stree[ind]=arr[l];
		return 0;
	}

	ll mid=(l+r)/2;
	int x=build(2*ind,l,mid);
	int y=build(2*ind+1,mid+1,r);
	if(x==0){
		stree[ind]=(stree[2*ind]|stree[2*ind+1]);
		return 1;
	}else{
		stree[ind]=(stree[2*ind]^stree[2*ind+1]);
		return 0;
	}
}

int update(ll ind,ll l,ll r,ll idx,ll val){
	if(l==r){
		arr[l]=val;
		stree[ind]=arr[l];
		return 0;
	}

	ll mid=(l+r)/2;
	int temp;
	if(idx<=mid){
		temp=update(2*ind,l,mid,idx,val);
	}else{
		temp=update(2*ind+1,mid+1,r,idx,val);
	}

	if(temp==0){
		stree[ind]=(stree[2*ind]|stree[2*ind+1]);
		return 1;
	}else{
		stree[ind]=(stree[2*ind]^stree[2*ind+1]);
		return 0;
	}
}

int main(){
	fast;
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	#endif
	cin>>n>>m;
	n=1<<n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	build(1,1,n);
	for(int i=0;i<m;i++){
		ll idx,val; cin>>idx>>val;
		update(1,1,n,idx,val);
		cout<<stree[1]<<endl;
	}
	return 0;
}