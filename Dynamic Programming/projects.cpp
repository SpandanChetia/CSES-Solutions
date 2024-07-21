#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
class Solution{
public:
    ll lowerb(ll i, vector<vector<ll>>&pro){
        ll n = pro.size();
        ll lb =-1;
        ll s=0, e=n-1;
        while(s<=e){
            ll mid = s+(e-s)/2;
            if(pro[mid][1]<pro[i][0]){
                lb=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return lb;
    }
    ll tabulation(vector<vector<ll>>&pro){
        int n = pro.size();
        vector<ll>dp(n+1, 0);
        dp[0] = pro[0][2];
        for(ll i=1; i<n; i++){
            ll lb = lowerb(i, pro);
            ll take = pro[i][2];
            if(lb!=-1){
                take += dp[lb];
            }
            ll exc = dp[i-1];

            dp[i] = max(take, exc);
        }
        return dp[n-1];
    }
};
 
int main(){
    Solution so;
    ll n;
    cin>>n;
    vector<vector<ll>>pro(n, vector<ll>(3));
    for(int i=0; i<n; i++){
        ll s, e, m;
        cin >> s >> e >> m;
        pro[i] = {s, e, m};
    }
    sort(pro.begin(), pro.end());
    cout << so.tabulation(pro);
    return 0;
}