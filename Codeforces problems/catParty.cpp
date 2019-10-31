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
#define tc int tcs;cin>>tcs;while(tcs--)
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ){stringstream ss; ss<< number; return ss.str();}


int main(){
	fast;
	int n;
	cin>>n;
	int u;
	vector<int> rib;
	vector<int> num(11,0);
	int maxx=INT_MIN;
	for (int j = 0; j < n; ++j)
	{
		cin>>u;
		rib.pb(u);
		num[u-1]++;
		bool extraUsed=false;
		bool possible=true;
		int maxCount=INT_MIN;
		int currcount=INT_MAX;
		for(int i=0;i<10;i++){
			if(num[i]==0){
				continue;
			}
			currcount=min(currcount,num[i]);
			maxCount=max(maxCount,num[i]);
		}
		// cout<<currcount<<endl;
		// for(int i=0;i<10;i++){
		// 	cout<<num[i]<<" ";
		// }
		// cout<<endl;
		for(int i=0;i<10;i++){
			if(num[i]==0){
				continue;
			}

			if(num[i]==currcount){
				continue;
			}
			if(num[i]==currcount+1 && !extraUsed){
				extraUsed=true;
			}else if(num[i]==currcount+1 &&extraUsed){
				possible=false;
				break;
			}
			//if(currcount>)
			if(maxCount-currcount>1 && currcount!=1){
				possible=false;
				break;
			}
		}

		if(possible){
			maxx=max(j+1,maxx);
		}
	}
	cout<<maxx<<endl;
	return 0;
}