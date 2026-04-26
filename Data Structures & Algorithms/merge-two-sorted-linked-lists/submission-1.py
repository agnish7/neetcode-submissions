# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy

        A, B = list1, list2

        while A and B:
            if A.val <= B.val:
                tail.next = A
                A = A.next
            else:
                tail.next = B
                B = B.next
            tail = tail.next

        tail.next = A if A else B

        return dummy.next

