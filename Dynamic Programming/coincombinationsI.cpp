#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
class Solution{
public:
    ll solve(ll n, vector<ll>&coins){
        vector<int>dp(n+1, 0);

        dp[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j]>=0){
                    dp[i] = (dp[i] + dp[i-coins[j]])%mod;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    ll n, amount;
    cin >> n >> amount;
    vector<ll>coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    cout << so.solve(amount, coins);
    return 0;
}