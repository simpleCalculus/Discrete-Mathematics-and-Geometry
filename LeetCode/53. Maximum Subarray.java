class Solution {
    public int maxSubArray(int[] nums) {
        int[] sum = new int[nums.length + 1];
        sum[0] = nums[0];
        for (int u = 1; u < nums.length; ++u) {
            sum[u] = sum[u - 1] + nums[u];
        }
        int mx = Integer.MIN_VALUE;
        int mn = 0;
        for (int u = 0; u < nums.length; ++u) {
            mx = Math.max(mx, sum[u] - mn);
            mn = Math.min(mn, sum[u]);
        }
        return mx;
    }
}
