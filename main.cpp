#include <bits/stdc++.h>

using namespace std;

// the solution for "leet code problem" https://leetcode.com/problems/unique-paths/description/ Part 1

int uniquePaths(int m, int n) {
    int t[m][n];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            t[i][j]=0;
        }
    }
    for (int j=0;j<n;j++)
    {
        t[0][j]=1;
    }
    for (int i=1;i<m;i++)
    {
        t[i][0]=1;
    }
    for (int i=1;i<m;i++)
    {
        for (int j=1;j<n;j++)
        {
            t[i][j]=t[i-1][j] + t[i][j-1];
        }
    }
    return t[m-1][n-1];
}

// the solution for "leet code problem" https://leetcode.com/problems/unique-paths-ii/description/ Part 2

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n= obstacleGrid[0].size();
    int t[m][n];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            t[i][j]=0;
        }
    }
    if (obstacleGrid[0][0]==1)
    {
        t[0][0]=0;
    }
    else
    {
        t[0][0]=1;
    }

    for (int j=1;j<n;j++)
    {
        if (obstacleGrid[0][j]==1)
        {
            t[0][j]==0;
        }
        else
        {
            t[0][j]=t[0][j-1];
        }
    }
    for (int i=1;i<m;i++)
    {
        if (obstacleGrid[i][0]==1)
        {
            t[i][0]==0;
        }
        else
        {
            t[i][0]=t[i-1][0];
        }
    }
    for (int i=1;i<m;i++)
    {
        for (int j=1;j<n;j++)
        {
            if (obstacleGrid[i][j]==1)
            {
                t[i][j]==0;
            }
            else
            {
                t[i][j]=t[i-1][j] + t[i][j-1];
            }
        }
    }
    return t[m-1][n-1];
    }

int main()
{
    return 0;
}
