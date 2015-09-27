using System;

class Solution
{
    static void Main(string[] args)
    {
        string[] LS1S2 = Console.ReadLine().Split(' ');

        int L = Convert.ToInt32(LS1S2[0]);
        int S1 = Convert.ToInt32(LS1S2[1]);
        int S2 = Convert.ToInt32(LS1S2[2]);

        double RS = Math.Abs(S1 - S2);

        double D = Math.Sqrt((L * L) + (L * L));

        int Q = Convert.ToInt32(Console.ReadLine());

        for (int i = 0; i < Q; i++)
        {
            int q = Convert.ToInt32(Console.ReadLine());

            double d = Math.Sqrt(q + q);

            double t = (D - d) / RS;

            Console.WriteLine("{0:R}", t);
        }
    }
}
