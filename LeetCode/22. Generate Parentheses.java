class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ls = new LinkedList<>();
        helper(ls, "(", n);
        return ls;
    }

    public void helper(List<String> ls, String S, int n) {
        if (S.length() == 2 * n && correct(S)) {
            ls.add(S);
        } else if (S.length() < 2 * n)
        {
            helper(ls, S + "(", n);
            helper(ls, S + ")", n);
        }
    }

    public boolean correct(String S) {
        int sum = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == '(')
                ++sum;
            else
                --sum;
            if (sum < 0)
                return false;
        }
        return (sum == 0);
    }
}
