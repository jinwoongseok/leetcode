class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if (self.is_valid_square(board) and self.is_valid_row(board) and self.is_valid_col(board)) is True:
            return True
        return False
            
    def is_valid_row(self, board):
        for row in board:
            if self.is_valid_unit(row) is False:
                return False
        return True
    
    def is_valid_col(self, board):
        for col in zip(*board):
            if self.is_valid_unit(col) is False:
                return False
        return True
    
    def is_valid_square(self, board):
        for i in range(0,9,3):
            for j in range(0,9,3):
                square = [board[r][c] for r in range(i,i+3) for c in range(j,j+3)]
                if self.is_valid_unit(square) is False:
                    return False
        return True
        
    def is_valid_unit(self, target):
        unit = [i for i in target if i != '.']
        if len(unit) == len(set(unit)):
            return True
        return False