#pragma once

#include<string>
#include<fstream>
#include <map>
#include "config_template.h"


//将文件路径中的文件名去掉
std::string get_filepath(std::string path) {
	int pos = path.find_last_of('\\');
	return path.substr(0, pos);
}

class JudgeConfig {
public:
	std::map<std::string, std::string>properties;
	//待测代码路径 文件夹
	std::string code_path;
	//测试数据路径 文件夹
	std::string data_path;
	//待测代码文件名
	std::string code_file_name;
	JudgeConfig(const std::string& config_fie_path="config.properties") {
		std::ifstream config_file_stream;
		config_file_stream.open(config_fie_path.c_str(), std::ios::in);
		if (config_file_stream.is_open()) {
			//TODO: 文件存在 读取配置
		}
		else {
			//配置文件不存在 新建默认配置
			//代码路径为当前路径
			//数据文件路径为当前路径的data文件夹内 若不存在新建
			//代码文件名默认为code.cpp
			code_path = get_filepath(static_cast<std::string>(_pgmptr));
			data_path = code_path + "\\data";
			code_file_name = "code.cpp";
		}
	}
	void output_config() {
		std::fstream config_file_write;
		config_file_write.open("config.properties", std::ios::out);
		if(!config_file_write.is_open()){
			//TODO:文件创建失败 报错
		}
		else{
			std::string out_inf = __config_template;
			out_inf.replace(out_inf.find("%code_path%"), strlen("%code_path%"), code_path);
			out_inf.replace(out_inf.find("%data_path%"), strlen("%data_path%"), data_path);
			out_inf.replace(out_inf.find("%code_file_name%"), strlen("%code_file_name%"), code_file_name);
			config_file_write << out_inf;
			config_file_write.close();
			//TODO:输出成功结果提示
		}
	}
};

