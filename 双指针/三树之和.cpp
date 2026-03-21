// 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || n < 3) return ans;
        for (int i = 0; i < n - 2 && nums[i] <= 0; i ++) {
            // 控制i和上一个数应该不一样  避免重复
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;  // 从两边向中间
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]}); // 还要寻找下一个答案
                    while (j < k && nums[j] == nums[j + 1]) j ++; // 找第一个不同的
                    while (j < k && nums[k] == nums[k - 1]) k --; // 找第一个不同的
                    j ++, k --; // 上面是相同的最后一个元素 这里是不同的第一个元素
                } else if (tmp < 0) j ++;
                else k --;
            }
        }
        return ans;
    }
};