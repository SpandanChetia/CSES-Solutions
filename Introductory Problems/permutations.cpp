#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int>perm(int n){
        vector<int>ans;

        vector<int>odd, even;

        for(int i=1; i<=n; i++){
            if(i&1){
                odd.push_back(i);
            }else{
                even.push_back(i);
            }
        }

        for(auto &e : even){
            ans.push_back(e);
        }
        for(auto &o : odd){
            ans.push_back(o);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    if(n==3 || n==2){
        cout << "NO SOLUTION";
        return 0;
    }
    Solution so;

    vector<int>ans = so.perm(n);
    for(auto &i : ans){
        cout << i << " ";
    }
    return 0;
}