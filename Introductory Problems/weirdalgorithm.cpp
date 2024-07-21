#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    #define lli long long int
    vector<lli>weirdalgo(lli n){
        vector<lli>ans;
        ans.push_back(n);
        while(n!=1){
            if(n%2!=0){
                n = 3*n + 1;
            }else{
                n/=2;
            }
            ans.push_back(n);
        }
        return ans;
    }
};

int main(){
    Solution so;

    long long int n;
    cin >> n;

    vector<long long int>ans = so.weirdalgo(n);
    cout << endl;
    for(auto &i : ans){
        cout << i << " ";
    }
    return 0;
}
