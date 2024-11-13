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

namespace shared
{

namespace
{
     SharedData* init()
    {
        SharedData *shared_mem = nullptr;

        shared_mem = (SharedData*) mmap(nullptr, SharedData::size, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

        if (shared_mem == MAP_FAILED)
        {
            perror("Memory mapping failed");
            abort();
        }

        return shared_mem;
    }
}

    SharedData *const data = init();

}


