// 解法1 优先队列  大根堆
/* 保存 值和索引的pair 每次堆顶元素就是最大值*/
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         priority_queue<pair<int, int>> q;
//         for (int i = 0; i < k; i ++) {
//             q.emplace(nums[i], i);
//         }
//         ans.push_back(q.top().first); 
//         for (int i = k; i < nums.size(); i ++) {
//             q.emplace(nums[i], i);  // 先加入 否则可能会超时 新来的如果是大元素 下面就不循环了
//             while (q.top().second <= i - k) q.pop();
//             ans.push_back(q.top().first);
//         }

//         return ans;
//     }
// };
// 解法2 分块 + 预处理   后一分组的前缀最大 前一分组的后缀最大 找最大的
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n), rear(n),  ans;

        for (int i = 0; i < n; i ++) {
            if (i % k == 0) pre[i] = nums[i];
            else pre[i] = max(pre[i - 1], nums[i]);
        }
        for (int i = n - 1; i >= 0; i --) {
            if (i % k == 0 || i == n - 1) rear[i] = nums[i];
            else rear[i] = max(rear[i + 1], nums[i]);
        }
        for (int i = 0; i <= n - k; i ++) {
            // i + k - 1 之前 到 i 之后
            ans.push_back(max(pre[i + k - 1], rear[i]));
        }
        return ans;
    }
};