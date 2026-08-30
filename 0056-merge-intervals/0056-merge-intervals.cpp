class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
int n=intervals.size();
        
int st ;
 int end ;
 st=intervals[0][0];
 end=intervals[0][1];


 for(int i=1; i<n;i++)
 {
if(end>=intervals[i][0] && end<=intervals[i][1])
{end=intervals[i][1];}

 else if(end>=intervals[i][0]&& end>=intervals[i][1])
 {
    end=end;
 }
else 
{
ans.push_back({st, end});
    st=intervals[i][0];
    end=intervals[i][1];

}

  

 }


ans.push_back({st,end});

 return ans;
        
    }
};