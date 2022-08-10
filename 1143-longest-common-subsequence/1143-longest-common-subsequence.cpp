class Solution 
{
public:
int inor(int i1, int i2, string &text1, string &text2, int n1, int n2, vector<vector<int>>&v)
    {
        if(i1>=n1 || i2>=n2)
        {
            return 0;
        }
    
    if(v[i1][i2]!=-1)
    {
        return v[i1][i2];
    }
    
    if(text1[i1] == text2[i2])
    {
        v[i1][i2] = 1 + inor(i1+1,i2+1,text1,text2,n1,n2,v);
    }
    else
    {
        v[i1][i2] = max(inor(i1+1,i2,text1,text2,n1,n2,v),inor(i1,i2+1,text1,text2,n1,n2,v));
    }
    return v[i1][i2];
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.size();
        int n2 = text2.size();
        //vector<int>t(1002,-1);
        vector<vector<int>>v(n1,vector<int>(n2,-1));
        return inor(0,0,text1,text2,n1,n2,v);
    }
};