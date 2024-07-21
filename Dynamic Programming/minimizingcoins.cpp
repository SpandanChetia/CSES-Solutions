#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
class Solution{
public:
    ll coin(ll index, ll amount, vector<ll>&coins){
        ll n = coins.size();
        vector<int>dp(amount+1, 1e9);
        dp[0]=0;
 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){  
                if(coins[i-1]<=j){
                    dp[j] = min(dp[j], 1+dp[j-coins[i-1]]);
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
 
    ll v = so.coin(0, a, coins);
 
    if(v==1e9){
        cout << -1;
    }else{
         cout << v;
    }
   
    return 0;
}
