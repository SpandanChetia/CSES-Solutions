#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
class Solution{
public:
    int game(int i, int j, bool flag, vector<ll>&points, vector<vector<ll>>&dp){
        if(i==j){
            return flag ? points[i] : 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take1=-1e9, take2=-1e9;
        int dont1=0, dont2=0;
        if(flag){
            take1 = points[i] + game(i+1, j, false, points, dp);
            take2 = points[j] + game(i, j-1, false, points, dp);
            dp[i][j] = max(take1, take2);
        }
        else{
            dont1 = game(i+1, j, true, points, dp);
            dont2 = game(i, j-1, true, points, dp);
            dp[i][j] = min(dont1, dont2);
        }
        return dp[i][j];
    }
};
 
int main(){
    Solution so;
    ll n;
    cin>>n;
    vector<ll>points(n);
 
    for(int i=0; i<n; i++){
        cin >> points[i];
    }
    vector<vector<ll>>dp(n+1, vector<ll>(n+1, -1));
    cout << so.game(0, n-1, true, points, dp);
    return 0;
}