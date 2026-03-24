// 解法1 排序+双指针
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i ++) {
            if (r < intervals[i][0]) {
                ans.push_back({l ,r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                if (r < intervals[i][1]) r = intervals[i][1];
            }
        }
        ans.push_back({l, r}); // 加入最后一个
        return ans;
    }
};