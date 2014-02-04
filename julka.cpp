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
#define MAXN 101

using namespace std;

int main() {
    for (int qwertz = 0; qwertz < 10; ++qwertz) {
        char a[MAXN], b[MAXN], y[MAXN];
        scanf("%s %s", a, b);
        // printf("\na:%s\nb:%s\n", a, b);
        // if (qwertz == 2) { printf("\na:%s\nb:%s\n", a, b);}
        bool overflow = false;
        int lena = strlen(a), lenb = strlen(b);
        int ptra = lena-1, ptrb = lenb-1;
        int ptry = 0;
        while (ptrb >= 0) {
            y[ptry] = a[ptra] + b[ptrb] + overflow - 2*'0';
            if (y[ptry] >= 10) { y[ptry] -= 10; overflow = true; }
            else overflow = false;
            // if (qwertz == 2) { printf("a %d\n", y[ptry]);}

            --ptra; --ptrb; ++ptry;
        }

        while (ptra >= 0) {
            y[ptry] = a[ptra] + overflow - '0';
            if (y[ptry] >= 10) { y[ptry] -= 10; overflow = true; }
            else overflow = false;
            // if (qwertz == 2) { printf("b %d\n", y[ptry]);}
            --ptra; ++ptry;
        }

        if (overflow) { y[ptry++] = overflow; overflow = false;
        // if (qwertz == 2) {printf("c %d\n", y[ptry-1]);}
        }
        --ptry;
        int leny = ptry;
        bool next_overflow = false;
        while (ptry >= 0) {
            next_overflow = y[ptry] & 1;
            if (overflow) y[ptry] += 10;
            y[ptry] /= 2;

            // if (qwertz == 2) {printf("d %d\n", y[ptry]);}
            overflow = next_overflow;
            --ptry;
        }

        // if (qwertz == 2) {printf("overflow:%d\n", overflow);}
        while (y[leny] == 0) --leny;
        ptry = leny;
        while (ptry >= 0) {
            printf("%d", y[ptry--]);
        }
        printf("\n");

        // if (qwertz == 2) {printf("\n");}
        ptry = 0;
        ptrb = lenb-1;
        while (ptrb >= 0) {
            // if (qwertz == 2) {printf("y[ptry]:%d b[ptrb]:%d\n", y[ptry], b[ptrb]-'0');}
            y[ptry] = y[ptry] - b[ptrb] - overflow + '0';
            if (y[ptry] < 0) { y[ptry] += 10; overflow = true; }
            else overflow = false;
            // if (qwertz == 2) {printf("e %d\n", y[ptry]);}
            --ptrb; ++ptry;
        }
        while (overflow) {
            --y[ptry];
            if (y[ptry] < 0) { y[ptry] += 10; overflow = true; }
            else overflow = false;
            // if (qwertz == 2) {printf("%d\n", y[ptry]);}
            ptry++;
        }
        // if (qwertz == 2) {printf("\n");}

        while (y[leny] == 0) --leny;
        ptry = leny;
        while (ptry >= 0) {
            printf("%d", y[ptry--]);
        }
        printf("\n");
    }
    
    return 0;
}
