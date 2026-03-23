// 解法1 滑动窗口 维护滑动窗口内的字母的数量
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> pn(26), sn(26), ans;
//         int sl = s.size(), pl = p.size(), r = 0;
//         if (sl < pl) return ans;
//         for (int i = 0; i < pl; i ++) {
//             pn[p[i] - 'a'] ++;
//             sn[s[i] - 'a'] ++;
//             r ++;
//         }
//         for (int i = 1; r <= sl; i ++) {  // 枚举左端点
//             if (pn == sn) ans.push_back(i - 1);
//             if (r == sl) return ans;  // 这里是为了处理最后一个
//             sn[s[i - 1] - 'a'] --;
//             sn[s[r] - 'a'] ++;
//             r ++;
//         }
//         return ans;
//     }
// };

// 解法2 带优化滑窗
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int diff = 0, pl = p.size(), sl = s.size(), r = 0;
        vector<int> cnt(26), ans; // 统计差异
        if (pl > sl) return ans;
        
        for (int i = 0; i < pl; i ++) {
            cnt[s[i] - 'a'] ++;
            cnt[p[i] - 'a'] --;
            r ++;
        }
        for (int i = 0; i < 26; i ++) diff += cnt[i] == 0 ? 0 : 1; // 当前差异
        for (int i = 1; r <= sl; i ++) {
            if (diff == 0) ans.push_back(i - 1);
            if (r == sl) return ans;
            if (cnt[s[i - 1] - 'a'] == 0) { // 原来相等
                diff ++;
            } else if (cnt[s[i - 1] - 'a'] == 1) {  // 原来大于
                diff --;
            } 
            cnt[s[i - 1] - 'a'] --;
            
            if (cnt[s[r] - 'a'] == 0) diff ++;
            else if (cnt[s[r] - 'a'] == -1) diff --;
            cnt[s[r] - 'a'] ++;
            r ++;
        }
        return ans;
    }
};



