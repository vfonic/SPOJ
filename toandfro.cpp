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
#include <string>
#include <vector>

#define inf 1000000000
#define MAXN 201

using namespace std;

int main()
{
    int t;
    
    scanf("%d\n", &t);
    
    while (t != 0) {
        char sentence[MAXN];
        scanf("%s\n", sentence);
        
        int limit = strlen(sentence);
        int chunks = limit / t;
        for (int j = 0; j < t; ++j) {
            bool even = false;
            for (int i = 0; i < chunks; ++i) {
                if (even) {
                    printf("%c", sentence[i*t+(t-j-1)]);
                } else {
                    printf("%c", sentence[i*t+j]);
                }
                even = !even;
            }
        }
        printf("\n");
        
        scanf("%d\n", &t);
    }
    
    return 0;
}
