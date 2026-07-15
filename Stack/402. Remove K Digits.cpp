class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string st;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(st.size() && num[i] < st.back() && k)
            {
                st.pop_back();
                k--;
            }
            if(st.size()==0 && num[i]=='0') continue;
            st.push_back(num[i]);
        }
        while(k-- && st.size()) st.pop_back();
    return st.size()?st:"0";
    }
};
