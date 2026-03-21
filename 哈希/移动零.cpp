// 解法1 双指针 左指针维护处理完毕的尾部的下一个  右指针指向待处理的头部
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0; // 开始均指向零
        while (r < n) {
            if (nums[r] == 0) {  // r 如果指向0 往后移
                r ++;
            } else {
                swap(nums[l], nums[r]);  // 不是0 就交换
                l ++, r ++;
            }
        }
    }
};