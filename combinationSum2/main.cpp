#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    /*
        with duplicates each element only be used once
    */
public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            vector<vector<int>> result;
            vector<int> temp;
            vector<int> ca=candidates;
            sort(ca.begin(),ca.end());
            helper(result,temp,target,ca,ca.begin());
            return result;
        }
    void helper(vector <vector<int >>& result,vector<int>&temp,int target,vector<int>&candidates,vector<int>::iterator in)
    {
        vector<int>::iterator in2=find_ndireff(candidates,in);
        int l=in2-in;
        if (l==0)
        {
            return;
        }
        int cou=0;
        while (cou<=l&&0<target)
        {
            for (int i=0;i<cou;i++)
            {
                temp.push_back(*in);
            }
            helper(result,temp,target,candidates,in2);
            for (int i=0;i<cou;i++)
            {
                temp.pop_back();
            }
            cou++;
            target-=*in;
            if (target==0&&cou<=l)
            {
                for (int i=0;i<cou;i++)
                {
                    temp.push_back(*in);
                }
                result.push_back(temp);
                for (int i=0;i<cou;i++)
                {
                    temp.pop_back();
                }
            }
        }
    }
    vector<int>::iterator find_ndireff(vector<int>&candi,vector<int>::iterator in)
    {
        int temp=*in;
        while (in<candi.end()&&temp==*in)
        {
            in++;
        }
        return in;
    }
};

int main()
{
    vector<int>a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    a.push_back(7);
    vector<int>::iterator aa=a.begin();
    vector<int>::iterator bb=a.end();
    cout <<bb-aa;
    cout <<a.size();
    Solution b;
    b.combinationSum2(a,7);

}
