class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second>1){
                return it.first;
            }
        };
        // int x=0;
        // for(auto it:nums){
        //     x+=it;
        // }
        // int s=nums.size();
        // int n=s*(s-1)/2;
        // return x-n;

        return -1;
    }
};