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
#define MAXN 100002

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int limit = n;
    n *= 2;
    
    char niz[MAXN];
    scanf("%s", niz);
    
    int abcd[4] = {0};
    for (int i = 0; i < n; ++i) {
        abcd[niz[i]-'A']++;
    }
    
    int occurences_remaining[4];
    for (int i = 0; i < 4; ++i) {
        occurences_remaining[i] = abcd[i];
    }
    
    char novi_niz[MAXN];
    for (int i = 0; i < n; ++i) {
        int smallest_index = inf, smallest_value = inf;
        for (int j = 0; j < 4; ++j) {
            if (abcd[j] == limit || (i > 0 && novi_niz[i-1] == j+'A') || niz[i] == j+'A') continue;
            
            if (abcd[j] < smallest_value) {
                smallest_value = abcd[j];
                smallest_index = j;
            } else if (abcd[j] == smallest_value
                && (occurences_remaining[j] && occurences_remaining[j] > occurences_remaining[smallest_index])
                ) {
                smallest_value = abcd[j];
                smallest_index = j;
            }
        }
        novi_niz[i] = 'A'+smallest_index;
        occurences_remaining[niz[i]-'A']--;
        abcd[smallest_index]++;
    }
    novi_niz[n] = '\0';

    printf("%s\n", novi_niz);
    
    return 0;
}
