cmake_minimum_required(VERSION 3.16)

project(Vko2T1-3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vko2T1-3 main.cpp
    Game.cpp
    Game.h)

include(GNUInstallDirs)
install(TARGETS Vko2T1-3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
