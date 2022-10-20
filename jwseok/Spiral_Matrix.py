from collections import deque

class Solution:
    def spiralOrder(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        visited = [[0] * n for _ in range(m)]
        dx = [0,1,0,-1]
        dy = [-1,0,1,0]
        dq = deque()
        dq.append((0, 0, 1))
        answer = [matrix[0][0]]
        visited[0][0] = 1
        while len(dq):
            cur = dq.popleft()
            nx = cur[1] + dx[cur[2]]
            ny = cur[0] + dy[cur[2]]
            if (0 > nx or n <= nx) or (0 > ny or m <= ny) or visited[ny][nx] == 1:
                new_dir = (cur[2] + 1) % 4
                nx = cur[1] + dx[new_dir]
                ny = cur[0] + dy[new_dir]
                if (0 > nx or n <= nx) or (0 > ny or m <= ny) or visited[ny][nx] == 1:
                    continue
                else:
                    visited[ny][nx] = 1
                    dq.append((ny, nx, new_dir))
                    answer.append(matrix[ny][nx])
            else:
                visited[ny][nx] = 1
                dq.append((ny, nx, cur[2]))
                answer.append(matrix[ny][nx])
        return answer

sol =Solution()
sol.spiralOrder([[1,2,3],[4,5,6],[7,8,9]])