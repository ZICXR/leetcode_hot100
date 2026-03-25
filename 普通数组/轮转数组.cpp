// 解法1 开辟新数组 把i位置上的数 放到(i + k) mod n 位置上
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> ans(nums.size());
//         for (int i = 0; i < nums.size(); i ++) {
//             ans[(i + k) % nums.size()] = nums[i];
//         }
//         nums = ans;
//     }
// };

// 解法2 递推交换 i位置上的数 放到(i + k) mod n 保存(i + k) mod n上的值
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size(), tmp = 0;
//         // 要交换所有 需要的次数 lcm(n, k) / k
//         // 这里直接统计啥时候交换次数是n
//         int start = 0, cnt = 0, cur = 0;
//         while (cnt != n) {
//             cur = start;
//             tmp = nums[cur];
//             do {
//                 int des = (cur + k) % n;
//                 swap(tmp, nums[des]);
//                 cnt ++;
//                 cur = des;
//             } while (cur != start);
//             start ++;
//         }
        
//     }
// };

// 解法3 两次逆转
class Solution {
public:
    void reverse(vector<int>& a, int l, int r) {
        while(l < r) swap(a[l ++], a[r --]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};