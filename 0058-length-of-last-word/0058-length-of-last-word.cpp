class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int alpha = 0;
        //   int space=0;
        if (s.size() == 1)
        {
            return 1;
        }
        else
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] != ' ')
                {
                    alpha++;
                }

                else
                {
                    if (alpha == 0)
                        continue;
                    else
                    {
                        break;
                    }
                }
            }
        }

        return alpha;
    }
};
