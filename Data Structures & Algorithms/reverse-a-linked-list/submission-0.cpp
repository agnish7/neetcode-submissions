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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr, *curr = nullptr;
        while(ptr && ptr->next) {
            curr = ptr;
            ptr = ptr->next;
            curr->next = prev;
            prev = curr;
        }
        if(ptr) ptr->next = curr;
        return ptr;
    }
};
