# CMakeTutorialCXX20
该仓库用来学习  CMake的语法 , 在CXX20的基础上进行学习和使用 ; 





参照 文档 食用 更佳  

使用Typora 和 XMind 打开 doc文件夹中的教程



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

# 待办清单



1. 参考 B站 双生 ** 的 CMake 教学 和 C++项目 ,以及  
   https://modern-cmake-cn.github.io/Modern-CMake-zh_CN/chapters/basics/example.html,以及 GitHub上面的 优秀的  范例 
2. 学习  B站 的Up主的 模块化 划分,方便 组织 
3. 学习 C++20 的编写, 
4. 首要推进的项目是   数据结构 和算法, 设计模式  等基础的技能,  多去参考 GitHub上已有  优秀的代码文件,  学习之后, 尝试编写 新的库 
5. 下半年 进入状态后, 尝试 编写小Demo ; 
6. 整理 出 yaml 的编写 教程, 拓展 出  Mac , Linux, Windows 三个平台的 代码编译版本;  提供 更多的 可能性 
7. CMake   尝试 编写 自己的自动化测试 算法库, 边界测试 
8. 对  边缘计算 和  底层的 进行学习 







---

规则 

1. 开源框架 使用  子模块方式 ;其他 只读 仓库不建议使用子模块-->  因为 教材类需要二次学习 和 修改,  而 原仓库 无更新,直接在自己的仓库内进行操作 
1. 当前正在 更新的 仓库  fork到自己的仓库, 借助  自己 可 同步远程  仓库, 可以合并到自己的仓库中 ,  自己掌控和 可合并到自己的 子模块中 ,保证  对方进度可 跟进,  自己的 笔记不丢失不覆盖 
