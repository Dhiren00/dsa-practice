#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> &cows,int n,int m,int mid )
{
    int cowsp=1;
    int lastposition=cows[0];
    for (int i = 0; i < 5; i++)
    {
        if (cows[i]-lastposition>=mid)
        {cowsp++;

lastposition=cows[i];
            
        }
        if (cowsp==m)
        {
            return true;
        }
        
        
        
    }
    return false;
    
}
int agressiveproblem(vector<int> &cows,int n,int m)
{int st=cows[0];
    int l=cows[0];
    for (int i = 0; i < 5; i++)
    {st=min(st,cows[i]);
        l=max(l,cows[i]);
        
    }
    int mid ;
    int end=l-st;
    int ans;
    while (end>=st)
    {
        mid=st+(end-st)/2;
        if (ispossible(cows,n,m,mid))
        {ans=mid;
            st=mid+1;
            
        }
        else
        {
            end=mid-1;

        }
        
        
    }
    
return ans ;
    
}
int main ()
{
    vector<int>cows={1,2,4,8,9};
    int n=5,c=3;

cout<<agressiveproblem(cows,n,c);
}
