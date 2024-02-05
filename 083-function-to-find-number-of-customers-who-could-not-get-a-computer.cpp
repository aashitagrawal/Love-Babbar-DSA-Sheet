#include <bits/stdc++.h>
using namespace std;

// Today's Date - 4 Feb 2024
// Question Name - Function to find Number of customers who could not get a computer

class Solution
{
public:
    int unServedCustomers(int n, string s)
    {
        int answer = 0;
        unordered_map<char, bool> hashmap;
        for (auto ele : s)
        {
            if (hashmap.count(ele) == 0) // entering
            {
                if (n != 0)
                {
                    hashmap[ele] = true;
                    n--;
                }
                else if (n == 0)
                    hashmap[ele] = false;
            }
            else // exiting
            {
                if (hashmap[ele] == true)
                    n++;
                else
                    answer++;
            }
        }
        return answer;
    }
};

int main()
{
    Solution solution;
    cout << solution.unServedCustomers(2, "ABBAJJKZKZ") << endl;
    cout << solution.unServedCustomers(3, "GACCBDDBAGEE") << endl;
    cout << solution.unServedCustomers(3, "GACCBGDDBAEE") << endl;
    cout << solution.unServedCustomers(1, "ABCBCA") << endl;
    cout << solution.unServedCustomers(1, "ABCBCADEED") << endl;
    return 0;
}
