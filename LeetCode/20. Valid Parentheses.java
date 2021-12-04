class Solution {
    public boolean isValid(String s) {
        Stack<Character> t = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{')
                t.push(c);
            else if (t.size() == 0)
                return false;
            else if (!helper(t.pop(), c))
                return false;
        }
        return t.size() == 0;
    }
    
    private boolean helper(char a, char b) {
        if ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'))
            return true;
        return false;
    }
}
