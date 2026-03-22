// 解法1 动态规划
// 下标 i 处可以积累的水的高度是  i 两侧最大值的较小的那一个 减去 height[i]
// 所以使用动态规划 找到i 两侧最大最小值
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> leftMax(n), rightMAx(n);  // 分别保存i左右最大值(包括i) 
//         leftMax[0] = height[0], rightMAx[n - 1] = height[n - 1]; // 处理边界
//         for (int i = 1, j = n - 2; i < n && j >= 0; i ++, j --) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//             rightMAx[j] = max(rightMAx[j + 1], height[j]);
//         }
//         // 计算面积
//         int ans = 0;
//         for (int i = 0; i < n; i ++) {
//             int h = min(leftMax[i], rightMAx[i]);
//             h -= height[i];
//             ans += h;
//         }
//         return ans;
//     }
// };



// 解法2 严格单调下降栈 每次遇到大的数字时，弹出大于的数字 并计算面积
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         stack<int> s;
//         int ans = 0;
//         for (int i = 0; i < n; i ++) {
//             if (s.empty() || height[s.top()] > height[i]) {
//                 s.push(i);
//             } else {
//                 // 弹出比height[i]小于的
//                 while (s.size() && height[s.top()] <= height[i]) { 
//                     int tmp = s.top();  // 这是低的中间值
//                     s.pop();
//                     if (!s.size()) break;
//                     int left = s.top(); // 这是中间值左边的第一个比他大的数
//                     int h = min(height[i], height[left]) - height[tmp];
//                     ans += (i - left - 1) * h;
//                 }
//                 s.push(i);  // 弹出比这个小的 原来的还要入栈
//             }
//         }
//         return ans;
//     }
// };

// 解法3 双指针 (对动态规划的空间优化)
// leftMax rightMax 
// 每次移动较小的那个  也就是移动之前 被移动的那一方的最大值 一定小于没有移动的那一方的值的最大值 （可以想象 两个指针走过的序列一定是递增的）
// 如果 height[l] < height[r]  也就是 rightMax 一定大于leftMax
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1, leftMax = 0, rightMax = 0;
        while (l < r) {
            int h = 0;
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (height[l] < height[r]) {
                h = leftMax - height[l];
                l ++;
            } else {
                h = rightMax - height[r];
                r --;
            }
            ans += h;
        }
        return ans;
    }
};

