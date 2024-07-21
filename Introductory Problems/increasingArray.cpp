#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    #define ll long long
    ll minimummoves(vector<int>&nums){
        ll ans=0;
        int n = nums.size();
        ll prev=nums[0];
        for(int i=1; i<n; i++){
            if(prev>nums[i]){
                int d = prev - nums[i]; 
                ans += d;
                prev = nums[i]+d;
            }else{
                prev = nums[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution so;

    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << so.minimummoves(nums);
    return 0;
}

