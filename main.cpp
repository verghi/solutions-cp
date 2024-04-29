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


//solution for the leetcode problem https://leetcode.com/problems/roman-to-integer/description/

string make_str(string symbol,int counti)
{
    string res;
    for (int i=0;i<counti;i++)
    {
        res+=symbol;
    }
    return res;
}

string handle_layer (int  layer, int coeff, map<int,string> symbols)
{
    string res="";
    if (layer == 9)
    {
        res=make_str(symbols[9*coeff],1);
    }
    else if (layer == 4)
    {
        res=make_str(symbols[4*coeff],1);
    }
    else if (layer == 5)
    {
        res=make_str(symbols[5*coeff],1);
    }
    else if (layer == 1)
    {
        res= make_str(symbols[coeff],1);
    }
    else
    {
        res=make_str(symbols[5*coeff],layer/5)+make_str(symbols[coeff],layer%5);
    }
    return res;
}

string intToRoman(int num) {
    map <int,string> symbols;
    symbols[1]="I";
    symbols[5]="V";
    symbols[10]="X";
    symbols[50]="L";
    symbols[100]="C";
    symbols[500]="D";
    symbols[1000]="M";
    //exceptions
    symbols[4]="IV";
    symbols[9]="IX";
    symbols[40]="XL";
    symbols[90]="XC";
    symbols[400]="CD";
    symbols[900]="CM";

    //Thousands, we are sure that nums cannot exceed thousands
    int layer1=(num/1000);
    string str1=make_str("M",layer1);

    //hundreds
    int layer2=((num%1000)/100) ;
    string str2=handle_layer(layer2,100,symbols);

    //decimals
    int layer3=(num%100)/10;
    string str3=handle_layer(layer3,10,symbols);

    //digits
    int layer4=(num%10);
    string str4=handle_layer(layer4,1,symbols);

    return str1+str2+str3+str4;
}


// solution for the problem house robber leetcode https://leetcode.com/problems/house-robber/

int rob(vector<int>& nums) {
    int current_max=0;
    if (nums.size()==1)
    {
        current_max=nums[0];
    }
    else if (nums.size()==2)
    {
        current_max= max(nums[0],nums[1]);
    }
    else
    {
        int last_max=nums[0];
        int last_rob_value=nums[0];
        int index_last_rob=0;
        current_max=nums[0];
        if (nums[1]>nums[0])
        {
            current_max=nums[1];
            last_max=nums[0];
            last_rob_value=nums[1];
            index_last_rob=1;
        }
        for (int i=2;i<nums.size();i++)
        {
            if (i-index_last_rob==1)
            {
                if (nums[i]+last_max > current_max)
                {
                    int aux=last_max;
                    last_max=current_max;
                    current_max= nums[i]+aux;
                    index_last_rob=i;
                    last_rob_value=nums[i];
                }
            }
            else
            {
                last_max=current_max;
                current_max+=nums[i];
                last_rob_value=nums[i];
                index_last_rob=i;
            }
        }
    }
    return current_max;
}


// solution for the problem https://leetcode.com/problems/maximum-subarray/description/
int maxSubArray(vector <int>&nums)
{
    int current_max=nums[0];
    int active_sum=nums[0];
    for (int i=1;i<nums.size();i++)
    {
        if (active_sum+nums[i]<=nums[i])
        {
            active_sum=nums[i];
            if (nums[i]>current_max)
            {
                current_max=nums[i];
            }
        }
        else if (active_sum+nums[i]>=current_max)
        {
            current_max=active_sum+nums[i];
            active_sum+=nums[i];
        }
        else if (active_sum+nums[i]>nums[i] && active_sum+nums[i]<current_max)
        {
            active_sum+=nums[i];
        }

    }
    return current_max;
}
// more clean code for the previous solution (refacto conditions)
int maxSubArray_1(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
}

int main()
{
    return 0;
}
