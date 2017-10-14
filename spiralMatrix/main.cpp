#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r,c;
        vector<int>result;
        int l=matrix.size();
        if(!l)
        {
            return result;
        }
        r=l;
        c=matrix[0].size();
        l*=c;
        int i=0;
        int row=0,col=0;
        while (i<l)
        {
            for (int j=0;j<c;j++,i++)
            {
                result.push_back(matrix[row][j+col]);
            }
            if (i==l)
            {
                return result;
            }
            for (int j=1;j<r;j++,i++)
            {
                result.push_back(matrix[row+j][c+col-1]);
            }
            if (i==l)
            {
                return result;
            }
            for (int j=1;j<c;j++,i++)
            {
                result.push_back(matrix[row+r-1][col+c-1-j]);
            }
            if (i==l)
            {
                return result;
            }
            for (int j=1;j<r-1;j++,i++)
            {
                result.push_back(matrix[row+r-1-j][col]);
            }
            row++;
            col++;
            r-=2;
            c-=2;
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b;
    vector<int>c1,c2,c3;
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(3);
    c2.push_back(4);
    c2.push_back(5);
    c2.push_back(6);
    c3.push_back(7);
    c3.push_back(8);
    c3.push_back(9);
    b.push_back(c1);
    b.push_back(c2);
    //b.push_back(c3);
    a.spiralOrder(b);
    cout << "Hello world!" << endl;
    return 0;
}
