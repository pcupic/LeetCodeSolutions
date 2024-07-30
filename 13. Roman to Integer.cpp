class Solution {
    private HashMap<Character, Integer> hash;

    public Solution() {
        hash = new HashMap<>();
        hash.put('I', 1);
        hash.put('V', 5);
        hash.put('X', 10);
        hash.put('L', 50);
        hash.put('C', 100);
        hash.put('D', 500);
        hash.put('M', 1000);
    }

    public int romanToInt(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int current = hash.get(s.charAt(i));
            if (i + 1 < s.length()) {
                int next = hash.get(s.charAt(i + 1));
                if (current < next) sum -= current;
                else sum += current;  
            } else sum += current;
        }
        return sum;
    }
}

