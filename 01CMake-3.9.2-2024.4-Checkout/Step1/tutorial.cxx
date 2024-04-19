#include <iostream>    // 输入输出 , std 所使用 - 内置 尖括号
#include <string>       // 字符串使用
#include <cmath>
#include "CMakeTutorialConfig.h"          // 头文件机制 - 自定义 引号 引用

/* 参数 两个*/
int main(int argc, char* argv[])
{
  //  无参 -- 打印版本信息 
  if (argc < 2) {
      std::cout << argv[0] << "Version" << Tutorial_VERSION_MAJOR  "."
          << Tutorial_VERSION_MINOR  std::endl;
      std::cout << "Usage: " << argv[0] << " number" << std::endl;
      std::cout << "_cplusplus: " << __cplusplus << std::endl;
      std::cout << "Tutorial_VERSION_MAJOR: " << Tutorial_VERSION_MAJOR   std::endl;
      std::cout << "Tutorial_VERSION_MINOR: " << Tutorial_VERSION_MINOR  std::endl;
      std::cout << "STR_TEST: " << STR_TEST << std::endl;

    return 1;
  }
  // 仅有一个参数  求平方根
  //const double inputValue = std::stod(argv[1]);
 // const double outputValue = sqrt(inputValue);
 // std::cout << "The square root of " << inputValue << " is " << outputValue
 //           << std::endl;

  return 0;
}
