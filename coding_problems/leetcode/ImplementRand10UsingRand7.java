/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10Normal() {
        int generated = 50;
        while (generated > 39) {
            generated = (rand7() - 1) + 7 * (rand7() - 1);
        }
        
        return ((int)generated / 4) + 1;
    }
    
    /*
    left = 1
    possibilities = 49
    digits = 2
    current = 47
    */
    public int rand10() {
        int left = 1;
        while (true) {
            int possibilities = left;
            while (possibilities < 10) {
                possibilities *= 7;
            }
            
            int digitsBase7 = 0;
            int current = 1;
            while (current < possibilities) {
                current *= 7;
                digitsBase7++;
            }
            
            current = 0;
            while (digitsBase7 > 0) {
                current += (rand7() - 1);
                if (digitsBase7 > 1) {
                    current *= 7;    
                }
                digitsBase7--;
            }
            // 0...48            
            if (current < possibilities - (possibilities % 10)) {
                return ((int) current / ((int)possibilities / 10)) + 1;
            }
            
            left = possibilities % 10;
        }
        
    }
}