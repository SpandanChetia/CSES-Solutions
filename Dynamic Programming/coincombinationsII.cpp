#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
class Solution{
public:
    ll solve(ll amount, vector<ll>&coins){
        vector<int>dp(amount+1, 0);
        
        dp[0] = 1;

        for(int i=1; i<=coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j-coins[i-1]>=0){
                    dp[j] = (dp[j] + dp[j-coins[i-1]])%mod;
                }
            }
        }
        return dp[amount];
    }
};
 
int main(){
    Solution so;
    ll n, a;
    cin >> n>> a;
    vector<ll>coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    ll v = so.solve(a, coins);
 
    cout << v;
   
    return 0;
}
