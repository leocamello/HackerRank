using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Solution
{
    static void Main(string[] args)
    {
        int T = Convert.ToInt32(Console.ReadLine());

        for (int i = 0; i < T; i++)
        {
            string[] points = Console.ReadLine().Split(' ');

            int Px, Py, Qx, Qy;

            Px = Convert.ToInt32(points[0]);
            Py = Convert.ToInt32(points[1]);
            Qx = Convert.ToInt32(points[2]);
            Qy = Convert.ToInt32(points[3]);

            int Sx, Sy;
            Sx = Qx + (Qx - Px);
            Sy = Qy + (Qy - Py);

            Console.Write("{0} {1}\n", Sx, Sy);
        }
    }
}
