class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        helper(nums, -1, new ArrayList<Integer>(), ans);
        return ans;
    }

    public void helper(int[] nums, int i, List<Integer> ls, List<List<Integer>> ans) {
        ans.add(new ArrayList<Integer>(ls));
        for (int j = i + 1; j < nums.length; ++j) {
            ls.add(nums[j]);
            helper(nums, j, ls, ans);
            ls.remove(ls.size() - 1);
        }
    }
}
