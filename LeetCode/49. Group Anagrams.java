class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (String i: strs) {
            char[] chars = i.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            if (!map.containsKey(key)) 
                map.put(key, new LinkedList<String>());
            map.get(key).add(i);
        }
        List<List<String>> list = new LinkedList<>();
        for (Map.Entry<String , List<String>> entry : map.entrySet()){
            list.add(entry.getValue());
        }
        return list;
    }
}
