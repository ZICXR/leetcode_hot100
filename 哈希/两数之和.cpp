// 解法1 hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(target - nums[i])) {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            } else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};

// 解法2 暴力枚举
