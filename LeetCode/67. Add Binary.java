class Solution {
    public String addBinary(String a, String b) {
        if (a.length() < b.length()) {
            String c = a;
            a = b;
            b = c;
        }
        StringBuilder ans = new StringBuilder();
        int[] d = new int[1];
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0; --i, j--) {
            if (j >= 0) {
                ans.insert(0, helper(a.charAt(i), b.charAt(j), d));
            } else {
                ans.insert(0, helper(a.charAt(i), '0', d));
            }
        }
        if (d[0] == 1)
            ans.insert(0, '1');
        return ans.toString();
    }

    private char helper(char a, char b, int[] d) {
        int ans = a - '0' + b - '0' + d[0];
        d[0] = ans / 2;
        return (char)(ans % 2 + '0');
    }
}
