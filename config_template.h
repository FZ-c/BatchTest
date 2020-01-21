// ReSharper disable CppClangTidyClangDiagnosticInvalidSourceEncoding
#pragma once

#include<string>

/**
 * \配置文件模板
 */
const std::string __config_template = "\
# 测试代码路径\n\
code_path: %code_path%\n\
# 测试数据路径\n\
data_path: %data_path%\n\
# 待测代码文件名\n\
code_file_name: %code_file_name%\n";