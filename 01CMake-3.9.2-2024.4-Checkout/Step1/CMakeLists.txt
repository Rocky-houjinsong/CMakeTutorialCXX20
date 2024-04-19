# 00 -- CMake 三要素 --
cmake_minimum_required(VERSION 3.10)
project(CMakeTutorial VERSION 2.15)   # MAJOR 和MINOR读取的就是小数点前后两个数字  
# 00 ----------------

# 01 -- CXX标准 设置
set(CMAKE_CXX_STANDARD 20)			#  C++标准变量枚举值 有 (98, 11,14,17,20,23等 其他报错)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# 01-----------------------
#在CMakeLists.txt定义变量, 有CPP文件进行读取 放在此处 , 设置后,可能不会理解刷新到 头文件 ,重新走命令行 重新cmake .. 一下 , 就可以
set(STR_TEST "Hello World!??")    

# 输入文件/模板文件  --> 输出文件
# 输出文件 放到Build 文件夹下  此时 , 生成文件在 build文件夹内, 而要在 build同级文件(tutorial.cxx) 中使用,如何 找到呢?无法直接包含,所以要指定 头文件的路径
configure_file(TutorialConfig.h.in CMakeTutorialConfig.h)
add_executable(CMakeTutorial tutorial.cxx)

#指定可执行目标 应在何处 查找包含文件  --->? 因为要添加的头文件 TutorialConfig.h无法直接包含,所以要指定路径
# build目录 可以使用 PROJECT_BINARY_DIR  进行表示 
# PUBLIC PRIVATE INTERFACE
# 若 路径无空格,可使用{},如果有空格,使用"" 进行包含
target_include_directories(CMakeTutorial PUBLIC 
							"${PROJECT_BINARY_DIR}"
						  )


#Specify MSVC UTF-8 encoding   添加以下两行 做UTF8编译
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${Tutorial_VERSION_MAJOR}")
message(STATUS "${Tutorial_VERSION_MINOR}")


