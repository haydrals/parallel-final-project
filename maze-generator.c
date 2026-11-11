#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WALL '#'
#define PATH ' '

typedef struct {
    int x;
    int y;
} Cell;

static const int dx[] = {0, 1, 0, -1};
static const int dy[] = {-1, 0, 1, 0};

static void shuffle4(int *order)
{
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}

int main(int argc, char *argv) {
    int w = 20, h = 10;
    unsigned seed = (unsigned)time(NULL);

    if (argc > 1) w = atoi(argv[1]);
    if (argc > 2) h = atoi(argv[2]);
    if (argc > 3) seed = (unsigned)strtoul(argv[3], NULL, 10);

    if (w < 2 || h < 2 || w > 500 || h > 500) {
        fprintf(stderr, "Invalid maze dimensions\n");
        return 1;
    }
    
    srand(seed);

    int gw = 2 * w + 1, gh = 2 * h + 1;
    char *grid = malloc((size_t)gw * gh);
    char *visited = calloc((size_t)gw * gh, 1);
    Cell *stack = malloc(sizeof(Cell) * (size_t)w * h);
    if (!grid || !visited || !stack) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    memset(grid, WALL, (size_t)gw * gh);
}


