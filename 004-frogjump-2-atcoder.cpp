#include<bits/stdc++.h>
using namespace std;

// Today's Date - 10 Dec 2023
// Topic - DP practise

const int N = 1e5 + 5;
int dp[N];

int min_cost(int index, int k, vector<int>& values)
{
    if(index==0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];

    int cost = INT_MAX;
    for(int i=1; i<=k; i++)
        if(index-i>=0)   
        cost = min(cost, min_cost(index-i, k, values) + abs(values[index]-values[index-i]));
    
    return dp[index] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int stones;
    int k;
    // cout<<"Enter number of stones and number of steps: ";
    cin>>stones>>k;
    vector<int> values;
    for(int i=0; i<stones; i++)
    {
        int temp;
        cin>>temp;
        values.push_back(temp);
    }
    // cout<<"Answer = ";
    cout<<min_cost(stones-1, k, values)<<endl;
}
