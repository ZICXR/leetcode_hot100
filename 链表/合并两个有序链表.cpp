// 解法1 迭代
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode *nhead = new ListNode(-1), *p = nhead;
//         while (list1 && list2) {
//             ListNode *tmp = nullptr;
//             if (list1 -> val < list2 -> val) {
//                 tmp = list1;
//                 list1 = list1 -> next;
//             } else {
//                 tmp = list2;
//                 list2 = list2 -> next;
//             }
//             tmp -> next = nullptr;
//             p -> next = tmp;
//             p = p -> next;
//         }
//         if (list1) p -> next = list1;
//         else if (list2) p -> next = list2;
//         return nhead -> next;
//     }
// };
// 解法2 递归  那边小就向哪边递归
class Solution {
public:
    ListNode* dfs(ListNode* list1, ListNode *list2) {
        if (!list1 && list2) return list2;  // 一边没了就直接返回另一边
        else if (!list2 && list1) return list1;
        else if (!list1 && !list2) return nullptr;
        ListNode *node = nullptr;
        if (list1 -> val < list2 -> val) {
            node  = list1 -> next;
            list1 -> next = dfs(node, list2);
            return list1;
        } else {
            node  = list2 -> next;
            list2 -> next = dfs(list1, node);
            return list2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return dfs(list1, list2);
    }
};