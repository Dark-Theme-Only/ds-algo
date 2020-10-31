// 115. Distinct Subsequences - Given two strings s and t, return the number of distinct subsequences of s which equals t.

// Solution Code:

class Solution {
public:
    
    map<pair<string, string>, int> m;
    
    // O(n^2) time since the loop inside is executed only once and the parameters the function are also trimmed every time. 
    int f(string s, string t) {
        if (m.count({s, t})) return m[{s, t}];
        if (t == "") return m[{s,t}] = 1;
        int tp = t.size() - 1, sn = s.size(), tn = t.size(), count = 0;
        for (int i = sn - 1; i >= 0; i --) {
            
            // if the characters don't match, can't do anything
            if (tp < 0 || s[i] != t[tp]) continue; 
            
            // if it matches, we have 2 choices, we either consume that character here and match the rest of the string
            // or, we don't
            string t1 = t, s1 = s.substr(0, i);
            t1.pop_back();
            count += (f(s1, t) + f(s1, t1));
            
            // break since the rest of the sub-sequences will be sub-sequences of this sequence
            break;
        }
        return m[{s,t}] = count;
    }
    
    int numDistinct(string s, string t) {
        return f(s, t);
    }
};
