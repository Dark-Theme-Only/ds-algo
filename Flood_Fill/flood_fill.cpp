#include <bits/stdc++.h>
using namespace std;
int mat[10][10];
int n,m;
int posx[]={0,-1,0,1};
int posy[]={-1,0,1,0};
int visi[10][10]={0};

bool is_possible(int sx,int sy){
    if(sx<0 || sy<0) return false;
    if(sx>=n || sy>=m) return false;
    if(sx==n-1 && sy==m-1) return true;
    if(visi[sx][sy]==1 || mat[sx][sy]==0) return false;
    visi[sx][sy]=1;
    for(int i=0;i<4;i++){
        int nx,ny;
        nx=sx+posx[i];
        ny=sy+posy[i];
        if(is_possible(nx,ny)) return true;
    }
    return false;


}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    if(is_possible(0,0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}