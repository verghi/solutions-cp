#include <bits/stdc++.h>

using namespace std;


// solution for the pb https://leetcode.com/problems/the-kth-factor-of-n/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
// kth factor problem
// this solution is of complexity O(n), we can make a solution less than this complexity, a newer solution is on hold, stay tuned
int kthFactor(int n, int k) {
    int res;
    for (int i=1;i<=n;i++)
    {
        if (n%i==0)
        {
            k--;
        }
        if (k==0)
        {
            res=i;
            break;
        }
    }
    if (k>0)
    {
        res=-1;
    }
    return res;
}

// solution for the problem https://leetcode.com/problems/optimal-partition-of-string/submissions/1267013632/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

bool exists_in_string(string s, char c)
{
    bool ok=false;
    int t[26];
    for (int i=0;i<26;i++)
    {
        t[i]=0;
    }
    for (int i=0;i<s.size();i++)
    {
        t[s[i]-'a']++;
    }
    if (t[c-'a']>0)
    {
        ok=true;
    }
    return ok;
}

// optimal partition of string
int partitionString(string s) {
    int t[s.size()];
    t[0]=1;
    string saux (1, s[0]);
    for (int i=1;i<s.size();i++)
    {
        if (exists_in_string(saux,s[i]))
        {
            t[i]=t[i-1]+1;
            saux=string (1, s[i]);
        }
        else
        {
            t[i]=t[i-1];
            saux+=string(1,s[i]);
        }
    }
    return t[s.size()-1];
}


int main()
{
    return 0;
}
