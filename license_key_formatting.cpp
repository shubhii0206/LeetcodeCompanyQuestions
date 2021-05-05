class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int chars = 0;
        string c = "", ans = "";
        int i = 0;

        for (char ch : s)
        {
            if (ch != '-')
            {
                chars++;
                if (ch >= 97 && ch <= 122)
                    ch -= 32;
                c += ch;
            }
        }
        if (chars == 0)
            return "";
        int first = chars % k;
        int groups = chars / k;
        int j = i + first;
        int f = first;
        while (first > 0)
        {
            ans += c[i];
            first--;
            i++;
        }
        if (f != 0)
            ans += '-';
        while (groups > 0)
        {
            for (int kk = j; kk < k + j; kk++)
            {
                ans += c[kk];
            }
            j += k;
            ans += '-';
            groups--;
        }

        ans.pop_back();
        return ans;
    }
};