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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>&lists, int l, int r) {
        if(l == r) {
            return lists[l];
        }
        if(l+1 == r) {
            return merge2Lists(lists[l], lists[r]);
        }

        int m = l + (r - l)/2;
        ListNode* left = merge(lists, l, m);
        ListNode* right = merge(lists, m + 1, r);

        return merge2Lists(left, right);
    }

    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b) {
            if(a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }
};
