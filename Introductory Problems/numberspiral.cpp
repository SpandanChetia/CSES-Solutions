#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    ll spiral(ll r, ll c){
        ll ans=0;
        if(r>c){
            if(r&1){
                ans = (r-1)*(r-1) + (c-1) + 1;
            }else{
                ans = (r)*(r) - (c-1);
            }
        }else{
            if(c&1){
                ans = (c)*(c) - (r-1);
            }else{
                ans = (c-1)*(c-1) + (r-1) + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution so;

    int tt;
    cin >> tt;
    vector<ll>ans;
    while(tt--){
        ll r, c;
        cin >> r >> c;
        ans.push_back(so.spiral(r, c));
    }

    for(auto &i : ans){
        cout << i << endl;
    }
    return 0;
}