cmake_minimum_required(VERSION 3.25)
project(projet_c C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_c main.c cell.c cell.h list.c list.h agenda.c agenda.h timer.c contact.c contact.h rdv.c rdv.h)
