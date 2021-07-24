using System;

namespace MatrixRotation
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] matrix = { { 1,2,3,4},
                               {5,6,7,8},
                            { 9,10,11,12},
                            { 13,14,15,16} };
            PrintMatrix(matrix);
            RotateMatrix(matrix);
            PrintMatrix(matrix);


            int[,] matrix2 = { { 1,4},
                               {5,8},
                            { 9,12},
                            { 13,16} };
            PrintMatrix(matrix2);
            RotateMatrix(matrix2);
            PrintMatrix(matrix2);


            Console.ReadLine();
        }

        static void RotateMatrix(int[,] matrix)
        {
            int maxRow = matrix.GetLength(0) - 1;
            int maxCol = matrix.GetLength(1) - 1;
            int row = 0;
            int col = 0;

            while (row < maxRow && col < maxCol)
            {

                int previous = matrix[row+1,col];
                for (int i = col; i <= maxCol; i++)
                {
                    int current = matrix[row,i];
                    matrix[row,i] = previous;
                    previous = current;
                }
                row++;

                for (int i = row; i <= maxRow; i++)
                {
                    int current = matrix[i, maxCol];
                    matrix[i, maxCol] = previous;
                    previous = current;
                }
                maxCol--;

                if (row < maxRow + 1)
                {
                    for (int i = maxCol; i >= col; i--)
                    {
                        int current = matrix[maxRow, i];
                        matrix[maxRow, i] = previous;
                        previous = current;
                    }
                    maxRow--;
                }

                if (col < maxCol + 1)
                {
                    for (int i = maxRow; i >= row; i--)
                    {
                        int current = matrix[i, col];
                        matrix[i, col] = previous;
                        previous = current;
                    }
                    col++;
                }
            }
        }

        private static void PrintMatrix(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
