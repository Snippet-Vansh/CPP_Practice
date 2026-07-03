#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search
void KMPsearch(const string &text, const string &pat) {
    int n = text.size();
    int m = pat.size();
    vector<int> lps = buildLPS(pat);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // reset j using lps
        } else if (i < n && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    KMPsearch(text, pattern);

    return 0;
}
