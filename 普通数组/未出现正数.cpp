// 解法1 置换 将nums[i] 放到索引nums[i]-1下面  最后看i-1 == nums[i]  第一个不是的i + 1是答案
// 
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         int idx = 0;
//         while(idx < n) {
//             while (idx < n && nums[idx] == idx + 1) idx ++;
//             if (idx >= n) break;
//             if (nums[idx] <= 0 || nums[idx] > n) {
//                 idx ++;
//                 continue;
//             }
//             if (nums[idx] == nums[nums[idx] - 1]) idx ++;  // 这里主要是避免重复数字
//             else swap(nums[idx], nums[nums[idx] - 1]);
//         }
//         for (int i = 0; i < n; i ++) if(nums[i] < 0 || i != nums[i] - 1) return i + 1;  // nums[i] < 0 这里主要是限制nums[i]-1过小超出范围
//         return n + 1;
//     }
// };
// 解法2 打标记   先把负数设置为大于len的数，然后给索引 nums[i]-1 对应的数设置为负数
// 1 在索引 0   
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }
        for (int i = 0; i < n ; i ++)  {
            int tmp = nums[i] > 0 ? nums[i] : -nums[i];
            if (tmp >= 1 && tmp <= n) nums[tmp - 1] = nums[tmp - 1] > 0 ? -nums[tmp - 1] : nums[tmp - 1];
        }
           
        for (int i = 0; i < n; i ++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
}; 