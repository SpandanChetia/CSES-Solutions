#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    bool possible(ll xn){
        if(xn==3){
            return true;
        }
        int n=1;
        int x=0;
        while(x<=xn){
            x = -1 + (n-1)*4;
            if(x==xn){
                return true;
            }
            n++;
        }

        return false;
    }
};

int main(){
    Solution so;

    int n;
    cin >> n;

    if(so.possible(n)){
        cout << "YES" << endl;
        vector<int>f, s;
        if(n==3){
            cout << 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << endl;
            cout << 3;
            return 0;
        }
        f.push_back(1);
        f.push_back(2);
        s.push_back(3);
        int v1=3;
        int v2 =5;
        while(true){
            v1++;
            f.push_back(v1);
            if(v1>=n){
                break;
            }
            s.push_back(v2);
            s.push_back(v2+1);
            v2+=4;
            v1+=3;
            f.push_back(v1);
            if(v1>=n){
                break;
            }
        }
        cout << f.size() << endl;
        for(auto &i : f){
            cout << i << " ";
        }
        cout << endl;
        cout << s.size() << endl;
        for(auto &i : s){
            cout << i << " ";
        }

    }else{
        cout << "NO";
    }

    return 0;
}