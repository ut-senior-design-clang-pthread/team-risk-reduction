//
// Created by MaxSa on 11/13/2024.
//

#include "header.h"

namespace {
    pthread_t thread;

    void *worker(void* memory) {
        // Now write some data into the shared memory
        const char* message = "This is from max worker thread";
        std::size_t len = std::min(strlen(message), shared::SharedData::size - 1);

        // Using memcpy to copy data into the mapped memory
        memcpy(memory, message, len);

        return nullptr;
    }
}

void max::init() {

    if (pthread_create(&thread, nullptr, worker, shared::data) != 0) {
        perror("pthread_created");
        abort();
    }
}

void max::run() {
    pthread_join(thread, nullptr);
}

