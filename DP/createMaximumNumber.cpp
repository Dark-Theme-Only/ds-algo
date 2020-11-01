// 321. Create Maximum Number

#define ll int
#define pb push_back

void genMax(ll arr[],ll n, vector<ll> nos[]){
        ll i=1;
        for(ll len=n;len>=1;len--)
        {
            if(len==n){
                for(ll i=1;i<=n;i++)
                    nos[len].pb(arr[i]);
            }
            else
            {
                i=1;
               while(i+1<=n and arr[i]>=arr[i+1])i++;
               n-=1;
               for(ll j=i;j<=n;j++)arr[j]=arr[j+1];
               for(ll j=1;j<=n;j++)nos[len].pb(arr[j]);
            }
        }
    }
    bool greater1(vector<ll> v1,int i,vector<ll> v2,int j)
    {
        while (i < v1.size() && j < v2.size() && v1[i] == v2[j]) {
            i++;
            j++;
        }
        return j == v2.size() || (i < v1.size() && v1[i] > v2[j]);
    }
    vector<int> merge(vector<int>& v1,vector<int> &v2){
        int n=v1.size(),m=v2.size();
        int k=n+m;
        vector<int> ans(k);
        for (int i = 0, j = 0, r = 0; r < k; ++r)
        ans[r] = greater1(v1, i, v2, j) ? v1[i++] : v2[j++];
            return ans;
    }
    bool great(vector<int> &result,vector<int> &temp){
        int k=result.size();
        int i=0;
        while(i<k and result[i]==temp[i])i++;
        if(i<k and result[i] < temp[i])return true;
        return false;
    }
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        int arr1[n+1],arr2[m+1];
        for(int i=0;i<n;i++)
            arr1[i+1]=nums1[i];
        for(int i=0;i<m;i++)
            arr2[i+1]=nums2[i];
        vector<int> v1[n+1];
        vector<int> v2[m+1];
        genMax(arr1,n,v1);
        genMax(arr2,m,v2);
        // for(ll i=n;i>=1;i--)
        // {
        //     cout<<"len= "<<i<<" : ";
        //     for(auto it:v1[i])
        //         cout<<it<<" ";cout<<endl;
        // }
        // for(ll i=m;i>=1;i--)
        // {
        //     cout<<"len= "<<i<<" : ";
        //     for(auto it:v2[i])
        //         cout<<it<<" ";cout<<endl;
        // }
        vector<int> result(k,-1);
        for(int i=0;i<=k;i++)
        {
            // cout<<"i_start= "<<i<<endl;
            // cout<<"result= ";
            // for(auto it:result)cout<<it<<" ";cout<<endl;
            int first=i,second=k-i;
            // cout<<"first= "<<first<<" second= "<<second<<endl;
            if(first>n or second>m)continue;
            if(first==0)
            {
                if(great(result,v2[second]))
                    result=v2[second];
                continue;
            }
            if(second==0)
            {
                if(great(result,v1[first]))
                    result=v1[first];
                continue;
            }
            // cout<<"i_end= "<<i<<endl;
            vector<int> temp=merge(v1[first],v2[second]);
            if(great(result,temp))
                result=temp;
        }
        return result;
    }
};
