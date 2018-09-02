class Solution {
    public int findCircleNum(int[][] M) {
        boolean[] visited = new boolean[M.length];
        int friendCircles = 0;
        for (int i = 0; i < M.length; ++i) {
            if (!visited[i]) {
                traverseFrom(i, M, visited);
                friendCircles++;
            }
        }
        
        return friendCircles;
    }
    
    private void traverseFrom(int startingNode, int[][] M, boolean[] visited) {
        Stack<Integer> nextNodes = new Stack();
        visited[startingNode] = true;
        nextNodes.push(startingNode);
        while (!nextNodes.empty()) {
            int next = nextNodes.pop();
            for (int i = 0; i < M.length; ++i) {
                if (!visited[i] && M[next][i] == 1) {
                    visited[i] = true;
                    nextNodes.push(i);
                }
            }
        }
    }
}