# CMake simple example

## [main]

# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
# 该命令为 开头第一个命令,必须在 project()之前  建立版本和策略设置非常重要。

# cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])
cmake_minimum_required(VERSION 3.1...3.28)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
# 定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言（默认情况支持所有语言）

#项目名称 存储到 CMAKE_PROJECT_NAME 中 
#项目版本信息 存储到  CMAKE_PROJECT_VERSION 中 
#项目描述 存储到 CMAKE_PROJECT_DESCRIPTION 中
project(
  ModernCMakeCXX20
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)


# Set 变量 
# SET 指令的语法是：
# [] 中的参数为可选项, 如不需要可以不写
# SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])

# 方式2: 各个源文件之间使用分号 ; 间隔
# 如果在 Project中指定 语言,例如C++ 单纯的 C 是否可使用? 
# 查看 CMAKE_CXX_STANDARD
set(CMAKE_CXX_STANDARD 20)
set(SRC_ARITHMETIC ./src/Arithmetic/add.cpp;./src/Arithmetic/div.cpp;./src/Arithmetic/mult.cpp;./src/Arithmetic/sub.cpp)
#aux_source_directory(${PROJECT_SOURCE_DIR}/   )
#如果这个路径中的子目录不存在，会自动生成，无需自己手动创建
#set(HOME /home/robin/Linux/Sort)
#set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)


# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(MyLibExample ./src/LibExample001/simple_lib.cpp; ./src/LibExample001/simple_lib.hpp)

# Link each target with other targets or add options, etc.

# Adding something we can run - Output name matches target name
# 定义工程会生成一个可执行程序 如有多个可用空格或;间隔
add_executable(MyExample src/LibExample001/simple_example.cpp )

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(MyExample PRIVATE MyLibExample)

## [main]

# This part is so the Modern CMake book can verify this example builds. For your code,
# you'll probably want tests too
enable_testing()
add_test(NAME MyExample COMMAND MyExample)


#====================================CMake 基础知识=============================================

#[[00 注释部分 - 此处 为块注释

# 行注释 
]]

