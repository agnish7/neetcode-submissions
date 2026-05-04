# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverse(self, prev, head, tail):
        if head.next == tail:
            prev.next = head
            return head

        newHead = self.reverse(prev, head.next, tail)
        head.next.next = head
        head.next = tail
        return newHead

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        prev, slow, fast = dummy, head, head
        
        while fast:
            ctr = 0
            while fast and ctr < k:
                fast = fast.next
                ctr += 1

            if ctr < k:
                break

            self.reverse(prev, slow, fast)

            prev = slow
            slow = fast

        return dummy.next