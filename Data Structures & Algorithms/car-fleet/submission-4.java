class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<speed.length;i++){
            mp.put(position[i],speed[i]);
        }
        Arrays.sort(position);
        double prev=-1;
        int count=0;
        for(int i=position.length-1;i>=0;i--){
                int distance=target-position[i];
                double time=(double)distance/mp.get(position[i]);
                if(time>prev){
                        count++;
                        prev=time;
                }
        }
        return count;
    }
}
