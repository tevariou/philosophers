cmake_minimum_required(VERSION 3.16)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_one philo_one.c)

add_executable(philo_two philo_two.c)