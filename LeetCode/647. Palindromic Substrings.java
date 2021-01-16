    public int countSubstrings(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j <= s.length(); ++j) {
                ans += isPolidrom(s, i, j) ? 1 : 0;
            }
        }
        return ans;
    }

    public boolean isPolidrom(String sb, int i, int j) {
        if (i == j)
            return false;
        if (j - i == 1)
            return true;
        for (int k = 0; k < (j - i) / 2; ++k) {
            if (sb.charAt(i + k) != sb.charAt(j - k - 1))
                return false;
        }
        return true;
    }
