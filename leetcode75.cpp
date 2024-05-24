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


int main()
{
    cout << mergeAlternately("abcd","pq");
    return 0;
}
