class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tempt=0;
        int ans=0;
for(int i=0;i<nums.size();i++)
{
    if(nums[i]==1)
    {
        tempt++;

    }
    else{
        tempt=0;

    }
ans=max(tempt,ans);
}



return ans;
    }
};