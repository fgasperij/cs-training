class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int left = -1, right = -1, acum = 0;
        
        for (int i = 0; i < timeSeries.length; ++i) {
            int timePoint = timeSeries[i];
            if (timePoint <= right) {
                right = timePoint + duration;
            } else {
                acum += right - left;
                left = timePoint;
                right = left + duration;
            }
        }
        
        acum += right - left;
        
        return acum;
    }
}
