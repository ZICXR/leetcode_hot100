// 解法2 暴力
// 解法1 前缀和 + 哈希
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i ++) {
            // 找 pre[i] - pre[j] == k 长度 = i->j-1 
            pre += nums[i];
            ans += mp.count(pre - k) ? mp[pre - k] : 0;
            mp[pre] ++;
        }
        return ans;

    }
};