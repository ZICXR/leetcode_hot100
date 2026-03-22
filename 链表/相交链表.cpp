/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 解法1 哈希表
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> s;
//         ListNode* tmp = headA;
//         while (tmp) {
//             s.insert(tmp);
//             tmp = tmp -> next;
//         }
//         tmp = headB;
//         while (tmp) {
//             if (s.contains(tmp)) return tmp;
//             tmp = tmp ->  next;
//         }
//         return nullptr;
//     }
// };
// 解法2 快慢指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 获取两个链表的长度
        int la = 0, lb = 0;
        ListNode* tmpa = headA, *tmpb = headB;
        while (tmpa) {
            la ++;
            tmpa = tmpa -> next;
        }
        while (tmpb) {
            lb ++;
            tmpb = tmpb -> next;
        }
        int k = la - lb;
        tmpa = headA;
        tmpb = headB;
        if (la < lb) {  // la 一定是长的那一个
            tmpa = headB;
            tmpb = headA;
            k = lb - la;
        }
        while (k --) tmpa = tmpa -> next;
        while (tmpa != tmpb) {
            tmpa = tmpa -> next;
            tmpb = tmpb -> next;
        }
        return tmpa;
    }
};
