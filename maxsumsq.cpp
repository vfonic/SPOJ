#include <cstdio>
#include <climits>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    int n;
    for(int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &n);
        
        int maks, cur, x, zeroes = 0, new_max_zeroes = 0;
        cur = maks = INT_MIN;
        bool has_hit_zero = true;
        long long sol = 0, cur_sol = 0, last = 0, last_sol = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            
            if (cur < 0) {
                cur = x;
                last = zeroes = new_max_zeroes = 0;
                has_hit_zero = false;
                last_sol += cur_sol;
                cur_sol = 0;
            } else {
                cur += x;
            }
            
            if (cur == 0) has_hit_zero = true;

            if (x == 0 && cur == 0) ++zeroes;
            if (cur == 0) ++new_max_zeroes;
            
            if (maks < cur) {
                last_sol = 0;
                if (cur == 0) last = cur_sol = 1;
                else last = cur_sol = new_max_zeroes + 1;

                if (cur != 0) zeroes = 0;
                maks = cur;
                has_hit_zero = (maks == 0);
                if (maks == 0) last = 0;
            }
            else if (maks == cur) {
                if (cur == 0) {
                    cur_sol = last + (long long)zeroes*(zeroes+1)/2;
                } else if (has_hit_zero) {
                    last = new_max_zeroes + 1;
                    cur_sol += last;
                } else {
                    if (last)
                        cur_sol += last;
                    else
                        ++cur_sol;
                }
                
                if (cur != 0) zeroes = 0;
                has_hit_zero = false;
            }

            sol = last_sol + cur_sol;
        }

        printf("%d %lld\n", maks, sol);
    }
    
    return 0;
}
