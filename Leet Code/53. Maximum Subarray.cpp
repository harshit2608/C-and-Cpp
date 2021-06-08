class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int maxending = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxending = max(nums[i], maxending + nums[i]);
            res = max(res, maxending);
        }
        return res;
    }
};