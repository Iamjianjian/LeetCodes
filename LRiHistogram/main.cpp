#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//http://blog.csdn.net/yutianzuijin/article/details/52072427

  class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            if (height.size()==0)
            {
                return 0;
            }
            int ret=height[0];
            height.push_back(0);
            int sta[height.size()];
            sta[0]=0;
            int p=1;
            int squa;
            for (int i=1;i<height.size();i++)
            {
                if (height[i]>height[sta[p-1]])
                {
                    sta[p++]=i;
                }
                else
                {
                    while(p>0&&height[sta[p-1]]>height[i])
                    {
                        p--;
                        int a=sta[p];
                        if (p==0)
                        {
                            squa=height[a]*(i);
                            ret=(ret<squa)?squa:ret;
                        }
                        else
                        {
                            squa=height[a]*(i-sta[p-1]-1);
                            ret=(ret<(squa))?(squa):ret;
                        }
                    }
                    sta[p]=i;
                    p++;
                }
            }
            return ret;
    }
};
int main()
{
    Solution a;
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);

    vector<int>b;
    b.push_back(1);
    b.push_back(1);
    cout<<a.largestRectangleArea(arr);
    return 0;
}
