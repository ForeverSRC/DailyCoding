class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0)
            return -1;
        queue<int> circle;
        for(int i=0;i<n;++i)
            circle.push(i);
        while(circle.size()>1)
        {
            for(int j=0;j<m-1;++j)
            {
                circle.push(circle.front());
                circle.pop();
            }
            circle.pop();
        }
        return circle.front();
    }
};