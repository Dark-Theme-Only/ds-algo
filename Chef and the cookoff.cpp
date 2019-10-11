//Link to the qustion: https://www.codechef.com/COOK91/problems/CCOOK


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int A[n][n];
    for(int i = 0; i< n ; i++) {
        for(int j = 0 ; j<5; j++) {
            cin>>A[i][j];
        }
    }

    for(int i = 0; i<n ; i++) {
        int sum = 0;
        for(int  j =0; j< 5 ;j++) {
            sum+=A[i][j];
        }
        
        if(sum == 0) {
            cout<<"Beginner\n";
        } else if(sum == 1) {
            cout<<"Junior Developer\n";
        } else if(sum == 2) {
            cout<<"Middle Developer\n";
        } else if(sum == 3) {
            cout<<"Senior Developer\n";
        } else if(sum == 4) {
            cout<<"Hacker\n";
        } else {
            cout<<"Jeff Dean\n";
        }
    }
    return 0;
} 
