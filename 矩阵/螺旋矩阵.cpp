// 解法1 模拟  一个bool矩阵 记录当前元素是否被 访问过 访问过就转向
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size(), cnt = 0; // cnt 记录遍历个数
//         int target = m * n, row = 0, col = 0, idx = 0; // idx 标记当前使用哪个转向
//         vector<vector<bool>> visited(m, vector<bool>(n));

//         vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         vector<int> ans;
//         while (cnt < target) {
//             ans.push_back(matrix[row][col]);
//             visited[row][col] = true;
//             cnt ++;
//             int nrow = row + dir[idx][0];
//             int ncol = col + dir[idx][1];

//             // 这里是满足情况
//             if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
//                 row = nrow;
//                 col = ncol;
//                 continue;
//             }
//             idx ++;
//             idx %= 4;
//             nrow = row + dir[idx][0];
//             ncol = col + dir[idx][1];
//             // 这里是满足情况
//             if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
//                 row = nrow;
//                 col = ncol;
//                 continue;
//             }
//             else break;
//         }
//         return ans;
//     }
// };

// 解法2 由外向内遍历
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        int l = 0, r = n - 1, t = 0, b = m - 1;
        vector<int> ans;
        while (l <= r && t <= b) {  // 这里是等号
            // 遍历第一行
            for (int i = l; i <= r; i ++) ans.push_back(matrix[t][i]);
            t ++;
            if (t > b) break;
            // 遍历最后一列
            for (int i = t; i <= b; i ++) ans.push_back(matrix[i][r]);
            r --;
            if (l > r) break;
            // 遍历最后一行
            for (int i = r; i >= l; i --) ans.push_back(matrix[b][i]);
            b --;
            if (t > b) break;
            // 遍历第一列
            for (int i = b; i >= t; i --) ans.push_back(matrix[i][l]);
            l ++;
        }
        return ans;
    }
};