> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [subingwen.cn](https://subingwen.cn/cmake/CMake-primer/)

> 1. CMake 概述 CMake 是一个项目构建工具，并且是跨平台的。

CMake 是一个项目构建工具，并且是跨平台的。关于项目构建我们所熟知的还有 Makefile（通过 make 命令进行项目的构建），大多是 IDE 软件都集成了 make，比如：VS 的 nmake、linux 下的 GNU make、Qt 的 qmake 等，如果自己动手写 makefile，会发现，makefile 通常依赖于当前的编译平台，而且编写 makefile 的工作量比较大，解决依赖关系时也容易出错。

而 CMake 恰好能解决上述问题， 其允许开发者指定整个工程的编译流程，在根据编译平台，`自动生成本地化的Makefile和工程文件`，最后用户只需`make`编译即可，所以可以把 CMake 看成一款自动生成 Makefile 的工具，其编译流程如下图：

![image-20230309130644912](https://raw.githubusercontent.com/Rocky-houjinsong/PictureBed/main/img202404221134074.png?token=ANVNPPJVZFEQ7WAEOHYCPW3GEXNPM)

*   蓝色虚线表示使用`makefile`构建项目的过程
*   红色实线表示使用`cmake`构建项目的过程

介绍完 CMake 的作用之后，再来总结一下它的优点：

*   跨平台
*   能够管理大型项目
*   简化编译构建过程和编译过程
*   可扩展：可以为 cmake 编写特定功能的模块，扩充 cmake 功能

`CMake`支持大写、小写、混合大小写的命令。如果在编写`CMakeLists.txt`文件时使用的工具有对应的命令提示，那么大小写随缘即可，不要太过在意。

[](#2-1-注释 "2.1 注释")2.1 注释
--------------------------

### [](#2-1-1-注释行 "2.1.1 注释行")2.1.1 注释行

`CMake` 使用 `#` 进行`行注释`，可以放在任何位置。

```
cmake_minimum_required(VERSION 3.0.0)
```

### [](#2-1-2-注释块 "2.1.2 注释块")2.1.2 注释块

`CMake` 使用 `#[[ ]]` 形式进行`块注释`。

```
cmake_minimum_required(VERSION 3.0.0)
```

[](#2-1-只有源文件 "2.1 只有源文件")2.1 只有源文件
-----------------------------------

### [](#2-1-1-共处一室 "2.1.1 共处一室")2.1.1 共处一室

1.  准备工作，为了方便测试，在我本地电脑准备了这么几个测试文件
    
    *   **add.c**
        
        ```
        #include <stdio.h>
        #include "head.h"
        
        int add(int a, int b)
        {
            return a+b;
        }
        ```
        
    *   **sub.c**
        
        ```
        #include <stdio.h>
        #include "head.h"
        
        
        int subtract(int a, int b)
        {
            return a-b;
        }
        ```
        
    *   **mult.c**
        
        ```
        #include <stdio.h>
        #include "head.h"
        
        int multiply(int a, int b)
        {
            return a*b;
        }
        ```
        
    *   **div.c**
        
        ```
        #include <stdio.h>
        #include "head.h"
        
        double divide(int a, int b)
        {
            return (double)a/b;
        }
        ```
        
    *   **head.h**
        
        ```
        #ifndef _HEAD_H
        #define _HEAD_H
        
        int add(int a, int b);
        
        int subtract(int a, int b);
        
        int multiply(int a, int b);
        
        double divide(int a, int b);
        #endif
        ```
        
    *   **main.c**
        
        ```
        #include <stdio.h>
        #include "head.h"
        
        int main()
        {
            int a = 20;
            int b = 12;
            printf("a = %d, b = %d\n", a, b);
            printf("a + b = %d\n", add(a, b));
            printf("a - b = %d\n", subtract(a, b));
            printf("a * b = %d\n", multiply(a, b));
            printf("a / b = %f\n", divide(a, b));
            return 0;
        }
        ```
    
2.  上述文件的目录结构如下：
    
    ```
    $ tree
    .
    ├── add.c
    ├── div.c
    ├── head.h
    ├── main.c
    ├── mult.c
    └── sub.c
    ```
    
3.  **添加 `CMakeLists.txt` 文件**
    
    在上述源文件所在目录下添加一个新文件 CMakeLists.txt，文件内容如下：
    
    ```
    cmake_minimum_required(VERSION 3.0)
    project(CALC)
    add_executable(app add.c div.c main.c mult.c sub.c)
    ```
    
    接下来依次介绍一下在 CMakeLists.txt 文件中添加的三个命令:
    
    *   `cmake_minimum_required`：指定使用的 cmake 的最低版本
        
        *   **可选，非必须，如果不加可能会有警告**
    *   `project`：定义工程名称，并可指定工程的版本、工程描述、web 主页地址、支持的语言（默认情况支持所有语言），如果不需要这些都是可以忽略的，只需要指定出工程名字即可。
        
        ```
        project(<PROJECT-NAME> [<language-name>...])
        project(<PROJECT-NAME>
               [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
               [DESCRIPTION <project-description-string>]
               [HOMEPAGE_URL <url-string>]
               [LANGUAGES <language-name>...])
        ```
        
    *   `add_executable`：定义工程会生成一个可执行程序
        
        ```
        add_executable(可执行程序名 源文件名称)
        ```
        
        *   这里的可执行程序名和`project`中的项目名没有任何关系
            
        *   源文件名可以是一个也可以是多个，如有多个可用空格或`;`间隔
            
            ```
            add_executable(app add.c div.c main.c mult.c sub.c)
            
            add_executable(app add.c;div.c;main.c;mult.c;sub.c)
            ```
    
4.  执行`CMake` 命令
    
    万事俱备只欠东风，将 CMakeLists.txt 文件编辑好之后，就可以执行 `cmake`命令了。
    
    ```
    # cmake 命令原型
    $ cmake CMakeLists.txt文件所在路径
    ```
    
    ```
    $ tree
    .
    ├── add.c
    ├── CMakeLists.txt
    ├── div.c
    ├── head.h
    ├── main.c
    ├── mult.c
    └── sub.c
    
    0 directories, 7 files
    robin@OS:~/Linux/3Day/calc$ cmake .
    ```
    
    当执行`cmake`命令之后，CMakeLists.txt 中的命令就会被执行，所以一定要注意给`cmake` 命令指定路径的时候一定不能出错。
    
    执行命令之后，看一下源文件所在目录中是否多了一些文件：
    
    ```
    $ tree -L 1
    .
    ├── add.c
    ├── CMakeCache.txt         # new add file
    ├── CMakeFiles             # new add dir
    ├── cmake_install.cmake    # new add file
    ├── CMakeLists.txt
    ├── div.c
    ├── head.h
    ├── main.c
    ├── Makefile               # new add file
    ├── mult.c
    └── sub.c
    ```
    
    我们可以看到在对应的目录下生成了一个`makefile`文件，此时再执行`make`命令，就可以对项目进行构建得到所需的可执行程序了。
    
    ```
    $ make
    Scanning dependencies of target app
    [ 16%] Building C object CMakeFiles/app.dir/add.c.o
    [ 33%] Building C object CMakeFiles/app.dir/div.c.o
    [ 50%] Building C object CMakeFiles/app.dir/main.c.o
    [ 66%] Building C object CMakeFiles/app.dir/mult.c.o
    [ 83%] Building C object CMakeFiles/app.dir/sub.c.o
    [100%] Linking C executable app
    [100%] Built target app
    
    # 查看可执行程序是否已经生成
    $ tree -L 1
    .
    ├── add.c
    ├── app					# 生成的可执行程序
    ├── CMakeCache.txt
    ├── CMakeFiles
    ├── cmake_install.cmake
    ├── CMakeLists.txt
    ├── div.c
    ├── head.h
    ├── main.c
    ├── Makefile
    ├── mult.c
    └── sub.c
    ```
    
    最终可执行程序`app`就被编译出来了（这个名字是在`CMakeLists.txt`中指定的）。
    

### [](#2-1-2-VIP-包房 "2.1.2 VIP 包房")2.1.2 VIP 包房

通过上面的例子可以看出，如果在`CMakeLists.txt`文件所在目录执行了`cmake`命令之后就会生成一些目录和文件（`包括 makefile 文件`），如果再基于`makefile文件`执行`make`命令，程序在编译过程中还会生成一些中间文件和一个可执行文件，这样会导致整个项目目录看起来很混乱，不太容易管理和维护，此时我们就可以把生成的这些与项目源码无关的文件统一放到一个对应的目录里边，比如将这个目录命名为`build`:

```
$ mkdir build
$ cd build
$ cmake ..
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/robin/Linux/build
```

现在`cmake`命令是在`build`目录中执行的，但是`CMakeLists.txt`文件是`build`目录的上一级目录中，所以`cmake` 命令后指定的路径为`..`，即当前目录的上一级目录。

当命令执行完毕之后，在`build`目录中会生成一个`makefile`文件

```
$ tree build -L 1
build
├── CMakeCache.txt
├── CMakeFiles
├── cmake_install.cmake
└── Makefile

1 directory, 3 files
```

这样就可以在`build`目录中执行`make`命令编译项目，生成的相关文件自然也就被存储到`build`目录中了。这样通过`cmake`和`make`生成的所有文件就全部和项目源文件隔离开了，各回各家，各找各妈。

[](#2-2-私人订制 "2.2 私人订制")2.2 私人订制
--------------------------------

### [](#2-2-1-定义变量 "2.2.1 定义变量")2.2.1 定义变量

在上面的例子中一共提供了 5 个源文件，假设这五个源文件需要反复被使用，每次都直接将它们的名字写出来确实是很麻烦，此时我们就需要定义一个变量，将文件名对应的字符串存储起来，在 cmake 里定义变量需要使用`set`。

```
SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
```

*   `VAR`：变量名
*   `VALUE`：变量值

```
set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)
add_executable(app  ${SRC_LIST})
```

### [](#2-2-2-指定使用的C-标准 "2.2.2 指定使用的C++标准")2.2.2 指定使用的 C++ 标准

在编写 C++ 程序的时候，可能会用到 C++11、C++14、C++17、C++20 等新特性，那么就需要在编译的时候在编译命令中制定出要使用哪个标准：

```
$ g++ *.cpp -std=c++11 -o app
```

上面的例子中通过参数`-std=c++11`指定出要使用 c++11 标准编译程序，C++ 标准对应有一宏叫做`DCMAKE_CXX_STANDARD`。在 CMake 中想要指定 C++ 标准有两种方式：

1.  在 CMakeLists.txt 中通过 set 命令指定
    
    ```
    set(CMAKE_CXX_STANDARD 11)
    
    set(CMAKE_CXX_STANDARD 14)
    
    set(CMAKE_CXX_STANDARD 17)
    ```
    
2.  在执行 cmake 命令的时候指定出这个宏的值
    
    ```
    #增加-std=c++11
    cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=11
    #增加-std=c++14
    cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=14
    #增加-std=c++17
    cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=17
    ```
    
    在上面例子中 CMake 后的路径需要根据实际情况酌情修改。
    

### [](#2-2-3-指定输出的路径 "2.2.3 指定输出的路径")2.2.3 指定输出的路径

在 CMake 中指定可执行程序输出的路径，也对应一个宏，叫做`EXECUTABLE_OUTPUT_PATH`，它的值还是通过`set`命令进行设置:

```
set(HOME /home/robin/Linux/Sort)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
```

*   第一行：定义一个变量用于存储一个绝对路径
*   第二行：将拼接好的路径值设置给`EXECUTABLE_OUTPUT_PATH`宏
    *   **如果这个路径中的子目录不存在，会自动生成，无需自己手动创建**

由于可执行程序是基于 cmake 命令生成的 makefile 文件然后再执行 make 命令得到的，所以如果此处指定可执行程序生成路径的时候使用的是相对路径 ./xxx/xxx，那么这个路径中的 ./ 对应的就是 makefile 文件所在的那个目录。

[](#2-3-搜索文件 "2.3 搜索文件")2.3 搜索文件
--------------------------------

如果一个项目里边的源文件很多，在编写`CMakeLists.txt`文件的时候不可能将项目目录的各个文件一一罗列出来，这样太麻烦也不现实。所以，在 CMake 中为我们提供了搜索文件的命令，可以使用`aux_source_directory`命令或者`file`命令。

### [](#2-3-1-方式1 "2.3.1 方式1")2.3.1 方式 1

在 CMake 中使用`aux_source_directory` 命令可以查找某个路径下的`所有源文件`，命令格式为：

```
aux_source_directory(< dir > < variable >)
```

*   `dir`：要搜索的目录
*   `variable`：将从`dir`目录下搜索到的源文件列表存储到该变量中

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_executable(app  ${SRC_LIST})
```

### [](#2-3-2-方式2 "2.3.2 方式2")2.3.2 方式 2

如果一个项目里边的源文件很多，在编写`CMakeLists.txt`文件的时候不可能将项目目录的各个文件一一罗列出来，这样太麻烦了。所以，在 CMake 中为我们提供了搜索文件的命令，他就是`file（当然，除了搜索以外通过 file 还可以做其他事情）`。

```
file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
```

*   `GLOB`: 将指定目录下搜索到的满足条件的所有文件名生成一个列表，并将其存储到变量中。
*   `GLOB_RECURSE`：递归搜索指定目录，将搜索到的满足条件的文件名生成一个列表，并将其存储到变量中。

**搜索当前目录的 src 目录下所有的源文件，并存储到变量中**

```
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
```

*   CMAKE_CURRENT_SOURCE_DIR 宏表示当前访问的 CMakeLists.txt 文件所在的路径。
    
*   关于要搜索的文件路径和类型可加双引号，也可不加:
    
    ```
    file(GLOB MAIN_HEAD "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
    ```
    

[](#2-4-包含头文件 "2.4 包含头文件")2.4 包含头文件
-----------------------------------

在编译项目源文件的时候，很多时候都需要将源文件对应的头文件路径指定出来，这样才能保证在编译过程中编译器能够找到这些头文件，并顺利通过编译。在 CMake 中设置要包含的目录也很简单，通过一个命令就可以搞定了，他就是`include_directories`:

```
include_directories(headpath)
```

举例说明，有源文件若干，其目录结构如下：

```
$ tree
.
├── build
├── CMakeLists.txt
├── include
│   └── head.h
└── src
    ├── add.cpp
    ├── div.cpp
    ├── main.cpp
    ├── mult.cpp
    └── sub.cpp

3 directories, 7 files
```

`CMakeLists.txt`文件内容如下:

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
set(CMAKE_CXX_STANDARD 11)
set(HOME /home/robin/Linux/calc)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin/)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(app  ${SRC_LIST})
```

其中，第六行指定就是头文件的路径，`PROJECT_SOURCE_DIR`宏对应的值就是我们在使用 cmake 命令时，后面紧跟的目录，一般是工程的根目录。

[](#2-5-制作动态库或静态库 "2.5 制作动态库或静态库")2.5 制作动态库或静态库
-----------------------------------------------

有些时候我们编写的源代码并不需要将他们编译生成可执行程序，而是生成一些静态库或动态库提供给第三方使用，下面来讲解在 cmake 中生成这两类库文件的方法。

### [](#2-5-1-制作静态库 "2.5.1 制作静态库")2.5.1 制作静态库

在 cmake 中，如果要制作静态库，需要使用的命令如下：

```
add_library(库名称 STATIC 源文件1 [源文件2] ...)
```

在 Linux 中，静态库名字分为三部分：`lib`+`库名字`+`.a`，此处只需要指定出库的名字就可以了，另外两部分在生成该文件的时候会自动填充。

在 Windows 中虽然库名和 Linux 格式不同，但也只需指定出名字即可。

下面有一个目录，需要将`src`目录中的源文件编译成静态库，然后再使用：

```
.
├── build
├── CMakeLists.txt
├── include           # 头文件目录
│   └── head.h
├── main.cpp          # 用于测试的源文件
└── src               # 源文件目录
    ├── add.cpp
    ├── div.cpp
    ├── mult.cpp
    └── sub.cpp
```

根据上面的目录结构，可以这样编写`CMakeLists.txt`文件:

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(calc STATIC ${SRC_LIST})
```

这样最终就会生成对应的静态库文件`libcalc.a`。

### [](#2-5-2-制作动态库 "2.5.2 制作动态库")2.5.2 制作动态库

在 cmake 中，如果要制作动态库，需要使用的命令如下：

```
add_library(库名称 SHARED 源文件1 [源文件2] ...)
```

在 Linux 中，动态库名字分为三部分：`lib`+`库名字`+`.so`，此处只需要指定出库的名字就可以了，另外两部分在生成该文件的时候会自动填充。

在 Windows 中虽然库名和 Linux 格式不同，但也只需指定出名字即可。

根据上面的目录结构，可以这样编写`CMakeLists.txt`文件:

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(calc SHARED ${SRC_LIST})
```

这样最终就会生成对应的动态库文件`libcalc.so`。

### [](#2-5-3-指定输出的路径 "2.5.3 指定输出的路径")2.5.3 指定输出的路径

#### [](#方式1-适用于动态库 "方式1 - 适用于动态库")方式 1 - 适用于动态库

对于生成的库文件来说和可执行程序一样都可以指定输出路径。`由于在Linux下生成的动态库默认是有执行权限的`，所以可以按照生成可执行程序的方式去指定它生成的目录：

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(calc SHARED ${SRC_LIST})
```

对于这种方式来说，其实就是通过`set`命令给`EXECUTABLE_OUTPUT_PATH`宏设置了一个路径，这个路径就是可执行文件生成的路径。

#### [](#方式2-都适用 "方式2 - 都适用")方式 2 - 都适用

由于在 Linux 下生成的静态库默认不具有可执行权限，所以在指定静态库生成的路径的时候就不能使用`EXECUTABLE_OUTPUT_PATH`宏了，而应该使用`LIBRARY_OUTPUT_PATH`，这个宏对应静态库文件和动态库文件都适用。

```
cmake_minimum_required(VERSION 3.0)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)



add_library(calc STATIC ${SRC_LIST})
```

[](#2-6-包含库文件 "2.6 包含库文件")2.6 包含库文件
-----------------------------------

在编写程序的过程中，可能会用到一些系统提供的动态库或者自己制作出的动态库或者静态库文件，cmake 中也为我们提供了相关的加载动态库的命令。

### [](#2-6-1-链接静态库 "2.6.1 链接静态库")2.6.1 链接静态库

```
src
├── add.cpp
├── div.cpp
├── main.cpp
├── mult.cpp
└── sub.cpp
```

现在我们把上面`src`目录中的`add.cpp、div.cpp、mult.cpp、sub.cpp`编译成一个静态库文件`libcalc.a`。[通过命令制作并使用静态链接库](https://subingwen.cn/linux/library/#1-1-%E7%94%9F%E6%88%90%E9%9D%99%E6%80%81%E9%93%BE%E6%8E%A5%E5%BA%93 "通过命令制作并使用静态链接库")

测试目录结构如下：

```
$ tree 
.
├── build
├── CMakeLists.txt
├── include
│   └── head.h
├── lib
│   └── libcalc.a     # 制作出的静态库的名字
└── src
    └── main.cpp

4 directories, 4 files
```

在 cmake 中，链接静态库的命令如下：

```
link_libraries(<static lib> [<static lib>...])
```

*   **参数 1**：指定出要链接的静态库的名字
    *   可以是全名 `libxxx.a`
    *   也可以是掐头（`lib`）去尾（`.a`）之后的名字 `xxx`
*   **参数 2-N**：要链接的其它静态库的名字

如果该静态库不是系统提供的（自己制作或者使用第三方提供的静态库）可能出现静态库找不到的情况，此时可以将静态库的路径也指定出来：

```
link_directories(<lib path>)
```

这样，修改之后的`CMakeLists.txt`文件内容如下:

```
cmake_minimum_required(VERSION 3.0)
project(CALC)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

link_libraries(calc)
add_executable(app ${SRC_LIST})
```

添加了第 8 行的代码，就可以根据参数指定的路径找到这个静态库了。

### [](#2-6-2-链接动态库 "2.6.2 链接动态库")2.6.2 链接动态库

在程序编写过程中，除了在项目中引入静态库，好多时候也会使用一些标准的或者第三方提供的一些动态库，关于动态库的制作、使用以及在内存中的加载方式和静态库都是不同的，在此不再过多赘述，如有疑惑请参考 [Linux 静态库和动态库](https://subingwen.cn/linux/library/ "Linux 静态库和动态库")

在`cmake`中链接动态库的命令如下:

```
target_link_libraries(
    <target> 
    <PRIVATE|PUBLIC|INTERFACE> <item>... 
    [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
```

*   **target**：指定要加载动态库的文件的名字
    
    *   该文件可能是一个源文件
    *   该文件可能是一个动态库文件
    *   该文件可能是一个可执行文件
*   **PRIVATE|PUBLIC|INTERFACE**：动态库的访问权限，默认为`PUBLIC`
    
    *   如果各个动态库之间没有依赖关系，无需做任何设置，三者没有没有区别，一般无需指定，使用默认的 PUBLIC 即可。
        
    *   `动态库的链接具有传递性`，如果动态库 A 链接了动态库 B、C，动态库 D 链接了动态库 A，此时动态库 D 相当于也链接了动态库 B、C，并可以使用动态库 B、C 中定义的方法。
        
        ```
        target_link_libraries(A B C)
        target_link_libraries(D A)
        ```
        
        *   `PUBLIC`：在 public 后面的库会被 Link 到前面的 target 中，并且里面的符号也会被导出，提供给第三方使用。
        *   `PRIVATE`：在 private 后面的库仅被 link 到前面的 target 中，并且终结掉，第三方不能感知你调了啥库
        *   `INTERFACE`：在 interface 后面引入的库不会被链接到前面的 target 中，只会导出符号。

#### [](#链接系统动态库 "链接系统动态库")链接系统动态库

动态库的链接和静态库是完全不同的：

*   静态库会在生成可执行程序的链接阶段被打包到可执行程序中，所以可执行程序启动，静态库就被加载到内存中了。
*   动态库在生成可执行程序的链接阶段**不会**被打包到可执行程序中，当可执行程序被启动并且调用了动态库中的函数的时候，动态库才会被加载到内存

因此，在`cmake`中指定要链接的动态库的时候，`应该将命令写到生成了可执行文件之后：`

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(app ${SRC_LIST})

target_link_libraries(app pthread)
```

在`target_link_libraries(app pthread)`中：

*   `app:` 对应的是最终生成的可执行程序的名字
*   `pthread`：这是可执行程序要加载的动态库，这个库是系统提供的线程库，全名为`libpthread.so`，在指定的时候一般会掐头（lib）去尾（.so）。

#### [](#链接第三方动态库 "链接第三方动态库")链接第三方动态库

现在，自己生成了一个动态库，对应的目录结构如下：

```
$ tree 
.
├── build
├── CMakeLists.txt
├── include
│   └── head.h            # 动态库对应的头文件
├── lib
│   └── libcalc.so        # 自己制作的动态库文件
└── main.cpp              # 测试用的源文件

3 directories, 4 files
```

假设在测试文件`main.cpp`中既使用了自己制作的动态库`libcalc.so`又使用了系统提供的线程库，此时`CMakeLists.txt`文件可以这样写：

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(app ${SRC_LIST})
target_link_libraries(app pthread calc)
```

在**第六行**中，`pthread、calc`都是可执行程序`app`要链接的动态库的名字。当可执行程序`app`生成之后并执行该文件，会提示有如下错误信息：

```
$ ./app 
./app: error while loading shared libraries: libcalc.so: cannot open shared object file: No such file or directory
```

这是因为可执行程序启动之后，去加载`calc`这个动态库，但是不知道这个动态库被放到了什么位置[解决动态库无法加载的问题](https://subingwen.cn/linux/library/#2-4-1-%E5%BA%93%E7%9A%84%E5%B7%A5%E4%BD%9C%E5%8E%9F%E7%90%86 "解决动态库无法加载的问题")，所以就加载失败了，在 CMake 中可以在生成可执行程序之前，通过命令指定出要链接的动态库的位置，指定静态库位置使用的也是这个命令：

```
link_directories(path)
```

所以修改之后的`CMakeLists.txt`文件应该是这样的：

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(app ${SRC_LIST})

target_link_libraries(app pthread calc)
```

通过`link_directories`指定了动态库的路径之后，在执行生成的可执行程序的时候，就不会出现找不到动态库的问题了。

温馨提示：使用 target_link_libraries 命令就可以链接动态库，也可以链接静态库文件。

[](#2-7-日志 "2.7 日志")2.7 日志
--------------------------

在 CMake 中可以用用户显示一条消息，该命令的名字为`message`：

```
message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] "message to display" ...)
```

*   `(无)` ：重要消息
*   `STATUS` ：非重要消息
*   `WARNING`：CMake 警告, 会继续执行
*   `AUTHOR_WARNING`：CMake 警告 (dev), 会继续执行
*   `SEND_ERROR`：CMake 错误, 继续执行，但是会跳过生成的步骤
*   `FATAL_ERROR`：CMake 错误, 终止所有处理过程

CMake 的命令行工具会在 stdout 上显示`STATUS`消息，在 stderr 上显示其他所有消息。CMake 的 GUI 会在它的 log 区域显示所有消息。

CMake 警告和错误消息的文本显示使用的是一种简单的标记语言。文本没有缩进，超过长度的行会回卷，段落之间以新行做为分隔符。

```
message(STATUS "source path: ${PROJECT_SOURCE_DIR}")

message(WARNING "source path: ${PROJECT_SOURCE_DIR}")

message(FATAL_ERROR "source path: ${PROJECT_SOURCE_DIR}")
```

[](#2-8-变量操作 "2.8 变量操作")2.8 变量操作
--------------------------------

### [](#2-8-1-追加 "2.8.1 追加")2.8.1 追加

有时候项目中的源文件并不一定都在同一个目录中，但是这些源文件最终却需要一起进行编译来生成最终的可执行文件或者库文件。如果我们通过`file`命令对各个目录下的源文件进行搜索，最后还需要做一个字符串拼接的操作，关于字符串拼接可以使用`set`命令也可以使用`list`命令。

#### [](#使用set拼接 "使用set拼接")使用 set 拼接

如果使用 set 进行字符串拼接，对应的命令格式如下：

```
set(变量名1 ${变量名1} ${变量名2} ...)
```

关于上面的命令其实就是将从第二个参数开始往后所有的字符串进行拼接，最后将结果存储到第一个参数中，如果第一个参数中原来有数据会对原数据就行覆盖。

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
set(TEMP "hello,world")
file(GLOB SRC_1 ${PROJECT_SOURCE_DIR}/src1/*.cpp)
file(GLOB SRC_2 ${PROJECT_SOURCE_DIR}/src2/*.cpp)

set(SRC_1 ${SRC_1} ${SRC_2} ${TEMP})
message(STATUS "message: ${SRC_1}")
```

#### [](#使用list拼接 "使用list拼接")使用 list 拼接

如果使用 list 进行字符串拼接，对应的命令格式如下：

```
list(APPEND <list> [<element> ...])
```

`list`命令的功能比`set`要强大，字符串拼接只是它的其中一个功能，所以需要在它第一个参数的位置指定出我们要做的操作，`APPEND`表示进行数据追加，后边的参数和`set`就一样了。

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
set(TEMP "hello,world")
file(GLOB SRC_1 ${PROJECT_SOURCE_DIR}/src1/*.cpp)
file(GLOB SRC_2 ${PROJECT_SOURCE_DIR}/src2/*.cpp)

list(APPEND SRC_1 ${SRC_1} ${SRC_2} ${TEMP})
message(STATUS "message: ${SRC_1}")
```

在 CMake 中，使用`set`命令可以创建一个`list`。一个在`list`内部是一个由`分号;`分割的一组字符串。例如，`set(var a b c d e)`命令将会创建一个`list:a;b;c;d;e`，但是最终打印变量值的时候得到的是`abcde`。

```
set(tmp1 a;b;c;d;e)
set(tmp2 a b c d e)
message(${tmp1})
message(${tmp2})
```

输出的结果:

```
abcde
abcde
```

### [](#2-8-2-字符串移除 "2.8.2 字符串移除")2.8.2 字符串移除

我们在通过`file`搜索某个目录就得到了该目录下所有的源文件，但是其中有些源文件并不是我们所需要的，比如：

```
$ tree
.
├── add.cpp
├── div.cpp
├── main.cpp
├── mult.cpp
└── sub.cpp

0 directories, 5 files
```

在当前这么目录有五个源文件，其中`main.cpp`是一个测试文件。如果我们想要把计算器相关的源文件生成一个动态库给别人使用，那么只需要`add.cpp、div.cp、mult.cpp、sub.cpp`这四个源文件就可以了。此时，就需要将`main.cpp`从搜索到的数据中剔除出去，想要实现这个功能，也可以使用`list`

```
list(REMOVE_ITEM <list> <value> [<value> ...])
```

通过上面的命令原型可以看到删除和追加数据类似，只不过是第一个参数变成了`REMOVE_ITEM`。

```
cmake_minimum_required(VERSION 3.0)
project(TEST)
set(TEMP "hello,world")
file(GLOB SRC_1 ${PROJECT_SOURCE_DIR}/*.cpp)

message(STATUS "message: ${SRC_1}")

list(REMOVE_ITEM SRC_1 ${PROJECT_SOURCE_DIR}/main.cpp)

message(STATUS "message: ${SRC_1}")
```

可以看到，在`第8行`把将要移除的文件的名字指定给`list`就可以了。但是一定要注意通过 file 命令搜索源文件的时候得到的是文件的绝对路径（在 list 中每个文件对应的路径都是一个 item，并且都是绝对路径），那么在移除的时候也要将该文件的绝对路径指定出来才可以，否是移除操作不会成功。

关于`list`命令还有其它功能，但是并不常用，在此就不一一进行举例介绍了。

1.  获取 list 的长度。
    
    ```
    list(LENGTH <list> <output variable>)
    ```
    
    *   `LENGTH`：子命令 LENGTH 用于读取列表长度
    *   `<list>`：当前操作的列表
    *   `<output variable>`：新创建的变量，用于存储列表的长度。
2.  读取列表中指定索引的的元素，可以指定多个索引
    
    ```
    list(GET <list> <element index> [<element index> ...] <output variable>)
    ```
    
    *   `<list>`：当前操作的列表
    *   `<element index>`：列表元素的索引
        *   从 0 开始编号，索引 0 的元素为列表中的第一个元素；
        *   索引也可以是负数，`-1`表示列表的最后一个元素，`-2`表示列表倒数第二个元素，以此类推
        *   当索引（不管是正还是负）超过列表的长度，运行会报错
    *   `<output variable>`：新创建的变量，存储指定索引元素的返回结果，也是一个列表。
3.  将列表中的元素用连接符（字符串）连接起来组成一个字符串
    
    ```
    list (JOIN <list> <glue> <output variable>)
    ```
    
    *   `<list>`：当前操作的列表
    *   `<glue>`：指定的连接符（字符串）
    *   `<output variable>`：新创建的变量，存储返回的字符串
4.  查找列表是否存在指定的元素，若果未找到，返回 - 1
    
    ```
    list(FIND <list> <value> <output variable>)
    ```
    
    *   `<list>`：当前操作的列表
    *   `<value>`：需要再列表中搜索的元素
    *   `<output variable>`：新创建的变量
        *   如果列表`<list>`中存在`<value>`，那么返回`<value>`在列表中的索引
        *   如果未找到则返回 - 1。
5.  将元素追加到列表中
    
    ```
    list (APPEND <list> [<element> ...])
    ```
    
6.  在 list 中指定的位置插入若干元素
    
    ```
    list(INSERT <list> <element_index> <element> [<element> ...])
    ```
    
7.  将元素插入到列表的 0 索引位置
    
    ```
    list (PREPEND <list> [<element> ...])
    ```
    
8.  将列表中最后元素移除
    
    ```
    list (POP_BACK <list> [<out-var>...])
    ```
    
9.  将列表中第一个元素移除
    
    ```
    list (POP_FRONT <list> [<out-var>...])
    ```
    
10.  将指定的元素从列表中移除
        
    ```
    list (REMOVE_ITEM <list> <value> [<value> ...])
    ```
    
11.  将指定索引的元素从列表中移除
        
    ```
    list (REMOVE_AT <list> <index> [<index> ...])
    ```
    
12.  移除列表中的重复元素
        
    ```
    list (REMOVE_DUPLICATES <list>)
    ```
    
13.  列表翻转
        
    ```
    list(REVERSE <list>)
    ```
    
14.  列表排序
        
    ```
    list (SORT <list> [COMPARE <compare>] [CASE <case>] [ORDER <order>])
    ```
    
    *   `COMPARE`：指定排序方法。有如下几种值可选：
        *   `STRING`: 按照字母顺序进行排序，为默认的排序方法
        *   `FILE_BASENAME`：如果是一系列路径名，会使用 basename 进行排序
        *   `NATURAL`：使用自然数顺序排序
    *   `CASE`：指明是否大小写敏感。有如下几种值可选：
        *   `SENSITIVE`: 按照大小写敏感的方式进行排序，为默认值
        *   `INSENSITIVE`：按照大小写不敏感方式进行排序
    *   `ORDER`：指明排序的顺序。有如下几种值可选：
        *   `ASCENDING`: 按照升序排列，为默认值
        *   `DESCENDING`：按照降序排列

[](#2-9-宏定义 "2.9 宏定义")2.9 宏定义
-----------------------------

在进行程序测试的时候，我们可以在代码中添加一些宏定义，通过这些宏来控制这些代码是否生效，如下所示：

```
#include <stdio.h>
#define NUMBER  3

int main()
{
    int a = 10;
#ifdef DEBUG
    printf("我是一个程序猿, 我不会爬树...\n");
#endif
    for(int i=0; i<NUMBER; ++i)
    {
        printf("hello, GCC!!!\n");
    }
    return 0;
}
```

在程序的第七行对`DEBUG`宏进行了判断，如果该宏被定义了，那么第八行就会进行日志输出，如果没有定义这个宏，第八行就相当于被注释掉了，因此最终无法看到日志输入出（**上述代码中并没有定义这个宏**）。

为了让测试更灵活，我们可以不在代码中定义这个宏，而是在测试的时候去把它定义出来，其中一种方式就是在`gcc/g++`命令中去指定，如下：

```
$ gcc test.c -DDEBUG -o app
```

在`gcc/g++`命令中通过参数 `-D`指定出要定义的宏的名字，这样就相当于在代码中定义了一个宏，其名字为`DEBUG`。

在`CMake`中我们也可以做类似的事情，对应的命令叫做`add_definitions`:

```
add_definitions(-D宏名称)
```

针对于上面的源文件编写一个`CMakeLists.txt`，内容如下：

```
cmake_minimum_required(VERSION 3.0)
project(TEST)

add_definitions(-DDEBUG)
add_executable(app ./test.c)
```

通过这种方式，上述代码中的第八行日志就能够被输出出来了。

下面的列表中为大家整理了一些`CMake`中常用的宏：

<table><thead><tr><th>宏</th><th>功能</th></tr></thead><tbody><tr><td>PROJECT_SOURCE_DIR</td><td>使用 cmake 命令后紧跟的目录，一般是工程的根目录</td></tr><tr><td>PROJECT_BINARY_DIR</td><td><sr-annote data-id="1713756637376" data-color-type="1" sr-annote-bg-color="true">执行 cmake 命令的目录</sr-annote></td></tr><tr><td>CMAKE_CURRENT_SOURCE_DIR</td><td><sr-annote data-id="1713756675897" data-color-type="1" sr-annote-bg-color="true">当前处理的 CMakeLists.txt 所在的路径</sr-annote></td></tr><tr><td>CMAKE_CURRENT_BINARY_DIR</td><td>target 编译目录</td></tr><tr><td>EXECUTABLE_OUTPUT_PATH</td><td>重新定义目标二进制可执行文件的存放位置</td></tr><tr><td>LIBRARY_OUTPUT_PATH</td><td>重新定义目标链接库文件的存放位置</td></tr><tr><td>PROJECT_NAME</td><td>返回通过 PROJECT 指令定义的项目名称</td></tr><tr><td>CMAKE_BINARY_DIR</td><td>项目实际构建路径，假设在<code>build</code>目录进行的构建，那么得到的就是这个目录的路径</td></tr></tbody></table>

[img-0]:data:image/png;base64,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