#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
class Solution{
public:
    int reduce(ll n){
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;

        string s=to_string(n+1);
        string k = "1";
        while(k!=s){
            int num = stoi(k);
            for(int i=0; i<k.size(); i++){
                dp[num] = min(dp[num], 1+dp[num - (k[i]-48)]);
            }
            num++;
            k = to_string(num);
        }
        return dp[n];
    }
};
 
int main(){
    Solution so;
    ll n;
    cin >> n;

    cout << so.reduce(n);
    return 0;
}
