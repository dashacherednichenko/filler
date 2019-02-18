cmake_minimum_required(VERSION 3.13)
project(filler C)

set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(dpiven.filler ${LIB} main.c filler.c libfiller.h ft_createmap.c ft_init_players.c)
link_libraries(libft/libft.a)