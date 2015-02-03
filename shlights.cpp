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
#define MAXN 100000

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    char lights[MAXN+1];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%s", lights);
        
        int i = 0;
        while (lights[i] != '\0' && lights[i] != 'G') ++i;

        if (lights[i] == '\0') { printf("0\n"); continue; }

        int init_pos = i;
        int num_green = 0;
        i++;
        int end_val = 0, blues = 0;
        while (lights[i] != '\0') {
            while (lights[i] == 'B') {
                ++blues;
                ++i;
            }

            if (lights[i] == '\0') break;

            while (lights[i] == 'G') {
                --blues;
                ++num_green;
                ++i;
            }

            if (lights[i] != '\0' && blues < 0) {
                end_val += blues;
                blues = 0;
            }
        }

        int final_pos = (i - num_green - 1);
        int sol = (final_pos - init_pos) - end_val;
        printf("%d\n", sol);
    }
    
    return 0;
}
