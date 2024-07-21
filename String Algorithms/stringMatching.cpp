#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPSArray(const string &pattern) {
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
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0; 
    int j = 0;
    int count = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++; 
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}

int main() {
    string a, b;
    cin >> a >> b;

    int matches = KMPSearch(a,b);
    cout << matches;

    return 0;
}
