# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        ptr, tail= dummy, head
        i = 0
        while tail:
            tail = tail.next
            if i >= n:
                ptr = ptr.next
            i += 1

        ptr.next = ptr.next.next

        return dummy.next