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
        char ploca[3][4];
        for (int i = 0; i < 3; ++i) {
            scanf("%s", ploca[i]);
        }
        
        int broj_xeva = 0, broj_o = 0;
        int horizontal_sol = 0, vertical_sol = 0;
        bool error = false;
        char sol_char = '\0';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (ploca[i][j] == 'O') ++broj_o;
                if (ploca[i][j] == 'X') ++broj_xeva;
            }
            
            if (strcmp(ploca[i], "OOO") == 0 || strcmp(ploca[i], "XXX") == 0) {
                if (horizontal_sol) { error = true; break; }
                horizontal_sol = i+1;
                if (vertical_sol && sol_char != ploca[i][0]) { error = true; break; }
                sol_char = ploca[i][0];
            }
            
            char stupac[] = {ploca[0][i], ploca[1][i], ploca[2][i], '\0'};
            if (strcmp(stupac, "OOO") == 0 || strcmp(stupac, "XXX") == 0) {
                if (vertical_sol) { error = true; break; }
                vertical_sol = i+1;
                if (horizontal_sol && sol_char != ploca[0][i]) { error = true; break; }
                sol_char = ploca[0][i];
            }
        }
        
        if (broj_o > broj_xeva || broj_xeva - broj_o > 1) error = true;
        
        bool diagonal_sol =
        (ploca[0][0] == ploca[1][1] && ploca[1][1] == ploca[2][2])
        || (ploca[0][2] == ploca[1][1] && ploca[1][1] == ploca[2][0])
        && (ploca[1][1] == 'O' || ploca[1][1] == 'X');
        
        if (!horizontal_sol && !vertical_sol && diagonal_sol) sol_char = ploca[1][1];
        
        if (diagonal_sol) {
            if (horizontal_sol == 1 || horizontal_sol == 3 || vertical_sol == 1 || vertical_sol == 3) error = true;
        }
        
        if (horizontal_sol && vertical_sol && diagonal_sol) error = true;
        if (sol_char == 'X' && broj_o == broj_xeva) error = true;
        if (sol_char == 'O' && broj_xeva != broj_o) error = true;
        
        if (!error) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}
