class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        int[] prefix=new int[nums.length];
        mp.put(0,1);
        prefix[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int count=0;
        for(int i=0;i<prefix.length;i++){
            int ans=prefix[i]%k;
            if(ans<0){
                ans+=k;
            }
            if(mp.containsKey(ans)){
                count+=mp.get(ans);
            }
            mp.put(ans,mp.getOrDefault(ans,0)+1);

        }
        return count;
    }
}