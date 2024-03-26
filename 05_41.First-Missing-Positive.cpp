//my logic but work for some test cases
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = 0; 
        for(int num : nums) {
            if(num > maxi) {
                maxi = num; 
            }
        }
        
        vector<int> ans(maxi + 1, -1); 

        for(int num : nums) {
            if(num > 0) {
                ans[num] = num;
            }
        }
        
        for(int i = 1; i <= maxi; ++i) { 
            if(ans[i] == -1)
                return i;
        }
        
        return maxi + 1; 
    }
};

//another solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(0);
        int smallest = n;
        for (int i = 0 ; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 1; i <= n; ++i)
            if (nums[i] != i)
                return i;
        return n + 1;
    }
};