# TODO 1: Set the minimum required version of CMake to be 3.10  
#[[ 设置 CMake 最低版本要求 语法 扩展 可  设置成 版本区间 
    该 命令 必须为 首要命令, 影响 后续命令的实现 
]]
cmake_minimum_required(VERSION 3.1...3.28)


# TODO 2: Create a project named Tutorial
# TODO 7: Set the project version number as 1.0 in the above project command
#[[ 创建 一个 名为 CMakeTutorial 的项目 
同时 可以 设置 项目的 介绍,项目的URL ,项目的 版本信息等,,项目使用的编程语言等 
顺序 没有要求,因为是 同时执行 命令 + 命令值 
建议 以 list的方式进行维护 
格式:  
]]
project(
  CMakeTutorialStep1
  VERSION 2.3.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)


# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True

#[[变量 声明/设置 ---- 内置变量 / 自定义变量 ]]
#[[ 启用C++语言标准     启用是 为了使用, 在CXX中 对照 使用的地方 

    如果 不启用, 则默认 启用 和使用上一个版本的 
]]
#[[ 可设置的 C++标准 一定是 固定 和受限的 枚举类型  如 98 11 14 17 20 23 26 等 C++标准对应

    如何 查看 编译 使用的C++标准呢?   打印输出 _cplusplus 这个宏定义 进行查看 
]]
set(CMAKE_CXX_STANDARD_REQUIRED True)   
set(CMAKE_CXX_STANDARD 17)              # 设置C++ 语言标准 为 C++20         需注意的是 启用的标准 要和 使用的C++特性保持对应 和向后兼容 ,例如 std::atof 是C++11 之后才有的, 98标准是没有的,                                                   

set(STR_TEST "Hello This is variable from CMakeLists.txt")



# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h
#[[ 第一种 使用message 进行 打印输出 特定内容]]
message(STATUS "Hello World from cmake!")
# CMake 访问 变量   使用 ${}  
message(STATUS ${PROJECT_BINARY_DIR})   
message(STATUS ${CMakeTutorialStep1_VERSION_MAJOR})     # 手动打印 特定项目的版本信息 
message(STATUS ${CMakeTutorialStep1_VERSION_MINOR})   



#[[ 第二种 使用 内置 CMakePrintHelpers  ----- Cmake的 打印帮助]]
include(CMakePrintHelpers)     # 内置的模组 CMakePrintHelpoers
cmake_print_variables(CMAKE_CXX_STANDARD)                                    # cmake .. 生成后 二次编辑 ,可使用cmake .  , 前提是借助 cmakecache.txt文件进行辅助构建生成 , 
cmake_print_variables(PROJECT_BINARY_DIR)     # build 所在目录  代表的 是 构建目录,也就是 cmake 指令 所在的目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)     # 走 CMAKe 内置变量打印 版本信息 
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 

#[[ 配置文件  ---  将 输入文件 读取并  转化为 输出 文件  ,一般 是 .in 转化为 .h 文件 ,便于 配置 , 源文件方便 引入  

    问题: 输出文件 .h 的路劲 存在  构建路径中 ,也就是 此处的 build 文件路径中  和  顶级根CMakeLists.txt不在同一路径下,需手动添加 导入该路径 

    问: 如何验证 该语句执行正确 ?  message 获取变量值, 查看构建路径 是否有 输出文件,且输出文件中的值 就是 特定的

    配置文件  借助转化成的 头文件 引入 可被 源文件读取, 反过来可以吗???    
]]
configure_file(TutorialConfig.h.in CMakeTutorialConfig.h)



# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx

#[[ 为 项目 添加一个 叫做 Tutorial.cxx 文件
    如果有多个 源文件(.cxx,cpp等格式)的文件需要添加 , 手动方式的话, 以 空格 或 分隔符; 进行 隔开 
    自动的 话 , 以 一个 变量 或者 文件搜索的方式 获取特定格式的 文件,然后 借助变量进行 赋值 
    cxx 格式后缀是 Linux平台的, CPP文件是Windows平台的, 但都可以识别和使用 
]]
add_executable(CMakeTutorial tutorial.cxx)
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}

#[[ 将 设计到的 ,被生成的 头文件   添加 进来 

  PUBLIC PRIVATE  INNER 三者  不同的 作用 
]]
# 此处 要引入的 目标是  TutorialConfig.h  所在路径 为构建路径    "${PROJECT_BINARY_DIR}"
target_include_directories(CMakeTutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )