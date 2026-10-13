class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;
        string s;
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() < n) {
                s = strs[i];
                n = strs[i].size();
            }
        }

        string ans;
        bool present = true;
        int i = 0;
        for(i = 0; i < n; i++) {
            char ch = s[i];
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] != s[i]) {
                    present = false;
                    break;
                }
            }

            if(!present) {
                break;
            }
            
        }

        ans = s.substr(0, i);
        return ans;
    }
};