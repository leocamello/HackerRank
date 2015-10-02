using System;

class Solution
{
    private static readonly int MAX_N = 100;

    static double SmallerPartWeight(int n, int[] x, int[] y, int[] v)
    {
        double minDiff = double.MaxValue;
        double smallerPartWeight = 0.0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double onePartWeight = 0.0;
                    double otherPartWeight = 0.0;

                    if (y[i] == y[j])
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (k != i && k != j)
                            {
                                if (y[k] > y[i])
                                {
                                    onePartWeight += v[k];
                                }
                                else
                                {
                                    otherPartWeight += v[k];
                                }
                            }
                        }
                    }
                    else
                    {
                        double a = (x[i] - x[j]) / (y[i] - y[j]);
                        double b = y[i] - a * x[i];

                        for (int k = 0; k < n; k++)
                        {
                            if (k != i && k != j)
                            {
                                if (y[k] > a * x[k] + b)
                                {
                                    onePartWeight += v[k];
                                }
                                else
                                {
                                    otherPartWeight += v[k];
                                }
                            }
                        }
                    }

                    double diffA, diffB;
                    diffA = Math.Abs((onePartWeight + v[i]) - (otherPartWeight + v[j]));
                    diffB = Math.Abs((onePartWeight + v[j]) - (otherPartWeight + v[i]));

                    if (diffA < diffB)
                    {
                        if (diffA < minDiff)
                        {
                            minDiff = diffA;
                            smallerPartWeight = (onePartWeight + v[i]) < (otherPartWeight + v[j]) ? (onePartWeight + v[i]) : (otherPartWeight + v[j]);
                        }
                    }
                    else
                    {
                        if (diffB < minDiff)
                        {
                            minDiff = diffB;
                            smallerPartWeight = (onePartWeight + v[j]) < (otherPartWeight + v[i]) ? (onePartWeight + v[j]) : (otherPartWeight + v[i]);
                        }
                    }
                }
            }
        }

        return smallerPartWeight;
    }

    static void Main(string[] args)
    {
        int N = Convert.ToInt32(Console.ReadLine());

        int[] x = new int[MAX_N];
        int[] y = new int[MAX_N];
        int[] v = new int[MAX_N];

        for (int i = 0; i < N; i++)
        {
            string[] xyv = Console.ReadLine().Split(' ');

            x[i] = Convert.ToInt32(xyv[0]);
            y[i] = Convert.ToInt32(xyv[1]);
            v[i] = Convert.ToInt32(xyv[2]);
        }

        Console.WriteLine(SmallerPartWeight(N, x, y, v));
    }
}