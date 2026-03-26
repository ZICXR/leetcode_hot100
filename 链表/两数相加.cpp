// 解法1 迭代 原地创建
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int t = 0, cnt = 0;
//         ListNode *n1 = l1, *n2 = l2;
//         ListNode *head = new ListNode(-1), *p = head;
//         while (l1 && l2) {
//             cnt ++;  // 交替使用
//             t = l1 -> val + l2 -> val + t;
//             if (cnt % 2) {
//                 n1 -> val = t % 10;
//                 p -> next = n1;
//                 n1 = n1 -> next;
//             } else {
//                 n2 -> val = t % 10;
//                 p -> next = n2;
//                 n2 = n2 -> next;
//             }
//             t /= 10;
            
//             l1 = l1 -> next;
//             l2 = l2 -> next;
//             p = p -> next;
//             p -> next = nullptr;
//         }
//         if (l2) l1 = l2, n1 = n2;
//         while (l1) {
//             t = l1 -> val + t;
//             n1 -> val = t % 10;
//             p -> next = n1;
//             n1 = n1 -> next;
//             p = p -> next;
//             l1 = l1 -> next;
//             p -> next = nullptr;
//             t /= 10;
//         }
//         if (t) {
//             ListNode *last = new ListNode(t);
//             p -> next = last;
//         }
//         return head -> next;
//     }
// };

// 解法2 递归  原地修改
class Solution {
public:
    ListNode * tmp = new ListNode(-1), *p = tmp; // 保存拿下来的节点
    int sum = 0; 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 || l2) {
            if (l1) {
                sum += l1 -> val;
                p -> next = l1;
                l1 = l1 -> next;
                p = p -> next;
                p -> next = nullptr;
            }
            if (l2) {
                sum += l2 -> val;
                p -> next = l2;
                l2 = l2 -> next;
                p = p -> next;
                p -> next = nullptr;
            }
            ListNode *t = tmp -> next;
            tmp -> next = t -> next;
            t -> val = sum % 10;
            sum = sum / 10;
            t -> next = addTwoNumbers(l1, l2);
            return t;
        } else {
            if (!sum) return nullptr;
                tmp -> val = sum;
                tmp -> next = nullptr;
                return tmp;
        }
    }
};
