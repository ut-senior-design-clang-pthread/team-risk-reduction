//
// Created by Timothy George on 11/13/24
//

#include "header.h"

namespace {
    pthread_t th;
    void *worker(void *shared_memory)
    {
        //read from memory
        auto *data = static_cast<shared::SharedData*>(shared_memory);

        //write to shared memory
        char msg[] = "Hello World";
        memcpy(data, msg, sizeof(msg));
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

