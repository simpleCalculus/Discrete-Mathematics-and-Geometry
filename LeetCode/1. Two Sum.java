class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> myHash = new HashMap<>();
        myHash.put(nums[0], 0);
        for (int i = 1; i < nums.length; ++i) {
            if (myHash.containsKey(target - nums[i])) {
                return new int[] {myHash.get(target - nums[i]), i};
            } else {
                myHash.put(nums[i], i);
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
