# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def merge2Lists(self, a, b):
        dummy = ListNode(0)
        tail = dummy

        while a and b:
            if a.val <= b.val:
                tail.next = a
                a = a.next
            else:
                tail.next = b
                b = b.next
            tail = tail.next

        if a:
            tail.next = a

        if b:
            tail.next = b

        return dummy.next

    # def printList(self, head):
    #     while(head):
    #         print(head.val, end = " ")
    #         head = head.next
    #     print()
    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        n = len(lists)
        print(lists)

        if n == 0:
            return None
        if n == 1:
            return lists[0]

        left = self.mergeKLists(lists[0:n//2])
        # print(lists[0:n//2])
        # self.printList(left)

        right = self.mergeKLists(lists[n//2: n])
        # print(lists[n//2 + 1: n])
        # self.printList(right)

        return self.merge2Lists(left, right)
