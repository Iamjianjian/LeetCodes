#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n==1)
        {
            vector<string> temp;
            temp.push_back("Q");
            result.push_back(temp);
            return result;
        }
        int m=(n-1)/2;
        vector<vector<int> > retemp1;
        vector<vector<int> > retemp2;
        vector<int>temp1;
        vector<int>temp2;
        vector<vector<int>> resulttemp;
        for(int i=0;i<n;i++)
        {
            temp2.push_back(i);
        }
        for (int i=0;i<m;i++)
        {
            temp1.push_back(i);
            retemp1.push_back(temp1);
            temp1.erase(temp1.begin(),temp1.end());
            temp2.erase(temp2.begin()+i,temp2.begin()+i+1);
            retemp2.push_back(temp2);
            temp2.insert(temp2.begin()+i,i);
        }
        while (retemp1.size()!=0)
        {
            temp1=*(retemp1.end()-1);
            retemp1.pop_back();
            temp2=*(retemp2.end()-1);
            retemp2.pop_back();
            for (int i=0;i<temp2.size();i++)
            {
                int col=temp2[i];
                int row=temp1.size();
                bool flag=true;
                for (int j=0;j<temp1.size();j++)
                {
                    if (row-j==col-temp1[j]||row-j==temp1[j]-col)
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag)
                {
                    temp2.erase(temp2.begin()+i,temp2.begin()+i+1);
                    temp1.push_back(col);
                    if (temp1.size()==n)
                    {
                        resulttemp.push_back(temp1);

                    }
                    else
                    {
                        retemp1.push_back(temp1);
                        retemp2.push_back(temp2);
                    }

                }
            }
        }
        vector<string> temp;
        for (int i=0;i<n;i++)
        {

        }
        for (int i=0;i<resulttemp.size();i++)
        {

        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
