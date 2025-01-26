cmake_minimum_required(VERSION 3.16)

project(Extra1_LuokkaJaOlio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Extra1_LuokkaJaOlio main.cpp)

include(GNUInstallDirs)
install(TARGETS Extra1_LuokkaJaOlio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
