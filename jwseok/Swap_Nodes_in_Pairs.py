# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        cnt = 0
        tmp = ListNode(0,head)
        cur = tmp
        while cur.next:
            if cur.next and cur.next.next and cnt & 1 == 0:
                cur_next = cur.next
                cur_next_next = cur.next.next
                cur_next.next = cur_next_next.next
                cur_next_next.next = cur_next
                cur.next = cur_next_next
            cnt += 1
            cur = cur.next
        return tmp.next