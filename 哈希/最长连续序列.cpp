// 解法1 把数字加入到set  逐个数字判断已改数字为起点的最长连续序列长度是多少
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int n : s) {  // 这里遍历集合即可 否则遍历nums超时
            // 注意这里要判断这个数是不是序列的开头
            if (s.contains(n - 1)) continue;
            int cnt = 0;
            while (s.contains(n)) {
                cnt ++;
                n ++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};