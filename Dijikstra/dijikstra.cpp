#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y,w));
    }
    vector<bool>visit(n+1, false);
    multiset<pair<int,int>>que;
    que.insert(make_pair(0,1));

    vector<long int>dis(n+1, INT_MAX);
    dis[1]=0;
    while(!que.empty()){
        pair<int,int>p = *que.begin();
        que.erase(que.begin());
        int v=p.second;
        if(visit[v]) continue;
        visit[v]=true;
        vector<pair<int,int>>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
            int x=it->first;
            int w=it->second;
            if(dis[v]!=INT_MAX && dis[v]+w<dis[x]){
                dis[x]=dis[v]+w;
                que.insert(make_pair(dis[x],x));
            }
        }
    }
    for(int i=2;i<=n;i++) cout << dis[i] << " ";
    return 0;
}