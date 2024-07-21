#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestrep(string& s){
        char prev = s[0];
        int ans=1;
        int maxi=1;
        for(int i=1; i<s.size(); i++){
            if(prev==s[i]){
                maxi++;
                ans = max(ans, maxi);
            }else{
                maxi=1;
                prev=s[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution so;

    string s;
    cin >> s;

    cout << so.longestrep(s);
    return 0;
}