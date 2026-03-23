// 解法1 滑动窗口 左指针每移动一位 在窗口后面加若干字符 直到存在重复
// 判断以每个字符开头的最大不重复子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ans = 0, r = 0;
        unordered_set<char> se;
        for (int i = 0; i < len; i ++) {
            if (i != 0) se.erase(s[i - 1]);  // 这次判断以s[i]开头 就删除s[i - 1]
            while (r < len && !se.contains(s[r])) {
                se.insert(s[r]);
                r ++;
            }
            ans = max(ans, r - i);
        }
        return ans;
    }
};