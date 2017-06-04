include (CMakeToolsHelpers OPTIONAL)

cmake_minimum_required(VERSION 2.8)

project(SW2048Game_CLI)

aux_source_directory(. DIR_SRCS)

aux_source_directory(xplatform DIR_X)

add_subdirectory(2048_GameModel_xplat_cpp_cmake)

add_executable(SW2048GameCLI main.cpp ${DIR_SRCS} ${DIR_X})

target_link_libraries(SW2048GameCLI SW2048GameModel)