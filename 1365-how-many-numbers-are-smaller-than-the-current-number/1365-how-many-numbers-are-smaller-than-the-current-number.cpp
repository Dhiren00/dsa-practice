class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
int n=nums.size();
vector<int>ans;
for(int i=0;i<n;i++)
{
int tempt=0;
for(int j=0;j<n;j++)
{
    if(nums[i]-nums[j]>0)
    {
tempt++;

    }


}
ans.push_back(tempt);
}
return ans;
        
    }
};