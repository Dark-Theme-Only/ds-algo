#include<bits/stdc++.h>
using namespace std;

int binSearch(vector<int>A,int ele)
{
    int l=0;
    int r=A.size()-1;

    while(l<=r)
    {
        int m=(l+r)/2;

        if(A[m]==ele)
        return m;

        if(A[m]<ele)
        l=m+1;

        else
        r=m-1;
    }

    return -1;
}
int main()
{


    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;

    vector<int>A(n);
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    int ele;
    cout<<"enter the element you wish to search"<<endl;
    cin>>ele;


    int result=binSearch(A,ele);

    if(result!=-1)
    cout<<"Element found at position "<<result<<endl;
    else
    cout<<"Element not Found"<<endl;

}
