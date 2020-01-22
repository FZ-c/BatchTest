// ReSharper disable CppClangTidyClangDiagnosticInvalidSourceEncoding
#pragma once

#include<string>
#include <utility>

/**
 * \配置文件模板
 */
const std::string __config_template = "\
# 测试代码路径\n\
code_path=%code_path%\n\
# 测试数据路径\n\
data_path=%data_path%\n\
# 待测代码文件名\n\
code_file_name=%code_file_name%\n";


class Properties{
public:
	Properties(std::string key = "", std::string value = "", std::string note = "") :
		key(std::move(key)), value(std::move(value)), note(std::move(note)) {};
	Properties(std::string pro_inf[3]) :
		key(pro_inf[0]), value(pro_inf[1]), note(pro_inf[2]) {};
	void setValue(std::string value) { this->value = std::move(value); }
	void setNote(std::string note) { this->note = std::move(note); }
	std::string getKey() const { return key; }
	std::string getValue() const { return value; }
	std::string getNote() const { return note; }
protected:
	const std::string key;
	std::string value;
	std::string note;
};
