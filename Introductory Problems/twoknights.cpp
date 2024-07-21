#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    ll total(ll n){
        return (n*n)*(n*n - 1)/2;
    }
    ll knights(ll n){
        return 4*(n-1)*(n-2);
    }
};

int main(){
    Solution so;
    int n;
    cin >> n;
    vector<ll>ans;
    for(int i=1; i<=n; i++){
        ll v = so.total(i) - so.knights(i);
        ans.push_back(v);
    }

    for(auto &i : ans){
        cout << i << endl;
    }
    return 0;
}