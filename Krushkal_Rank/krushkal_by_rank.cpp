#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int,int>>> adj;
int Max=10001;

int par[10001];
int ran[10001];

int root(int x){
    while(par[x]!=x){
        int y=par[x];
        x=y;
    }
    return par[x];
}
int sn = 5;
void unio(int a, int b){
    int x=root(a);
    int y=root(b);
    if( (ran[x])>(ran[y]) ){
        par[y]=x;
    }
    else if(ran[x]<ran[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        ran[x]++;
    }
}

int kruskal(){
    int ans=0;
    vector<pair<int, pair<int,int>>>::iterator it;
    for(it=adj.begin();it!=adj.end();it++){
        int x=it->second.first;
        int y=it->second.second;
        int w=it->first;
        if(root(x)!=root(y)){
            ans+=w;
            unio(x,y);
        }
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(adj.begin(),adj.end());
    for(int i=0;i<=n;i++){
        par[i]=i;
        ran[i]=0;
    }
    cout << kruskal() << endl;

}
