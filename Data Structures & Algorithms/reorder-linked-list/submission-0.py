# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead

    def reorderList(self, head: Optional[ListNode]) -> None:

        fast = slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        first, second = head, slow.next
        slow.next = None

        second = self.reverseList(second)

        tail = first

        i = 0

        first = first.next  # skip head since tail already points to it
        while first and second:
            if i % 2 == 0:
                tail.next = second
                tail = tail.next
                second = second.next
            else:
                tail.next = first
                tail = tail.next
                first = first.next
            i += 1


        if first:
            tail.next = first
        
        if second:
            tail.next = second

