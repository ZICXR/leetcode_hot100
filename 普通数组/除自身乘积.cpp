// 解法1 两个数组 保存左侧和右侧的乘积
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> l(n), r(n), ans;
//         l[0] = 1, r[n - 1] = 1;
//         for (int i = 1; i < n; i ++) l[i] = l[i - 1] * nums[i - 1]; // 注意这里乘的是 i-1
//         for (int i = n - 2; i >= 0; i --) r[i] = r[i + 1] * nums[i + 1];  // 注意这里乘的是 i+1
//         for (int i = 0; i < n; i ++) {
//             ans.push_back(l[i] * r[i]);
//         }
//         return ans;
//     }
// };

// 解法2 空间优化 输出数组不算在空间复杂度内
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums.size());
        ans[n - 1] = 1;
        for (int i = n - 2; i >= 0; i --) ans[i] = ans[i + 1] * nums[i + 1];
        int tmp = 1;
        for (int i = 0; i < n; i ++) {
            ans[i] *= tmp;
            tmp *= nums[i];
        }
        return ans;
    }
};