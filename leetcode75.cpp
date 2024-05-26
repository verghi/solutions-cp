#include <bits/stdc++.h>

using namespace std;

// solution for the problem https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75
// 1st pb

string mergeAlternately(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
    int minsize=min(len1,len2);
    string res="";
    for (int i=0;i<minsize;i++)
    {
        res+=word1[i];
        res+=word2[i];
    }
    if (len1>minsize)
    {
        res+=word1.substr(minsize,len1-minsize);
    }
    if (len2>minsize)
    {
        res+=word2.substr(minsize,len2-minsize);
    }
    return res;
}

// solution for the problem https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

bool is_t (string s1, string s2, int len1, int len2)
{
    if (len1%len2==1)
    {
        return false;
    }
    else if (len1==len2)
    {
        if (s1==s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        bool ok=true;
        for (int i=0;i<len1;i=i+len2)
        {
            if (s1.substr(i,len2)!=s2)
            {
                ok=false;
                break;
            }
        }
        return ok;
    }
}

string handle_string(string str1,string str2,int len1, int len2)
{
    string res="";
    for (int i=0;i<len2;i++)
    {
        string auxi=str2.substr(0,len2-i);
        if (is_t(str1,auxi,len1,auxi.size()) && is_t(str2,auxi,len2,auxi.size()))
        {
            res=auxi;
            break;
        }
    }
    return res;
}

string gcdOfStrings(string str1, string str2) {
    int len1=str1.size();
    int len2=str2.size();
    string res;
    if (len1>len2)
    {
        res= handle_string(str1,str2,len1,len2);
    }
    else
    {
        res= handle_string(str2,str1,len2,len1);
    }
    return res;
}
int main()
{
    cout << mergeAlternately("abcd","pq");
    return 0;
}
