#include <bits/stdc++.h>
using namespace std;

const int N = 2509;

int main() {
	int T;
    scanf("%d",&T);
    while (T--) {
        string s, t; cin >> s >> t;
        string r = "";
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '.' && t[i + 1] == '*') r += "(.)(\\1)*", i++;
            else r += t[i];
        }
        puts(regex_match(s, regex(r)) ? "yes" : "no");
    }
}
