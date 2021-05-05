//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
class Solution
{
public:
    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> arr(7), brr(7), same(7);

        for (int i = 0; i < n; i++)
        {
            arr[A[i]]++;
            brr[B[i]]++;
            if (A[i] == B[i])
                same[A[i]]++;
        }
        int ans = INT_MAX, p = INT_MAX;
        for (int i = 1; i < 7; i++)
        {
            if (arr[i] + brr[i] - same[i] == n)
            {
                p = n - max(arr[i], brr[i]);
                ans = min(p, ans);
            }
        }

        if (ans != INT_MAX)
            return ans;

        return -1;
    }
};