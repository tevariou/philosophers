cmake_minimum_required(VERSION 3.16)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_one philo_one/philo_two.c philo_one/philo_one.h philo_one/utils.c philo_one/time.c philo_one/print.c philo_one/philosopher.c philo_one/monitor.c)

add_executable(philo_two philo_two/philo_two.c philo_two/philo_two.h philo_two/utils.c philo_two/time.c philo_two/print.c philo_two/philosopher.c philo_two/monitor.c)