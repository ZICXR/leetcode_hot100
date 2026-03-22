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
 // 解法1 反转后一半 然后逐一比对
// class Solution {
// public:
//     ListNode* reverseList(ListNode* node) {
//         ListNode* tmp = node,* pre = nullptr;
//         while (tmp) {
//             ListNode* t = tmp -> next;
//             tmp -> next = pre;
//             pre = tmp;
//             tmp = t;
//         }
//         return pre;
//     }
//     bool isPalindrome(ListNode* head) {
//         // 找偏左的中间节点
//         ListNode* slow = head, *fast = head;
//         while (fast && fast -> next && fast -> next -> next) {
//             slow = slow -> next;
//             fast = fast -> next -> next;
//         }
//         ListNode* tmp = reverseList(slow -> next);  // 反转后一半
//         slow -> next = nullptr;
//         while(tmp) {
            
//             if (tmp -> val != head -> val) return false;
//             tmp = tmp -> next;
//             head = head -> next;
//         }
//         return true;
//     }
// };

// 解法2 递归
class Solution {
public:
    ListNode* l = nullptr;
    bool dfs(ListNode* node) {
        if (!node || l == node) return true;
        bool res = dfs(node -> next);
        if (l -> val == node -> val) {
            l = l -> next;
            return res;
        } else return false;

    }
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        l = head;
        return dfs(head -> next);
;    }
};
// 解法3 复制到数组中左指针 右指针

