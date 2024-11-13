//
// Created by Timothy George on 11/13/24
//

#include "header.h"

namespace {
    pthread_t th;
    void *func(void *shared_memory)
    {
        auto *data = static_cast<shared::SharedData*>(shared_memory);
        std::print("{}", data->as_string_view());

        return nullptr;
    }
}

void timothy::init(){
    pthread_create(&th, nullptr, worker, shared::data);
}

void timothy::run(){
    pthread_join(th, nullptr);
}

