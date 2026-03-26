 // 解法1 迭代
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* newhead = new ListNode(0), *p = newhead;
//         newhead -> next = head;
//         // null 1 2 3 4
//         // p   tmp
//         // 
//         while (p && p -> next && p -> next -> next) {
//             ListNode *tmp = p -> next;
//             p -> next = tmp -> next;
//             tmp -> next = p -> next -> next;
//             p -> next -> next = tmp;
//             p = p -> next -> next;
//         }
//         return newhead -> next;
//     }
// };
// 解法2 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) return head;
        // 交换 head 和 head -> next
        ListNode *a = head -> next, *b = head -> next -> next;
        // head -> next 指向 a 后面的排好序的
        head -> next = swapPairs(b);
        // a -> next 指向head
        a -> next = head;
        return a;
    }
};