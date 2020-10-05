#include<bits/stdc++.h> 
#define pii pair<int,int>
#define fi first
#define sec second

using namespace std;

// Problem Task - Find the Minimum Spanning Tree of the given
// 				Connected Graph using Kruskal's Algorithm
// In this Algorithm we take lowest weighted edge which does not 
// 				form a cycle in the growing Tree

// Problem link - https://www.spoj.com/problems/MST/

// Time - O(E*log(E)) where E is number of edges



// Find if Edge is already in mst or not
int find_set(int v,int par[]) {
	if(par[v]==v) return v;
	return par[v] = find_set(par[v],par);
}


// Join Edge if not already connected
bool union_set(int a,int b,int par[],int ran[]) {
	a = find_set(a,par);
	b = find_set(b,par);
	if(a==b) return false;
	if(ran[a]<ran[b]) swap(a,b);
	par[b]=a;
	if(ran[a]==ran[b]) ran[a]++;
	return true;
}

int main() {

	int n;		// Number of Vertices	(1 <= n <= 10000)
	cin>>n;

	int e;		// Number of Edges
	cin>>e;
	priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > q;
	for(int i=0;i<e;i++) {
		int a,b,w;	// Edge Input	(1 <= a,b <= n),(1 <= w <= 100000)
		cin>>a>>b>>w;
		q.push({w,{a,b}});	// Min-Heap for edges
	}

	int par[n+1],ran[n+1];		// Disjoint Set Union
	for(int i=1;i<=n;i++) {
		par[i]=i;
		ran[i]=1;
	}

	long long int mst=0;
	while(!q.empty()) {
		pair<int,pii> top = q.top();
		q.pop();
		int a=top.sec.fi,b = top.sec.sec,w = top.fi;
		if(union_set(a,b,par,ran)) {
			mst+=w;
		}
	}
	cout<<mst;
	return 0;
}
