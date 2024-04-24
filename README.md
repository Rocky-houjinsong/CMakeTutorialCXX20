# CMakeTutorialCXX20
该仓库用来学习  CMake的语法 , 在CXX20的基础上进行学习和使用 ; 





参照 文档 食用 更佳  

使用Typora 和 XMind 打开 



---



该仓库的初始版本 是 3.29.2版本;

之后若无重大更新则是 在当前版本上 的语法微调 



```powershell
├─.github
│  └─workflows   #工作流 GitHub Action , CI/ID使用  保证提交的代码 可以正常 合并到主分支
├─apps
├─build			# Cmake 生成的中间路径，存放编译生成的文件
├─docs
├─extern		# 第三方依赖项目文件
├─include		# 本项目中的头文件
├─out			# 本项目编译生成的可执行文件、库文件等
├─scripts
├─src			# 本项目中的源文件，(包含 CMakeLists.txt 文件)
└─tests			# 本项目测试代码路径，(包含 CMakeLists.txt 文件)

build.sh 脚本为基于 CMake 的编译脚本
CMakeLists.txt 为项目根路径上的 CMake 配置文件
util 文件 是 帮助类 
tool ??  

```

