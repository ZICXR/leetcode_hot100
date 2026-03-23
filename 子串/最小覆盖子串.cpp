// 解法1 滑动窗口
class Solution {
public: // A -> a == 32    A -> z 32 + 26 = 58 ==> 60
    string minWindow(string s, string t) {
        vector<int> req(60), has(60);
        int ans = INT_MAX, l = 0, start = 0, k = 0; // 记录当前满足的字母
        // 这是需要的
        for (char ch : t) {
            if (req[ch - 'A'] == 0) k ++;
            req[ch - 'A'] ++;
        }
        for (int i = 0; i < s.size(); i ++) {
            has[s[i] - 'A'] ++;
            if (has[s[i] - 'A'] == req[s[i] - 'A']) {  // 如果不等于0 说明当前还需要这个
                k --;
            }
            while (k == 0) {
                if (ans > i - l + 1) {
                    ans = i - l + 1;
                    start = l;
                }
                if (has[s[l] - 'A'] == req[s[l] - 'A']) k ++;
                has[s[l] - 'A'] --;
                l ++;
            }
            
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};