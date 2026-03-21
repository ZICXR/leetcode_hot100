// 解法1  排序  异位词排序之后结果相同
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, int> mp;
//         int cnt = 0;
//         vector<vector<string>> ans;
//         for (int i = 0; i < strs.size(); i ++) {
//             string tmp = strs[i];
//             sort(tmp.begin(), tmp.end());
//             if (mp.count(tmp)) { // 已经存在了
//                 int index = mp[tmp];
//                 ans[index].push_back(strs[i]);
//             } else {
//                 mp[tmp] = cnt;
//                 cnt ++;
//                 vector<string> strtmp;
//                 strtmp.push_back(strs[i]);
//                 ans.push_back(strtmp);
//             }
//         }
//         return ans;
//     }
// };

// 解法1 题解实现
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         vector<vector<string>> ans;
//         for (int i = 0; i < strs.size(); i ++) {
//             string tmp = strs[i];
//             sort(tmp.begin(), tmp.end());
//             mp[tmp].emplace_back(strs[i]);
//         }
//         for (auto& [k, v] : mp) ans.push_back(v);
//         return ans;
//     }
// };

// 解法2 统计字符 
class Solution {
public:
    string get_key(vector<int>& cnt) {
        string key = "";
        for (int i = 0; i < 26; i ++) {
            key += (char)((int)'a' + i) + cnt[i];
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i ++) {
            vector<int> cnt(26);
            string stmp = strs[i];
            for (int j = 0; j < strs[i].size(); j ++) cnt[stmp[j] - 'a'] ++;
            string key = get_key(cnt);
            mp[key].emplace_back(stmp);
        }
        for (auto& [k, v] : mp) ans.push_back(v);
        return ans;
    }
};


