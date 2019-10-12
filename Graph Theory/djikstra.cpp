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

vector<pair<int,int> > adj[100000];
bool visited[100000];
ll dist[100000];

void djikstra(int start){
	//cout<<"ero"<<endl;
	set<pair<int,int>> s;
	s.insert(mp(0,start));
	//visited[start]=true;

	while(!s.empty()){
		pair<int,int> curr= *(s.begin());
		visited[curr.ss]=true;
		s.erase(s.begin());
		//cout<<"ero 2"<<endl;
		for(auto it : adj[curr.ss]){
			//cout<<"ero 3"<<endl;
			if(!visited[it.ff]){
			if(dist[it.ff] > curr.ff+it.ss){
				if(s.find(mp(dist[it.ff],it.ff))!=s.end()){
					s.erase(mp(dist[it.ff],it.ff));
				}
				dist[it.ff]=curr.ff+it.ss;
			}
			s.insert(mp(dist[it.ff],it.ff));
		}
	}
	}
}
int main(){
	fast;
	tc{

		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n+1; ++i)
		{
			adj[i].clear();
		}
		memset(visited,false,sizeof(visited));
		for (int i = 0; i < n+1; ++i)
		{
			dist[i]=INT_MAX;
		}
		int x,y,z;
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y>>z;
			adj[x].pb(mp(y,z));
			adj[y].pb(mp(x,z));
		}
		int start;
		cin>>start;
		dist[start]=0;
		djikstra(start);
		for(int i=1;i<=n;i++){
			if(dist[i]!=0){
				if(dist[i]==INT_MAX){
					cout<<"-1"<<" ";
				}else{
					cout<<dist[i]<<" ";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
