#include <iostream>

using namespace std;
//https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        vector<int> canReach;
        for(int i=0;i<nums.size();i++)
        {
            canReach.push_back(i+nums[i]);
        }
        int i=0;
        while (i<=reach&&reach<canReach.size())
        {
            if (reach<canReach[i])
            {
                reach=canReach[i];
            }
            i++;
        }
        if (canReach.size()-1<=reach)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
