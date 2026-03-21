// 解法1 双指针  每次移动较小的那一个  因为向中间移动 只能是宽度减小 
// 两个指针指向的数字中较小值∗指针之间的距离  把较大的移出去 最小的不会增加 只可能变得更小
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int a = (r - l) * min(height[l], height[r]);
            if (height[l] <= height[r]) l ++;
            else r --;
            ans = max(ans, a);
        }
        return ans;
    }
};