# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        
        fast = slow = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        first, second = head, slow.next
        slow.next = None

        # Reverse the second list.

        pn, cn = None, second
        while cn:
            tmp = cn
            cn = cn.next
            tmp.next = pn
            pn = tmp

        second = pn

        while first and second:
            tmp = first
            first = first.next
            tmp.next = second
            tmp = second
            second = second.next
            tmp.next = first

            
