from collections import deque
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x:(x[0],x[1]))
        l, r = -1, -1
        dq = deque()
        for interval in intervals:
            start = interval[0]
            end = interval[1]
            if start > r:
                dq.append([l,r])
                l = start
                r = end
                continue
            if end > r:
                r = end
        dq.popleft()
        ret = list(dq)
        if len(ret) == 0 or ret[-1][0] != l:
            ret.append([l,r])
        return ret