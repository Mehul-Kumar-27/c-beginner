cmake_minimum_required(VERSION 3.10)
project(BettingGame C)

set(CMAKE_C_STANDARD 11)

# Add player and game source files
add_executable(gamble main.c player/player.c utils/utils.c)
