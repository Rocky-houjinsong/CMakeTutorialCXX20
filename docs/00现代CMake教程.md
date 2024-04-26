# 优秀的CMake编写



## 范例





## 原则

* :x:  硬编码





# 个人CMake 项目结构 习惯

---



```powershell

```





# 碎片知识 待整理 



*  手动指定 若干cpp文件, 文件之间 可使用 `;` 或 `空格`  来 区分, 可优化为 使用变量 和 文件检索  批量获取特定源文件 --  非 硬编码  
* 新建 和 在 build文件夹中 进行构建和生成     目的是为了 将 中间文件 和 代码源文件 作区分   
* 调试 和 发布两种模式 , 可手动指定  ;  
* 如果在CMakeLists.txt文件所在目录执行了cmake命令之后就会生成一些目录和文件（包括 makefile 文件），如果再基于makefile文件执行make命令，程序在编译过程中还会生成一些中间文件和一个可执行文件，这样会导致整个项目目录看起来很混乱，不太容易管理和维护，此时我们就可以把生成的这些与项目源码无关的文件统一放到一个对应的目录里边，比如将这个目录命名为build:
* cmake命令是在build目录中执行的，但是CMakeLists.txt文件是build目录的上一级目录中，所以cmake 命令后指定的路径为..，即当前目录的上一级目录
* 在CMake中想要指定C++标准有两种方式

  *  CMakeLists.txt 中通过 set 命令指定\
  *  执行 cmake 命令的时候指定出这个宏的值  cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=17

*  由于可执行程序是基于 cmake 命令生成的 makefile 文件然后再执行 make 命令得到的，所以如果此处指定可执行程序生成路径的时候使用的是相对路径 ./xxx/xxx，那么这个路径中的 ./ 对应的就是 makefile 文件所在的那个目录

*  搜索文件
   
*   重复导入路径 报错 -->  googletest  git子模块验证存在后 添加  和   启用 test功能添加 都是同一个路径 重复添加 报错  
   
*  
   
*  
   *  CMake 中使用aux_source_directory 命令可以查找某个路径下的所有源文件，命令格式为  aux_source_directory(< dir > < variable >)





# CMake教程

在 linux 平台下使用 CMake 生成 Makefile 并编译的流程如下：

1. 写 CMake 配置文件 CMakeLists.txt 。
2. 执行命令 `cmake PATH` 或者 `ccmake PATH` 生成 Makefile（`ccmake` 和 `cmake` 的区别在于前者提供了一个交互式的界面）。其中， `PATH` 是 CMakeLists.txt 所在的目录。
3. 使用 `make` 命令进行编译。



双生  

