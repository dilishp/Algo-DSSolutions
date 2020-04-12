using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace FindCounterFromQueuePos
{
    class MinimumLengthSubstring
    {
        public static int shortestSubstring(string s)
        {
            ISet<char> set = new HashSet<char>();

            if (s.Length == 0)
                return 0;

            foreach (char c in s)
            {
                set.Add(c);
            }


            int left = 0, right = left + 1;

            int minLength = Int32.MaxValue;

            while (right < s.Length)
            {
                string substr = s.Substring(left, (right - left + 1));

                bool bIsallCharCovered = true;
                foreach (char ch in set)
                {
                    if (!substr.Contains(ch))
                    {
                        bIsallCharCovered = false;
                        break;
                    }
                }

                if (bIsallCharCovered)
                {
                    if (substr.Length < minLength)
                    {
                        minLength = substr.Length;
                    }
                    left++;
                }
                else
                {
                    right++;
                }
            }

            return minLength;
        }
    }
}
