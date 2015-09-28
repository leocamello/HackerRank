using System;

class Solution
{
    static void Main(string[] args)
    {
        int N = Convert.ToInt32(Console.ReadLine());

        int a, b;

        a = b = int.MaxValue;

        for (int i = 0; i < N; i++)
        {
            string[] ab = Console.ReadLine().Split(' ');

            a = Math.Min(a, Convert.ToInt32(ab[0]));
            b = Math.Min(b, Convert.ToInt32(ab[1]));
        }

        Console.WriteLine(((double)a) * ((double)b));
    }
}
