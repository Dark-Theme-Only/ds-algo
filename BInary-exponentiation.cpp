// calculate x to the power of y in O(log2(y)) time which is better than the usual O(y) time


#include <iostream>
using namespace std;
#define p (int)(1e9+7)
int bin_expo(int x,int y) //takes in 2 integer and returns x raised to y mod p(1000000007)
{
    if(y == 1)
        return x;
    if(y == 0)
        return 1;
    if(y%2 == 0)
        return ((bin_expo(x,y/2)%p)*(bin_expo(x,y/2)%p))%p;
    return ((x%p)*(bin_expo(x,y-1)%p));
}

int main()
{
    int x,y;
    cout<<"Enter the numbers x and y :";
    cin>>x>>y;
    cout<<"x to the power of y mod p(1000000007) is "<<bin_expo(x,y);
    return 0;
}
