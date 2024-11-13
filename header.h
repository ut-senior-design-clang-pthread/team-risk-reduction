//
// Created by isaac on 11/13/24.
//
#pragma once

#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <string.h>

#include <print>

namespace isaac
{
    void init();
    void run();
}

namespace timothy
{
    void init();
    void run();
}

namespace victoria
{
    void init();
    void run();
}

namespace max
{
    void init();
    void run();
}

namespace shared
{
    struct SharedData
    {
        static constexpr size_t size = 131'072;

        std::string_view as_string_view() const;
    };

    extern SharedData *const data;
}