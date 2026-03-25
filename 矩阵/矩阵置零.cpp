// 解法1 两个数组保存
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<int> row(m), col(n);

//         for (int i = 0; i < m; i ++) 
//             for (int j = 0; j < n; j ++)
//                 if (matrix[i][j] == 0) row[i] = col[j] = 1;
        
//         for (int i = 0; i < m; i ++)
//             for (int  j = 0; j < n; j ++)
//                 if (row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
//     }
// };

// 解法2  使用第一行 第一列代替解法一的两个额外数组 但是第一行第一列是原本是否有0就查询不出了
// 所以先遍历一遍第一行第一列  将是否有0分别保存在两个变量中
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int row = 0, col = 0, m = matrix.size(), n = matrix[0].size();
//         for (int i = 0; i < m; i ++) if (matrix[i][0] == 0) col = 1; // 第一列
//         for (int i = 0; i < n; i ++) if (matrix[0][i] == 0) row = 1; // 第一行

//         // 记录某行某列是不是有0
//         for (int i = 1; i < m; i ++) 
//             for (int j = 1; j < n; j ++)
//                 if (matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
        
//         // 遍历一遍矩阵 置零操作
//         for (int i = 1; i < m; i ++) 
//             for (int j = 1; j < n; j ++)
//                 if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        
//         // 处理第一行
//         if (row) 
//             for (int i = 0; i < n; i ++) matrix[0][i] = 0;
//         // 处理第一列
//         if (col)
//             for (int i = 0; i < m; i ++) matrix[i][0] = 0;

//     }
// };

// 解法3 对解法2优化 使用matrix[0][0] 记录第一行是否有0  这样就只要使用一个变量
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), col = 0;
        
        for (int i = 0; i < m; i ++) {
            if (matrix[i][0] == 0) col = 1;
            for (int j = 1; j < n; j ++) // 这里遍历了第一行（除了第一个元素）
                // 当i = 0 时 如果为0  那么00会被置为0
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        }
        
        // 倒序遍历置零  如果正序 需要从1开始 则要单独对第一行进行处理
        // 这样倒序后面只需要对列重新排序
        for (int i = m - 1; i >= 0; i --)   // 会处理第一行
            for (int j = 1; j < n; j ++)  // 不会处理第一列
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        
        // 第一列
        if (col) 
            for (int i = 0; i < m; i ++) matrix[i][0] = 0;

    }
};