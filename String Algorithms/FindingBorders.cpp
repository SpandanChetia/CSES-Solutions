#include<bits/stdc++.h>
using namespace std;

vector<int> LPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); 
    int length = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string s;
    cin >> s;
    vector<int>lps = LPS(s);
    int i=lps[s.size()-1];
    set<int>ans;
    while(i>0){
        ans.insert(i);
        i = lps[i-1];
    }
    vector<int>res(ans.begin(), ans.end());
    sort(res.begin(), res.end());
    for(auto& m : res){
        cout << m << " ";
    }
    return 0;
}