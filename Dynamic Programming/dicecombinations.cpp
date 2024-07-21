#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
class Solution{
public:
    ll dynamic(ll n, vector<ll>&dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        ll take=0;
        for(int i=1; i<=6; i++){
            take+=dynamic(n-i, dp)%mod;
        }
        dp[n] = take%mod;
        return take%mod;
    }
};

int main(){
    Solution so;
    ll n;
    cin >> n;
    vector<ll>dp(n+1, -1);

    cout << so.dynamic(n, dp)%mod;
    return 0;
}