#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, const char *argv[]) {
    srand(time(0));
    int width;
    cin >> width;
    int height = width;
    int sx = rand()%width;
    int sy = rand()%height;
    int ex = rand()%width;
    int ey = rand()%height;
    int map[height][width];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            map[i][j] = rand() % 10;
        }
    }
    cout << width << " " << height << endl;
    cout << sx << " " << sy << endl;
    cout << ex << " " << ey << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
