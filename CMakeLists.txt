cmake_minimum_required(VERSION 3.30)
project(team_risk_reduction)

set(CMAKE_CXX_STANDARD 23)

option(ENABLE_THREAD_SANITIZER "Compile the project with ThreadSanitizer" OFF)

add_executable(team_risk_reduction main.cpp
        isaac.cpp
        timothy.cpp
        victoria.cpp
        max.cpp)
target_link_options(team_risk_reduction PRIVATE "-lpthread" "-Wl,--as-needed")
target_compile_options(team_risk_reduction PRIVATE -fno-exceptions)

target_precompile_headers(team_risk_reduction PRIVATE header.h)

if (ENABLE_THREAD_SANITIZER)
    target_compile_options(team_risk_reduction PRIVATE
            -fsanitize=thread
            -Og
            -ggdb3
            -fno-omit-frame-pointer
    )
    target_link_options(team_risk_reduction PRIVATE
        -fsanitize=thread
    )
endif ()