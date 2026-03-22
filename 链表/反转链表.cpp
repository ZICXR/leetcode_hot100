/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 解法1 头插法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* nhead = new ListNode(0);
//         nhead -> next = head;
//         ListNode* tail = head;
//         while (tail) {
//             ListNode* tmp = tail -> next;
//             if (!tmp) return nhead -> next;
//             tail -> next = tmp -> next;
//             tmp -> next = nhead -> next;
//             nhead -> next = tmp;
//         }
//         return nhead -> next;
//     }
// };
 // 解法2 迭代  遍历链表 更改指针
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *tmp = head, * pre = nullptr;
//         while (tmp) {
//            ListNode *ne = tmp -> next;
//            tmp -> next = pre;
//            pre = tmp;
//            tmp = ne;
//         }
//         return pre;
//     }
// };
// 解法3 递归
class Solution {
public:
    ListNode* h = nullptr;
    ListNode* dfs(ListNode* node) {
        if (node == nullptr) return nullptr;
        ListNode* tmp = dfs(node -> next);
        if (!tmp) {
            h = node;
            return node;
        }
        tmp -> next = node;
        node -> next = nullptr; // 这里要断开
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        dfs(head);
        return h;
    }
};