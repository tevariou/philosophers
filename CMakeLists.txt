cmake_minimum_required(VERSION 3.16)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_one philo_one/philo_one.c philo_one/philo_one.h philo_one/utils.c philo_one/time.c)

add_executable(philo_two philo_two/philo_two.c)