#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    // small one in front
    bool static  bigger(Interval i1,Interval i2)
    {
        return i1.start<i2.start;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>result;
        if (intervals.size()==0)
        {
            result.push_back(newInterval);
            return result;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),bigger);
        Interval i(intervals[0].start,intervals[0].end);
        Interval t;
        for(int j=1;j<intervals.size();j++)
        {
            t.end=intervals[j].end;
            t.start=intervals[j].start;
            if (i.end<t.start)
            {
                result.push_back(i);
                i.end=t.end;
                i.start=t.start;
                continue;
            }
            else
            {
                i.end=(i.end<t.end)?t.end:i.end;
            }
        }
        result.push_back(i);

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
