#include <stdio.h>
#include <unistd.h> // Para usar usleep()
#include <stdlib.h> // Para usar system()

typedef struct
{
    int p1y, p1x,
        p2y, p2x,
        p3y, p3x,
        p4y, p4x;
} diamonds;

static int frameCounter = 0;

void clearFrame(int height, int width, char frame[height][width]);
void renderFrame(int height, int width, char frame[height][width]);
void updateDiamond(diamonds *update);
void drawDiamond(int height, int width, char frame[height][width],
                 int x1, int y1,
                 int x2, int y2,
                 int x3, int y3,
                 int x4, int y4);

int main()
{
    int width = 40;  // columnas (X)
    int height = 15; // filas (Y)

    char frame[height][width]; // <-- ahora está correcto: frame[y][x]

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            frame[y][x] = '$';
        }
    }

    diamonds diamond;
    diamond.p1y = 0;
    diamond.p1x = 1;
    diamond.p2y = 1;
    diamond.p2x = 0;
    diamond.p3y = 1;
    diamond.p3x = 2;
    diamond.p4y = 2;
    diamond.p4x = 1;

    frame[diamond.p1y][diamond.p1x] = '*';
    frame[diamond.p2y][diamond.p2x] = '*';
    frame[diamond.p3y][diamond.p3x] = '*';
    frame[diamond.p4y][diamond.p4x] = '*';

    do
    {
        updateDiamond(&diamond);

        clearFrame(height, width, frame); // limpiar el buffer

        drawDiamond(height, width, frame,
                    diamond.p1y,diamond.p1x,
                    diamond.p2y,diamond.p2x,
                    diamond.p3y,diamond.p3x,
                    diamond.p4y,diamond.p4x);

        renderFrame(height, width, frame);

    } while (frameCounter < 36);
   
    return 0;
}


void updateDiamond(diamonds *update)
{
    update->p1x++;
    update->p2x++;
    update->p3x++;
    update->p4x++;
}

void clearFrame(int height, int width, char frame[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            frame[i][j] = '$';
        }
    }
}

void renderFrame(int height, int width, char frame[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            printf("%c", frame[i][j]);
        printf("\n");
    }
    frameCounter++; // global para ser accedida por otras funciones
    usleep(300000);
    system("clear");
}

void drawDiamond(int height, int width, char frame[height][width],
                 int x1, int y1,
                 int x2, int y2,
                 int x3, int y3,
                 int x4, int y4)
{
    frame[x1][y1] = '*';
    frame[x2][y2] = '*';
    frame[x3][y3] = '*';
    frame[x4][y4] = '*';
}
