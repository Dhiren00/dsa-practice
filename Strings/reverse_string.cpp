
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sat=0;
         int n= s.size();
         int end =n-1;
         while(end>=sat)
         {
            swap(s[sat],s[end]);
            end--;
            sat++;
         }

        
    }
};
