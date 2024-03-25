// Angepasste 2D Matrix
// Debuger Übung
#include <stdio.h>
#include <stdlib.h>
int main()
{
    const int nx = 3; // Spalten
    const int ny = 3; // Zeilen
    const int nz = 3; // Höhe/Tiefe
    int ***matrix;
    //Matrix befüllen
    matrix = (int ***)malloc(nz * sizeof(int**));
    for (int z = 0; z < nz; z++)
    {
        matrix[z] = (int **)malloc(ny * sizeof(int*));
        for (int y = 0; y < ny; y++)
        {
            matrix[z][y] = (int *)malloc(nx * sizeof(int));
            for (int x = 0; x < nx; x++)
            {
                matrix[z][y][x] = (z + 1) * 100 + (y + 1) * 10 + x + 1;
            }
        }
    }
    //Ausgabe
    for (int z = 0; z < nz; z++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int x = 0; x < nx; x++)
            {
                printf("%i ", matrix[z][y][x]);
            }
            printf("\n");
        }
        printf("\n");
    }
    //Reservierten Speicherplatz freigeben
    for (int z = 0; z < nz; z++)
    {
        for (int y = 0; y < ny; y++)
        {
            free(matrix[z][y]);
        }
        free(matrix[z]);
    }
    free(matrix);
}