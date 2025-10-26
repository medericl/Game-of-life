#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "grid.h"
#include "generation.h"

static int live_or_die(char **grid, const int j, const int i)
{
    int neighbors = 0;
    for (int k = -1; k <= 1; k += 1)
    {
        for (int l = -1; l <= 1; l += 1)
        {
            if ((l == 0 && k == 0))
                goto skip;
            neighbors += grid[j + k][i + l];
skip:
        }
    }

    if (grid[j][i] && (neighbors == 2 || neighbors == 3))
        return 1;

    if (!grid[j][i] && neighbors == 3)
        return 1;

    return 0;
}

char** next_generation(char **grid, char **new_grid)
{
    for (int j = 1; j < HEIGHT - 1; j++)
        for (int i = 1; i < WIDTH - 1; i++)
            new_grid[j][i] = live_or_die(grid, j, i);

    return new_grid;
}
