class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        int[] next = new int[101];
        Arrays.fill(next, Integer.MAX_VALUE);
        for (int i = T.length - 1; i >= 0; --i) {
            int w_ind = Integer.MAX_VALUE;
            for (int t = T[i] + 1; t <= 100; ++t) {
                if (next[t] < w_ind)
                    w_ind = next[t];
            }
            if (w_ind < Integer.MAX_VALUE)
                ans[i] = w_ind - i;
            next[T[i]] = i;
        }
        return ans;
    }
}
/*
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = T.length - 1; i >= 0; --i) {
            while (!stack.empty() && T[i] >= T[stack.peek()]) {
                stack.pop();
            }
            ans[i] = stack.empty() ? 0 : stack.peek() - i;
            stack.push(i);
        }
        return ans;
    }
}
*/
