/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 解法1 哈希表存储节点
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> s;
//         while (head) {
//             if (s.contains(head)) return true;
//             s.insert(head);
//             head = head -> next;    
//         }
//         return false;
//     }
// };
// 解法2 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *s = head, *f = head -> next;;
        while (s != f && f && f -> next) {
            s = s -> next;
            f = f -> next -> next;
        }
        if (s == f) return true;
        return false;
    }
};