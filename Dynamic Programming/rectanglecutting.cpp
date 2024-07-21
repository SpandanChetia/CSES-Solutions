#include <bits/stdc++.h>
using namespace std;
 
#define ll int
class Solution{
public:
    int mincut(int a, int b){
        vector<vector<int>>dp(a+1, vector<int>(b+1, 1e9));
        for(int i=1; i<=a; i++){
            if(i<=b) dp[i][i]=0;
        }
        for(int j=1; j<=b; j++){
            if(j<=a) dp[j][j]=0;
        }

        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(i==j){
                    continue;
                }
                for(int n=1; n<=j-1; n++){
                    dp[i][j] = min(dp[i][j], 1+dp[i][n]+dp[i][j-n]);
                }

                for(int m=1; m<=i-1; m++){
                    dp[i][j] = min(dp[i][j], 1+dp[m][j]+dp[i-m][j]);
                }
            }
        }
        return dp[a][b];
    }
};
 
int main(){
    Solution so;
    ll a, b;
    cin >> a >> b;
    cout << so.mincut(a, b);
    return 0;
}