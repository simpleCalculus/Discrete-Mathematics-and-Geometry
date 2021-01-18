class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        helper(candidates, target, 0, list, ans);
        return ans;
    }
    
    public void helper(int[] cand, int target, int index, List<Integer> list, List<List<Integer>> ans) {
        int sum = getSum(list);
        for (int i = index; i < cand.length; ++i) {
            if (sum + cand[i] > target)
                return;
            list.add(cand[i]);
            if (sum + cand[i] == target) {
                ans.add(new ArrayList<Integer>(list));
            } else {
                helper(cand, target, i,  list, ans);
            }
            list.remove(list.size() - 1);
        }
    }
    
    public int getSum(List<Integer> list) {
        int sum = 0;
        for (int i : list) {
            sum += i;
        }
        return sum;
    }
}
