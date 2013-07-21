#include <cstdio>
#include <string>
#include <iostream>

#define MAXN 1000010
#define p 1000007

using namespace std;

int H[MAXN];
int r_H[MAXN];
int P[MAXN];

int hash(int idx, int len) {
    return H[idx+len-1] - H[idx-1]*P[len];
}

int r_hash(int idx, int len) {
    if (idx-len > 0)
        return r_H[idx] - r_H[idx-len];
    else return r_H[idx];
}

int main() {
    cin.sync_with_stdio(false);
    int t;
    string ary;
    cin >> t;
    getline(cin, ary);

    for (int qwertz = 0; qwertz < t; ++qwertz) {
        getline(cin, ary);
        if (ary.size() == 0) { printf("YES\n"); continue; }
        if (ary[ary.size()-1] == '\r') ary.erase(ary.size()-1);
        P[0] = 1;
        H[0] = ary[0];
        r_H[0] = ary[0];
        for (int i = 1; i < (int)ary.size(); ++i) {
            H[i] = H[i-1]*p + ary[i];
            P[i] = P[i-1]*p;
            r_H[i] = P[i]*ary[i] + r_H[i-1];
        }
        
        if (ary.size() % 2) { printf("NO\n"); continue; }

        int begin = 0;
        for (int i = 1; i < (int)ary.size(); ++i) {
            if (ary[i] == ary[i-1]) {
                if (i + i-begin > (int)ary.size()) break;
                if (hash(i, i-begin)*P[begin] == r_hash(i-1, i-begin)) {
                    begin = i = i + i-begin;
                }
            }
        }
        if (begin == (int)ary.size()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
