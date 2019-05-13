#include "../headers/GraphicsEngine.h"

int main() {
    auto engine = GraphicsEngine();
    engine.DrawLine(20, 20, 40, 40);

    getch();
    return 0;
}
