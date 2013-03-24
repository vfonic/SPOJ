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
#define MAXN 100000

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        set<string> winners;
        set<string> loosers;
        char tim1[4], tim2[4];
        int gol1, gol2;
        for (int i = 0; i < 16; ++i) {
            scanf("%s %s %d %d", tim1, tim2, &gol1, &gol2);
            if (gol1 > gol2) {
                char tim3[4];
                strcpy(tim3, tim1);
                strcpy(tim1, tim2);
                strcpy(tim2, tim3);
            }
            set<string>::iterator ex_winner = winners.find(string(tim1));
            if (ex_winner != winners.end()) {
                winners.erase(ex_winner);
            }
            loosers.insert(string(tim1));
            
            set<string>::iterator looser = loosers.find(string(tim2));
            if (looser == loosers.end()) {
                winners.insert(string(tim2));
            }
        }
        printf("%s\n", winners.begin()->c_str());
    }
    
    return 0;
}
