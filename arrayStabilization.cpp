//Link to the question: https://codeforces.com/contest/1095/problem/B    
    
    #include<bits/stdc++.h>
    using namespace std;
    int main() {
        long long n;
        cin >> n;
        int A[100000];
        for(int i = 0 ; i < n ; i++) {
            cin >> A[i];
        }
        sort(A,A+n);
        long long s = min(A[n-1]-A[1], A[n-2]-A[0]);
        cout<< s;
        return 0;
    } 
