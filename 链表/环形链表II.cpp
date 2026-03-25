// 解法1 哈希表  空间n
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> s;
//         while (head) {
//             if (s.contains(head)) return head;
//             else s.insert(head);
//             head = head -> next;
//         }
//         return nullptr;
//     }
// };
// 解法2 快慢指针  快慢指针第一次遇到时 快指针从head开始， 慢指针从当前位置开始，均每次走一个 再次遇到时 就是入口节点
// 推理：f,s遇到时 f一定在圈里走了n圈+x个节点了 否则永远不会遇到
// 那也就是 圈外长度 a 圈长度c 节点个数是 a + c
// 假设f,s遇到时 f在圈里面走了n圈+x节点   遇到时 s走了圈内x个节点 s一定不会走多余一整圈 因为f,s差距是1 总会在会在s进入第一圈时碰到（s走一圈 f走两圈 一定会碰到）
// 也就是有 s走的距离 a + x  f 走的距离 a + nc + x
// 快指针走的路径是满指针的两倍 a + nc + x = 2(a + x) ==> a + x = nc
// a = nc - x = nc - (n - t) = (n - 1)c + t // t 是x到入口节点的距离
// 也就是 a 的距离 相等于 从x走 走n圈 再走t
// a 走到入口节点时  环内指针也应该刚好走完t距离
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head -> next) return nullptr;
        ListNode *slow = head, *fast = head;
        do {
            slow = slow -> next;
            fast = fast -> next -> next;
        } while (fast && fast -> next && slow != fast);
        if (!fast || !fast -> next) return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};