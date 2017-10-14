#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/maximal-rectangle/description/

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0)
        {
            return 0;
        }
        int re=0;
        int n=matrix[0].size();
        vector<int> rect(n);
        int temp;
        for (int i=0;i<n;i++)
        {
            int j=matrix.size()-1;
            while (0<=j&&matrix[j][i]!='0')
            {
                j--;
            }
            rect[i]=matrix.size()-1-j;
        }
        for (int i=matrix.size()-1;0<=i;i--)
        {
            for (int t=0;t<rect.size();t++)
            {
                cout<<rect[t];
            }
            cout<<endl;
            temp=largestRectangleArea(rect);
            rect.pop_back();
            re=(re<temp)?temp:re;
            if (i==0)
            {
                break;
            }
            for (int k=0;k<n;k++)
            {
                if (rect[k]==0)
                {
                    int j=i-1;
                    while (0<=j&&matrix[j][k]!='0')
                    {
                        j--;
                    }
                    rect[k]=i-j-1;
                }
                else
                {
                    rect[k]=rect[k]-1;
                }
            }
        }
        return re;
    }
};
int main()
{
    vector <vector<char> > ma;
    vector <char> cv;
    cv.push_back('1');
    cv.push_back('0');
    cv.push_back('1');
    cv.push_back('0');
    cv.push_back('0');
    ma.push_back(cv);
    cv.erase(cv.begin(),cv.end());
    cv.push_back('1');
    cv.push_back('0');
    cv.push_back('1');
    cv.push_back('1');
    cv.push_back('1');
    ma.push_back(cv);
    cv.erase(cv.begin(),cv.end());
    cv.push_back('1');
    cv.push_back('1');
    cv.push_back('1');
    cv.push_back('1');
    cv.push_back('1');
    ma.push_back(cv);
    cv.erase(cv.begin(),cv.end());
    cv.push_back('1');
    cv.push_back('0');
    cv.push_back('0');
    cv.push_back('1');
    cv.push_back('0');
    ma.push_back(cv);
    cv.erase(cv.begin(),cv.end());
    Solution a;
    a.maximalRectangle(ma);
    return 0;
}
