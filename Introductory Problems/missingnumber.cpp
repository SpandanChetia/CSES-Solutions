#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    // O(N) Time + O(1) Space Method
    int missingnum(vector<int>&nums){
        int n = nums.size();
        for(int i=0; i<n; i++){
            int v = abs(nums[i]);
            nums[v-1] *= -1;
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution so;
    
    cout << so.missingnum(nums);
    return 0;
}