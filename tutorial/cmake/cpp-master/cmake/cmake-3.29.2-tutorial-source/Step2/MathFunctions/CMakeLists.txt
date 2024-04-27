# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
# Hint: You will need the add_library command
#---------------- 需强调  在此处 所 引用的 均是 相对 该层CMakeLists.txt而言的, .表示当前文件夹   若只在当前文件夹, 可省略----
#[[方法一 ,手动维护
add_library(MathFunctions  mysqrt.cxx ; MathFunctions.h)

]]
#[[方法二 ,手动维护 -- 进阶 变量维护 
set(Lib_SRC_MathFuc mysqrt.cxx ; MathFunctions.h)
add_library(MathFunctions  ${Lib_SRC_MathFuc})
]]


# TODO 7: Create a variable USE_MYMATH using option and set default to ON

# TODO 8: If USE_MYMATH is ON, use target_compile_definitions to pass
# USE_MYMATH as a precompiled definition to our source files

# TODO 12: When USE_MYMATH is ON, add a library for SqrtLibrary with
# source mysqrt.cxx

# TODO 13: When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
