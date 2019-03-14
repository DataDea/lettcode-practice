//
// Created by 杨海 on 2019-03-14.
//

/**
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：

    给定一个链表: 1->2->3->4->5, 和 n = 2.

    当删除了倒数第二个节点后，链表变为 1->2->3->5.
    说明：

    给定的 n 保证是有效的。

    进阶：

    你能尝试使用一趟扫描实现吗
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        if (n < 0) {
            return head;
        }
        if (!head) {
            return head;
        }
        ListNode *cur = head, *font = head, *before = head;
        while (cur->next) {
            int count = 0;
            ListNode *tmp = cur;
            while (tmp->next) {
                if (++count == n) {
                    before->next = tmp->next;
                    return head;
                }
                tmp = tmp->next;
            }
            before = cur;
            cur = cur->next;
        }
        return head;
    }

public:
    void iterate(ListNode *head) {
        ListNode *tmp = head;
        while (tmp) {
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
    }

public:
    Solution() {};
};


ListNode *call() {

    Solution *s = new(Solution);
    int lens;
    cout << "请输入链表的长度" << endl;
    cin >> lens;
    int i = 0;
    ListNode *cur = NULL;
    ListNode *head;
    while (i < lens) {
        cout << "输入节点的值" << endl;
        int val;
        cin >> val;
        if (i == 0) {
            head = new ListNode;
            head->val = val;
            cur = head;
        } else {
            auto *temp = new ListNode;
            temp->val = val;
            cur->next = temp;
            cur = temp;
        }
        i++;
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    s->iterate(head);
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << head->val << endl;
//    int n;
//    cout << "输入删除倒数节点编号" << endl;
//    cin >> n;
//    s->removeNthFromEnd(head, n);
//    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
//    s->iterate(head);
//    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

}