#include "header.h"

int main()
{
    isaac::init();
    timothy::init();
    victoria::init();
    max::init();

    isaac::run();
    timothy::run();
    victoria::run();
    max::run();

    return 0;
}