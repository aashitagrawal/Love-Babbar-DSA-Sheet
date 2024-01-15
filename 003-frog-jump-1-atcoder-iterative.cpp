#include<bits/stdc++.h>
using namespace std;

// Today's Date - 10 Dec 2023
// Topic - DP practise

const int N = 1e5 + 5;
int dp[N];

int min_cost(int index, vector<int> values)
{
    dp[0] = 0;
    dp[1] = abs(values[1]-values[0]);

    for(int i=2; i<=index; i++)
    {
        int cost1 = dp[i-1] + abs(values[i]-values[i-1]);
        int cost2 = dp[i-2] + abs(values[i]-values[i-2]);

        dp[i] = min(cost1, cost2);
    }

    return dp[index];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int stones;
    // cout<<"Enter number of stones : ";
    cin>>stones;
    vector<int> values;
    for(int i=0; i<stones; i++)
    {
        int temp;
        cin>>temp;
        values.push_back(temp);
    }
    // cout<<endl<<"Answer = ";
    cout<<min_cost(stones-1, values)<<endl;
}