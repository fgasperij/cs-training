class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int row = 0; row < A.length; ++row) {
            flipAndInvertRow(A[row]);
        }
        
        return A;
    }
    
    private void flipAndInvertRow(int[] row) {
        int left = 0, right = row.length-1, temp;
        while (left <= right) {
            temp = row[left];
            row[left] = invertElement(row[right]);
            row[right] = invertElement(temp);
            ++left;
            --right;
        }
    }
    
    private int invertElement(int a) {
        return (a + 1) % 2;
    }
}
