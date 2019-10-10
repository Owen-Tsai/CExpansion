cmake_minimum_required(VERSION 3.14)
project(CExpansion C)

set(CMAKE_C_STANDARD 99)

add_executable(CExpansion main.c Utls/Status.h LinearList/SequenceList.h LinearList/SequenceList.c Utls/include.h Utls/MathHelper.c)