#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define inf 1000000000

using namespace std;

int main() {
    string url;
    int pos = 37;
    int sol[6];

    while (true) {
        getline(cin, url);

        if (url.empty()) break;

        int seed = atoi(url.substr(pos, 6).c_str());
        int guess = atoi(url.substr(pos+6, 6).c_str());
        int answer = ((seed%1000)*1000) + (seed/1000) - 8964;
        answer = (answer + 1000000) %1000000;

        int mod = 1000000, div = mod/10;
        int pos = 6;
        while (mod > 1) {
            int nr = (answer%mod)/div;
            sol[--pos] = nr;
            div /= 10; mod /= 10;
        }

        int a = 0, b = 0;
        for (int i = 0; i < 6; ++i) {
            int nr = guess%10;
            if (sol[i] == nr) ++a;
            for (int j = 0; j < 6; ++j) {
                if (i == j) continue;
                if (sol[j] == nr) ++b;
            }
            guess /= 10;
        }

        printf("%dA%dB\n", a, b);
    }

    return 0;
}
