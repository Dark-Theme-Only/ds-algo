#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back

int main(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	//cout<<min(n*a,b*(n/m)+a*(n%m));
	if(m>n && b<a*n){
		cout<<b<<endl;
	}else{
		cout<<min(n*a,min((b*(n/m))+(a*(n%m)),b*(n/m+1)))<<endl;
	}
	return 0;
}