#[[顶级CMakeList.txt文件]]


#[[ Almost all CMake files should start with this.
 You should always specify a range with the newest
 and oldest tested versions of CMake. This will ensure
 you pick up the best policies.
 该命令为 开头第一个命令,必须在 project()之前  建立版本和策略设置非常重要。 

 cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR]) ]]
cmake_minimum_required(VERSION 3.1...3.28)

#[[This is your project statement. You should always list languages;
 Listing the version is nice here since it sets lots of useful variables
 定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言默认情况支持所有语言
 项目名称 存储到 CMAKE_PROJECT_NAME 中 
 项目版本信息 存储到  CMAKE_PROJECT_VERSION 中 
 项目描述 存储到 CMAKE_PROJECT_DESCRIPTION 中]]
project(
  ModernCMakeCXX20
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

#[[启用编译 链接 相关 设置]]
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
Set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")


#[[打印输出相关变量]]
include(CMakePrintHelpers)     # 内置的模组 CMakePrintHelpoers
cmake_print_variables(CMAKE_CXX_FLAGS)

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




#===================================使用 CMake 下载项目=======================
#=================================== 方法一: 在构建时 (build time) 下载  , 一般走  git的 submodule 

#[[GIt子模组 添加 ,对 用户环境Git检测]]
find_package(Git QUIET)    #CMake 自带的 FindGit.cmake 检测是否安装了 Git
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git") # Update submodules as needed option(GIT_SUBMODULE "Check submodules during build" ON) 
	if(GIT_SUBMODULE) 
		message(STATUS "Submodule update") 
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT) 
		if(NOT GIT_SUBMOD_RESULT EQUAL "0") 
			message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules") 
		endif() 
	endif() 
endif() 

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/submodule/googletest/googletest/CMakeLists.txt")   # 路径需要正确  CMake都会检查仓库是否已经被拉取到本地
	message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.") 
endif()
## 子模组 子路径  
# 缺点: 若 前置拉取失败 ,则add_subdirectory 不能对一个尚不存在的文件夹使用
# 解决: 必须自己构建自己（这个外部项目）来解决这个问题
#因为导入 该文件路径在测试时需要, 直接转移到是否启用测试中去 
#add_subdirectory(extern/submodule/googletest/googletest)  
#=================================== 方法二: 在配置时 (configure time) 下载
# 提供了插件式（不需要改变你原有的 CMakeLists.txt）的解决方案
# 自动下载在没有网络访问的环境下也是难以实现的，并且外部项目经常被下载到构建目录中，如果你有多个构建目录，这就既浪费时间又浪费空间。
# 参考  https://github.com/Crascit/DownloadProject

#=================================测试模块 ============================
set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/extern/submodule/googletest/googletest)
message(STATUS  "GTEST_ROOT = ${GTEST_ROOT}")
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
	# 相同的 路径 不能导入两次,否则会报错 ,例如 针对googletest子模块存在验证添加 和 测试模块添加都导入同一个路径 重复导入报错
	add_subdirectory(${GTEST_ROOT})
	include_directories(${GTEST_ROOT}/include)
endif()

# 代码是可选的，它可以让你的 CACHE 更干净
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)




#====================================CMake 基础知识=============================================

#[[00 注释部分 - 此处 为块注释

# 行注释 
]]

# 01------------打印变量 

# 方法一 

set(My_Variable 100)   # 声明变量
message(STATUS "My_Variable = ${My_Variable}")  #打印变量
message(STATUS "My_Variable = ${PROJECT_SOURCE_DIR}")  #打印变量
message(STATUS "My_Variable = ${CMAKE_SOURCE_DIR}")  #打印变量

