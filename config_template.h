// ReSharper disable CppClangTidyClangDiagnosticInvalidSourceEncoding
#pragma once

#include<string>
#include <utility>

/**
 * \�����ļ�ģ��
 */
const std::string __config_template = "\
# ���Դ���·��\n\
code_path=%code_path%\n\
# ��������·��\n\
data_path=%data_path%\n\
# ��������ļ���\n\
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
