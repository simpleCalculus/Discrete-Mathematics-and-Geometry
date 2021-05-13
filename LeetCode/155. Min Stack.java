class MinStack {
    List<Integer> list;
    List<Integer> minValues;
    int minValue = Integer.MAX_VALUE;

    /** initialize your data structure here. */
    public MinStack() {
        list = new ArrayList<>();
        minValues = new ArrayList<>();
    }
    
    public void push(int val) {
        list.add(val);
        minValue = Math.min(minValue, val);
        minValues.add(minValue);
    }
    
    public void pop() {
        if (list.size() == 1) {
            minValue = Integer.MAX_VALUE;
        } else {
            minValue = minValues.get(minValues.size() - 2);
        }

        list.remove(list.size() - 1);
        minValues.remove(minValues.size() - 1);
    }
    
    public int top() {
        return list.get(list.size() - 1);
    }
    
    public int getMin() {
        return minValues.get(list.size() - 1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
