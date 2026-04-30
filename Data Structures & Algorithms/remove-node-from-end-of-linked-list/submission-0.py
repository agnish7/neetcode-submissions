# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = slow = head
        prev = None
        i = 0
        while fast:
            fast = fast.next
            if i >= n:
                prev = slow
                slow = slow.next

            i += 1

        if prev == None:
            return head.next

        prev.next = slow.next

        return head

        

        
