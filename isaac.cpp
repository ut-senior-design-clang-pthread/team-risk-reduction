//
// Created by isaac on 11/13/24.
//

#include "header.h"

namespace
{
    pthread_t thread;

    void *worker(void *shared_mem)
    {
        auto *data = static_cast<shared::SharedData*>(shared_mem);
        std::print("{}", data->as_string_view());
        return nullptr;
    }
}

void isaac::init()
{
    pthread_create(&thread, nullptr, worker, shared::data);
}

void isaac::run()
{
    pthread_join(thread, nullptr);
}
