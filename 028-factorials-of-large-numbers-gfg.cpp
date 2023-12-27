#include <bits/stdc++.h>
using namespace std;

// Today's Date - 26 Dec 2023
// GFG Question Name - Factorials of large numbers

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> answer(2570, 0);
        answer[0] = 1;
        int size=1;

        for(int i=2; i<=N; ++i)
            multiply(answer, size, i);      

        vector<int> result;
        for(int i = size-1; i>=0; --i)
            result.push_back(answer[i]);
        return result;
    }

    void multiply(vector<int>& nums, int& size, int multiplier)
    {
        int carry =0;

        for(int i=0; i<size; ++i) //traverse thorugh each digit of nums
        {
            int res = nums[i] * multiplier;
            res += carry;
            nums[i] = res%10;
            carry = res/10;
        }

        while(carry>0)
        {
            nums[size++] = carry%10;
            carry/=10;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> vec = solution.factorial(10);
    for(auto ele : vec)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}