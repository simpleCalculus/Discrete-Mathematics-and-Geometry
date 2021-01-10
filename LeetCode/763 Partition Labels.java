    public List<Integer> partitionLabels(String S) {
        List<Integer> ls = new LinkedList<>();
        if (S.length() == 0)
            return ls;
        int lastIndex = S.lastIndexOf(S.charAt(0));
        int begin = 0;
        for(int i = 0; i < S.length(); ++i) {
            if (i == lastIndex) {
                ls.add(lastIndex - begin + 1);
                begin = i + 1;
                if (i + 1 < S.length())
                    lastIndex = S.lastIndexOf(S.charAt(i + 1));
            } else {
                lastIndex = Math.max(lastIndex, S.lastIndexOf(S.charAt(i)));
            }
        }
        return ls;
    }
