cmake_minimum_required(VERSION 3.28...3.29)

project(
  ArilineTicket
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

#[[启用编译 链接 相关 设置]]
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
Set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# 设置项目要使用的Visual Studio版本
set(CMAKE_GENERATOR "Visual Studio 17 2022")
add_compile_options(-fexperimental-library)

#[[打印输出相关变量]]
include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_FLAGS)




# 源文件
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/*.cpp
        ${CMAKE_SOURCE_DIR}/*.c
        ${CMAKE_SOURCE_DIR}/*.ui
        ${CMAKE_SOURCE_DIR}/*.qrc
        )

#！！！ 重点递归查找模板文件 所有的模块接口文件
file(GLOB_RECURSE MODULES_HEADERS
        ${CMAKE_SOURCE_DIR}/module/*.ixx
        ${CMAKE_SOURCE_DIR}/module/*.cxx
        ${CMAKE_SOURCE_DIR}/module/*.cppm)
# 模块定义文件
file(GLOB_RECURSE MODULES_SRC
        ${CMAKE_SOURCE_DIR}/module/*.h
        ${CMAKE_SOURCE_DIR}/module/*.hpp
        ${CMAKE_SOURCE_DIR}/module/*.h
        ${CMAKE_SOURCE_DIR}/module/*.hpp)

add_library(ArilineTicketModule)  
target_sources(
	ArilineTicketModule
	PUBLIC
	FILE_SET  CXX_MODULES FILES
	 ${MODULES_HEADERS};${MODULES_SRC}
	 )  

# 构建可执行程序
add_executable(
    ArilineTicket
	${CMAKE_CURRENT_SOURCE_DIR}/AirlineTicketTest.cpp )


target_link_libraries(ArilineTicket ArilineTicketModule)



