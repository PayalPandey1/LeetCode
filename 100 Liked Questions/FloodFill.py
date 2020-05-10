class Solution:
    def ff(self, image, curr_row, curr_col, newColor, digit):
        if(curr_row >= len(image) or curr_row < 0 or curr_col < 0 or curr_col >= len(image[0])):
            return 
        if(image[curr_row][curr_col] == newColor):
            return
        print("curr_row : {} curr_col : {}".format(curr_row, curr_col))
        if image[curr_row][curr_col] == digit:
            image[curr_row][curr_col] = newColor 
        else:
            return
        self.ff(image, curr_row + 1, curr_col, newColor, digit)
        self.ff(image, curr_row - 1, curr_col, newColor, digit)
        self.ff(image, curr_row, curr_col + 1, newColor, digit)
        self.ff(image, curr_row, curr_col - 1, newColor, digit)
        
        
    
    
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        digit = image[sr][sc]
        self.ff(image, sr, sc, newColor, digit)
        return image
