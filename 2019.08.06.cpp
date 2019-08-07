class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len=s.size();
        if(len<=0)
            return s;
        int start=0;
        int end=len-1;
        int maxlen=0;
        for(int i=0;i<len;++i)
        {
            int len1=expand(i,i,s);
            int len2=expand(i,i+1,s);
            int len3=max(len1,len2);
            if(maxlen<len3)
            {
                maxlen=len3;
                start=i-((maxlen-1)>>1);
                end=i+(maxlen>>1);
            }
        }
        return s.substr(start,end-start+1);
    }
    int expand(int start,int end,string& s)
    {
        while(start>=0&&end<s.size()&&s[start]==s[end])
        {
            --start;
            ++end;
        }
        return end-start-1;
    }
};