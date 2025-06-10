/*

## Questions

- Will it always have a redundant connection? What should the program return if it doesn't have one? null? An Optional?

Test cases

Edge cases
- []
- [ (1,2) ]
- [ (1,2), (2,3) ]

- it returns the redundant: [ (1,2), (2,3), (1,3) ] --> (1,3)
- it returns redundant when it's not last: [ (1,2), (2,3), (1,3), (2,4), (4,5) ] -> (1,3)
*/

class Solution {
    class DisjointSets {
        
        final private int[] parentOf;
        final private int[] rankOf;
        
        public DisjointSets(int i) {
            parentOf = new int[i];
            rankOf = new int[i];
            for (int j = 0; j < i; ++j) {
                parentOf[j] = -1;
                rankOf[j] = 0;
            }
        }
        
        public int setOf(int anElement) {
            if (parentOf[anElement] == -1) {
                return anElement;
            }
            
            int representative = setOf(parentOf[anElement]);
            parentOf[anElement] = representative;

            return representative;
        }
        
        public void merge(int aSet, int anotherSet) {
            if (parentOf[aSet] != -1 || parentOf[anotherSet] != -1) {
                throw new IllegalArgumentException("Merge can only be called with representatives of sets");
            }
            
            if (rankOf[aSet] > rankOf[anotherSet]) {
                parentOf[anotherSet] = aSet;
            } else if (rankOf[anotherSet] > rankOf[aSet]) {
                parentOf[aSet] = anotherSet;
            } else {
                parentOf[aSet] = anotherSet;
                rankOf[anotherSet] += 1;
            }
        }
        
    }
    
    
    public int[] findRedundantConnection(int[][] edges) {
        int[] redundant = new int[2];
        DisjointSets dj = new DisjointSets(edges.length);
        for (int i = 0; i < edges.length; ++i) {
            int aSet = dj.setOf(edges[i][0]-1);
            int anotherSet = dj.setOf(edges[i][1]-1);
            if (aSet == anotherSet) {
                redundant = edges[i];
            } else {
                dj.merge(aSet, anotherSet);
            }
        }
        
        return redundant;
    }
}