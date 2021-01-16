    public int[] productExceptSelf(int[] nums) {
        if (nums.length <= 1)
            return nums;
        int[] a = new int[nums.length];
        a[0] = nums[0];
        for (int i = 1; i < nums.length; ++i)
            a[i] = nums[i] * a[i-1];        
        int d = nums[nums.length - 1];
        int[] ans = new int[nums.length];
        ans[nums.length - 1] = a[nums.length - 2];
        for (int i = nums.length - 2; i >= 1; --i) {
            ans[i] = a[i-1] * d;
            d *= nums[i];
        }
        ans[0] = d;
        return ans;
    }
