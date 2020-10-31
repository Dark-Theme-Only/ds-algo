// 87. Scramble String

// Code:

unordered_map<string, bool> mp;
class Solution {
public:
    bool isScramble(string s1, string s2){
        
        if(s1.length()!= s2.length())
            return false;
        
        if(s1.length() && s2.length() == 0)
            return true;
    
        if(s1.compare(s2) == 0)
            return true;
        
        if(s1.length() <= 1 || s2.length()<=1)
            return false;
        
        string key = s1;           // string key=s1+" "+s2
        key.push_back(' ');
        key.append(s2);
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int n = s1.length();
        
        bool flag = false;
    
        for(int k = 1; k < n; k++){
        
            bool c1 = (isScramble(s1.substr(0, k),s2.substr(n - k, k)) && isScramble(s1.substr(k, n-k), s2.substr(0, n - k)));
            bool c2 = (isScramble(s1.substr(0, k),s2.substr(0, k)) && isScramble(s1.substr(k, n-k), s2.substr(k,n - k)));                                                     
        
              if(c1 || c2){
                 flag = true;
                 break;
              }
        }
         return mp[key] = flag;
    }
};
