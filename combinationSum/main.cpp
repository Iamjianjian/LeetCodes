#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    /*
        without duplicates use element many times
    */
public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target)
        {
            vector<vector<int>> result;
            vector<int> temp;
            helper(result,temp,target,candidates);
            return result;
        }
    void helper(vector <vector<int >>& result,vector<int>&temp,int target,vector<int>&candidates)
    {

        if (target<0)
        {
            return;
        }
        if (target==0)
        {
            result.push_back(temp);
        }
        for (int i=0;i<candidates.size();i++)
        {
            int in;
            if (0<temp.size())
            {
                in=*(temp.end()-1);
                if (candidates[i]<in)
                {
                    continue;
                }
            }
            in=candidates[i];
            temp.push_back(in);
            helper(result,temp,target-in,candidates);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int>a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    a.push_back(7);
    cout <<a.size();
    Solution b;
    b.combinationSum(a,7);

}
