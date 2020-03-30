using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[,] a = new int[n, n];
        int nm = 1;
        int fromLeftToRigth = 0;
        int fromLeftToRigth2 = 0;
        int j = 0;
        while(nm <= n * n)
        {
///            Console.WriteLine("nm = " + nm);
            for (j = fromLeftToRigth2; j < n - fromLeftToRigth2; ++j)
            {
                a[fromLeftToRigth, j] = nm;
                ++nm;
            }
            fromLeftToRigth2 = ++fromLeftToRigth; // 1, 1

            int fromUpToDown = fromLeftToRigth; // 1
            int fromUpToDown2 = n - fromLeftToRigth2; // n - 1

            for (j = fromUpToDown; j <= n - fromUpToDown; ++j)
            {
                a[j, fromUpToDown2] = nm;
                nm++;
            }

            int fromRigthToLeft = --j; // n - 1
            int fromRigthToLeft2 = --fromUpToDown2; // n - 2

            for (j = fromRigthToLeft2; j >= fromLeftToRigth2 - 1; j--)
            {
                a[fromRigthToLeft, j] = nm;
                nm++;
            }

            int fromDownToUP = fromRigthToLeft - 1; // n - 2
            int fromDownToUp2 = fromLeftToRigth - 1; // 0

            for (j = fromDownToUP; j >= fromLeftToRigth; j--)
            {
                a[j, fromDownToUp2] = nm;
                nm++;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
                Console.Write(a[i,j] + " ");
            Console.WriteLine();
        }
    }
}
