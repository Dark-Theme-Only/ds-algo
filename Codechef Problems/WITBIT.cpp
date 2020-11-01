// WITBIT - Codechef Problem
// Problem: Given a range of integers [L, R] and we have to find the count of such integer i where L≤i≤R,
// and binary representation of i contains the pattern “110” as a substring, where L, R can potentially go up to 10^18.

// EXPLANATION:
// As we need to find the information of substring “110”, whether it is present in the given range we need to convert the given numbers into Binary Strings. 
// We can simply do that in C++ using inbuilt function std::string s = std::bitset< 64 >( number ).to_string().

//Code:

#include <bits/stdc++.h>
using namespace std;

#define LL              long long
#define pb              push_back

vector<LL> num;
LL a, b, k;
LL DP[70][70][2];

LL go(LL pos, LL cnt, int fl){
    
    if(pos == num.size()){
        if(cnt == 3)    return 1;
        return 0;
    }

    int lmt;
    LL &res = DP[pos][cnt][fl];
    if(res != -1)   return res;
    
    res = 0;
    if(fl){
        lmt = 1;
    }else lmt = num[pos];

    for(int i = 0; i <= lmt; i++){
        int nf = fl;
        int ncnt = cnt;
        if(fl == 0 && i < lmt) nf = 1; /// The number is getting smaller at this position
        if(i == 1 && (cnt == 0 || cnt == 1))    ++ncnt;
        if(i == 0 && cnt == 1)  ncnt = 0;
        if(i == 0 && cnt == 2)  ++ncnt;

        res += go(pos+1, ncnt, nf);
    }
    
    return res;
}

LL solve(string s){
    num.clear();
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            num.pb(0);
        }
        else num.pb(1);
    }
    
    memset(DP, -1, sizeof(DP));
    LL res = go(0, 0, 0);
    return res;
    
}

int main () {
    int t;
    cin>>t;
    while(t--){
        cin >> a >> b;
        std::string s = std::bitset< 64 >( a-1 ).to_string(); 
        std::string s1 = std::bitset< 64 >( b ).to_string(); 
        cout<<solve(s1) - solve(s)<<endl;
    }   

}
