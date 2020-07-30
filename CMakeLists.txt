cmake_minimum_required(VERSION 3.16)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_one philo_one/philo_one.c philo_one/philo_one.h philo_one/utils.c philo_one/time.c philo_one/print.c philo_one/philosopher.c philo_one/monitor.c philo_one/config.c philo_one/clean.c)

add_executable(philo_two philo_two/philo_two.c philo_two/philo_two.h philo_two/utils.c philo_two/time.c philo_two/print.c philo_two/philosopher.c philo_two/monitor.c philo_two/config.c)

add_executable(philo_three philo_three/philo_three.c philo_three/philo_three.h philo_three/utils.c philo_three/time.c philo_three/print.c philo_three/philosopher.c philo_three/monitor.c philo_three/config.c)