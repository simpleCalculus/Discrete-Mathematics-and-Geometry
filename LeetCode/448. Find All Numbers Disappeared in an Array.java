class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        //O(n)
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                int y = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[y - 1] = y;
                i--;
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i)
            if (nums[i] != i + 1)
                list.add(i+1);
        return list;
    }
}
