// 解法1 右上角遍历  大于就向左 小于就向下
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int t = 0, r = n - 1;
//         while (t < m && r >= 0) {
//             if (matrix[t][r] == target) return true;
//             else if (matrix[t][r] < target) t ++;
//             else r --;
//         }
//         return false;
//     }
// };

// 解法2 每行二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i ++) {
            int l = 0, r = n - 1, mid = (l + r) >> 1;
            while (l <= r) {
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) l = mid + 1;
                else r = mid - 1;
                mid = (l + r) >> 1;
            }
        } 
        return false;              
    }
};

// 解法三 直接遍历矩阵