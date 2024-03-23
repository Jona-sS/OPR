//Debuger Übung
#include <stdio.h>
#include <stdlib.h>
int main()
{
    const int nx = 3;//Spalten
    const int ny = 2;//Zeilen
    int **matrix;
    matrix = (int **)malloc(ny*sizeof(int));
    for (int y = 0; y < ny; y++)
    {
        matrix[y] = (int*)malloc(nx*sizeof(int));
        for (int x = 0; x < nx; x++)
        {
            matrix[y][x] = (y + 1) * 10 + x + 1;
        }
    }
    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            printf("%i ", matrix[y][x]);
        }
        printf("\n");
    }
    for (int y = 0; y < ny; y++)
    {
        free(matrix[y]);
    }
    free(matrix);
}