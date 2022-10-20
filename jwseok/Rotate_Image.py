class Solution:
    def rotate(self, matrix: list) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        def rotate(start: int, end: int):
            if start >= end:
                return
            up = [matrix[start][i] for i in range(start, end+1)]
            down = [matrix[end][i] for i in range(start, end+1)]
            left = [matrix[i][start] for  i in range(start, end+1)]
            right = [matrix[i][end] for i in range(start, end+1)]
            for i in range(len(up)):
                matrix[start][end-i] = left[i]
                matrix[start+i][start] = down[i]
                matrix[end][end-i] = right[i]
                matrix[start+i][end] = up[i]
            rotate(start+1, end-1)
        rotate(0, n-1)
        return matrix