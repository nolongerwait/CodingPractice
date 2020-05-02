class Solution {
    public int countCharacters(String[] words, String chars) {
        HashMap<Character,Integer> a = new HashMap<>();

        int sum=0;

        for(char c:chars.toCharArray()) {
            if(a.containsKey(c)) a.put(c, a.get(c) + 1);
            else a.put(c, 1);
        }

        for(String word:words) {
            boolean flag = true;

            HashMap<Character, Integer> b = new HashMap<>();

            for(char c:word.toCharArray()) {
                if(b.containsKey(c)) b.put(c, b.get(c) + 1);
                else b.put(c, 1);

                if(a.containsKey(c)) {
                    if(a.get(c) < b.get(c)) {
                        flag = false;
                        break;
                    }
                }
                else {
                    flag =false;
                    break;
                }
            }
            
            if(flag) sum += word.length();
        }

        return sum;        
    }
}