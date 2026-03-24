// 解法1 动态规划
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> f(nums.size());
//         // 以i结尾的最大子数组和
//         f[0] = nums[0];
//         int maxv = nums[0];
//         for (int i = 1; i < nums.size(); i ++) {
//             if (f[i - 1] > 0) f[i] = f[i - 1] + nums[i];
//             else f[i] = nums[i];
//             maxv = max(maxv, f[i]);
//         }
//         return maxv;
//     }
// };
// 解法二 线段树
/*
[l, r] :lSum 以l为左端点的最大子段和 == max(左子区间lSum, 右子区间lSum + 左子区间iSum)
rSum 以r为右端点的子段和 == max(左子区间rSum + 右子区间iSum, 右子区间rSum)
iSum 区间内的所有数的和  左iSum 右iSum
mSum 表示最大的 == max(左lSum, 右rSum, 左rSum + 右lSum)
*/
// class Solution {
// public:
//     struct Node {
//         int lSum, rSum, iSum, mSum;
//     };
//     Node pushUp(Node lNode, Node rNode) {  // 合并两个区间
//         int lSum = max(lNode.lSum, lNode.iSum + rNode.lSum);
//         int rSum = max(lNode.rSum + rNode.iSum, rNode.rSum);
//         int iSum = lNode.iSum + rNode.iSum;
//         int mSum = max({lNode.mSum, rNode.mSum, lNode.rSum + rNode.lSum});  // 不跨m 跨m
//         return (Node) {lSum, rSum, iSum, mSum};
//     }
//     Node get(vector<int>& nums, int l, int r) {
//         if (l == r) return (Node){nums[l], nums[l], nums[l], nums[l]};
//         int mid = (l + r) >> 1;
//         Node lNode = get(nums, l, mid);  // 分区间
//         Node rNode = get(nums, mid + 1, r);
//         return pushUp(lNode, rNode);  
        
//     }
//     int maxSubArray(vector<int>& nums) {
//         return get(nums, 0, nums.size() - 1).mSum;
//     }
// };
// 解法3 前缀和   永远记录最小的前缀和  与当前前缀和相减 就是最大
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minv = 0, ans = INT_MIN, preSum = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            preSum += nums[i];
            ans = max(ans, preSum - minv);
            minv = min(preSum, minv);
        }
        return ans;
    }
};
