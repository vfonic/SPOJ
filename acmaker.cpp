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
#define MAXN 151

using namespace std;

int dp[MAXN][MAXN][2];
string abbr, abbreviation;
int abbr_len;
string phrase;
int phrase_len;

int rek(int pos = 0, int abbr_pos = 0, bool took_a_char = false) {
    if (pos == phrase_len) return abbr_pos == abbr_len && took_a_char;
    if (dp[pos][abbr_pos][took_a_char] != -1) return dp[pos][abbr_pos][took_a_char];
    if (phrase[pos] == ' ') {
        if (!took_a_char) return 0;
        else return dp[pos][abbr_pos][took_a_char] = rek(pos+1, abbr_pos, false);
    }
    if (abbr_pos == abbr_len) return dp[pos][abbr_pos][took_a_char] = rek(pos+1, abbr_pos, took_a_char);

    dp[pos][abbr_pos][took_a_char] = rek(pos+1, abbr_pos, took_a_char);
    if (phrase[pos] == abbr[abbr_pos]) {
        dp[pos][abbr_pos][took_a_char] += rek(pos+1, abbr_pos+1, true);
    }

    return dp[pos][abbr_pos][took_a_char];
}

int main() {
    while (true) {
        int t;
        cin >> t;
        if (!t) return 0;

        set<string> insignificant_words;
        
        string insignificant_word;
        for (int qwertz = 0; qwertz < t; ++qwertz) {
            cin >> insignificant_word;
            insignificant_words.insert(insignificant_word);
        }
        
        string line;
        // read all the words
        getline(cin, line); // read \n

        while (true) {
            getline(cin, line);

            istringstream iss(line);

            getline(iss, abbreviation, ' ');
            abbr = abbreviation;
            transform(abbreviation.begin(), abbreviation.end(), abbr.begin(), ::tolower);
            abbr_len = abbr.size();

            vector<string> words;
            string word;
            getline(iss, word, ' ');
            
            if (abbreviation == "LAST" && word == "CASE") break;

            do {
                if (!word.empty() && insignificant_words.find(word) == insignificant_words.end()) {
                    words.push_back(word);
                }
            } while (getline(iss, word, ' '));

            phrase = "";
            for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
                phrase += ' ' + *it;
            }
            phrase_len = phrase.size();

            memset(dp, -1, sizeof dp);
            int sol = rek(1);
            
            if (sol) cout << abbreviation << " can be formed in " << sol << " ways" << endl;
            else cout << abbreviation << " is not a valid abbreviation" << endl;
        }
    }

    return 0;
}
