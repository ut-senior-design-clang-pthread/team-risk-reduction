cmake_minimum_required(VERSION 3.30)
project(team_risk_reduction)

set(CMAKE_CXX_STANDARD 20)

add_executable(team_risk_reduction main.cpp)
target_link_options(team_risk_reduction PRIVATE "-lpthread")