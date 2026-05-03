# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        s, c = 0, 0

        a, b = l1, l2
        while a and b:
            s = a.val + b.val + c % 10
            d = s % 10
            tail.next = ListNode(d)
            c = s // 10
            a = a.next
            b = b.next
            tail = tail.next
        
        while a:
            s = c + a.val
            d = s % 10
            tail.next = ListNode(d)
            c = s // 10
            a = a.next
            tail = tail.next

        while b:
            s = c + b.val
            d = s % 10
            tail.next = ListNode(d)
            c = s // 10
            b = b.next
            tail = tail.next

        print(c)

        if c == 1:
            tail.next = ListNode(c)

        return dummy.next