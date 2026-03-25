// 解法1 辅助数组  第一行变最后一列  第一行第一个数 变最后一列第一个数
// matrix[i][j] 放到 matrix[j][n - i - 1]

// 解法2 原地旋转  由外向内旋转 
// t, b, l, r
// t, l + i => t + i, r
// t + i, r => b, r - i
// b, r - i => b - i, l
// b - i, l => t, l + i
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         int t = 0, b = m - 1, l = 0, r = n - 1;
//         while (t < b && l < r) {
//             for (int i = 0; l + i < r; i ++) {  // 这里是小于 避免把拍好的破坏
//                 int tmp = matrix[b - i][l];
//                 swap(tmp, matrix[t][l + i]);
//                 swap(tmp, matrix[t + i][r]);
//                 swap(tmp, matrix[b][r - i]);
//                 swap(tmp, matrix[b - i][l]);
//             }
//             t ++, l ++, b --, r --;
//         }
//     }
// };

// 解法3 上下反转 之后按照主对角线反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 上下反转
        for (int i = 0; i < m / 2; i ++) {
            for (int j = 0; j < n; j ++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 对角线反转
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < i; j ++)
                swap(matrix[i][j], matrix[j][i]);

    }
};