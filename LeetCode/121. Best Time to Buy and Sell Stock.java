class Solution {
    public int maxProfit(int[] prices) {
        int mn = prices[0];
        int mx = 0;
        for (int i = 0; i < prices.length; ++i) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            if (prices[i] - mn > mx) {
                mx = prices[i] - mn;
            }
        }
        return mx;
    }
}
