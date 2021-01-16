class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new LinkedHashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        int[][] a = new int[map.size()][2];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            a[i][0] = entry.getValue();
            a[i][1] = entry.getKey();
            i++;
        }
        Arrays.sort(a, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] > o2[0])
                    return -1;
                else if (o1[0] == o2[0])
                    return  0;
                return 1;
            }
        });
        int[] ans = new int[k];
        for (i = 0; i < k; ++i)
            ans[i] = a[i][1];
        return ans;
    }
}
