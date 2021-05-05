/*
 Ques: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/
*/
class Solution
{
public:
    int kadane(vector<int> arr, int n)
    {
        int maxTillNow = 0, maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxTillNow += arr[i];

            if (maxTillNow > maxSum)
                maxSum = maxTillNow;
            if (maxTillNow < 0)
                maxTillNow = 0;
        }

        return maxSum;
    }
    int maxSubarraySumCircular(vector<int> &A)
    {
        int n = A.size();
        int maxKadane = kadane(A, n);

        if (maxKadane < 0)
            return maxKadane;

        int maxWrap = 0;
        for (int i = 0; i < n; i++)
        {
            maxWrap += A[i];
            A[i] = -A[i];
        }

        maxWrap += kadane(A, n);

        return max(maxKadane, maxWrap);
    }
};