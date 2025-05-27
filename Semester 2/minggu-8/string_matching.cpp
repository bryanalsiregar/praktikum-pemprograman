#include<iostream>
#include<string>
#include<vector>

using namespace std;

void constructLPS(const string &pat, vector<int> &lps) {
    int len = 0;
    int idx = 1;
    lps[0] = 0;

    int nPat = pat.size();
    while (idx < nPat) {
        if (pat[idx] == pat[len]) {
            len++;
            lps[idx] = len;
            idx++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[idx] = 0;
                idx++;
            }
        }
    }
}

vector<int> KMP(const string &pat, const string &text) {
    int nText = text.size();
    int nPat = pat.size();

    vector<int> result;

    vector<int> lps(nPat);

    constructLPS(pat, lps);

    int i = 0;
    int j = 0;
    while (i < nText) {
        if (pat[j] == text[i]) {
            i++; j++;
        }

        if (j == nPat) {
            result.push_back(i-j);
            j = lps[j - 1];
        }

        else if (i < nText && pat[j] != text[i]) {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    
    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> ans = KMP(pattern, text);

    cout << "Pattern found at indexes: ";
    for (auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}