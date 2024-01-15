#include<bits/stdc++.h>
using namespace std;

// Today's Date - 10 December 2023
// Topic - DP practise

const int N = 1e5 + 5; //state = index
int dp[N];

long long min_cost(int index, vector<int>& values)
{
    if(index<=0)
        return 0;
    if(index==1)
        return abs(values[0]-values[1]);
    if(dp[index]!=-1)
        return dp[index];

    long long int cost1 = min_cost(index-1, values) + abs(values[index-1]-values[index]);
    long long int cost2 = min_cost(index-2, values) + abs(values[index-2]-values[index]);

    long long int ans = min(cost1, cost2);

    return dp[index]=ans;
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