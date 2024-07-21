#include <bits/stdc++.h>
using namespace std;
 
#define ll int
class Solution{
public:
    int maxpages(ll n, vector<ll>&price, vector<ll>&pages, ll& maxi){
        vector<vector<ll>>dp(n+1, vector<ll>(maxi+1, 0));
        ll ans=0;
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=maxi; j++){
                if(j-price[i-1]>=0){
                    dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-price[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
 
int main(){
    Solution so;
    ll n, maxip;
    cin >> n >> maxip;
    vector<ll>price(n);
 
    for(ll i=0; i<n; i++){
        cin >> price[i];
    }
    vector<ll>pages(n);
    for(ll i=0; i<n; i++){
        cin >> pages[i];
    }
 
    ll ans = so.maxpages(n, price, pages, maxip);
    cout << ans;
    return 0;
}