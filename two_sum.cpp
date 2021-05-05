class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if (mp.find(n) != mp.end())
            {
                ans = {i, mp[n]};
                return ans;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};