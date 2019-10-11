 //Link to the question: https://www.codechef.com/SNCK1B19/problems/SNCKYEAR

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int val;
    for(int i = 0;i < n; i++) {
        cin>>val;
        if(val == 2010 || val == 2015 || val == 2016 || val == 2017 ||val == 2019) {
            cout<<"HOSTED"<<"\n";
        } else {
            cout<<"NOT HOSTED\n";
        }

    }
    return 0;
}
