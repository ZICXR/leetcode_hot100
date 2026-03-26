// 解法1 双指针
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *newhead = new ListNode(0), *l = newhead, *r = newhead;
//         newhead -> next = head;
//         ListNode *tmp = newhead;
//         // null 1 2 3
//         while (n --) {
//             r = r -> next; 
//         }
//         while (r && r -> next) {  
//             r = r -> next;
//             l = l -> next;
//         }
//         if (l -> next) l -> next = l -> next -> next;
//         else l -> next = nullptr;
//         return newhead -> next;
//     }
// };
// 解法2 计算长度
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *newhead = new ListNode(0), *p = newhead;
//         newhead -> next = head;
//         int len = 0;
//         // null 1 2
//         while (p -> next) {
//             p = p -> next;
//             len ++;
//         }
//         int k = len - n;
//         p = newhead;
//         while (k --) { // 找到前面的
//             p = p -> next;
//         }
//         if (p -> next) p -> next = p -> next -> next;
//         else p -> next = nullptr;
//         return newhead -> next;
//     }
// };
// 解法3 栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newhead = new ListNode(0), *tmp = head;
        newhead -> next = head;
        stack<ListNode*> s;
        while(tmp) {
            s.push(tmp);
            tmp = tmp -> next;
        }
        while (n --) { //弹到倒数第n个
            s.pop();
        }
        if (!s.size()) return newhead -> next -> next;
        else s.top() -> next = s.top() -> next -> next;
        return newhead -> next;
    }
};
