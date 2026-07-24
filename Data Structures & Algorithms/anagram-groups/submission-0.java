class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> map=new HashMap<>();
        for(String s:strs){
            char[] arr=s.toCharArray();
            Arrays.sort(arr);
            String ss=new String(arr);
            map.putIfAbsent(ss,new ArrayList<>());
            map.get(ss).add(s);
        }
        return new ArrayList<>(map.values());
    }
}
