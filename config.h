#pragma once

#include<string>
#include<fstream>
#include <map>
#include "config_template.h"


//将文件路径中的文件名去掉
inline std::string get_filepath(std::string path) {
	return path.substr(0, path.find_last_of('\\'));
}

class JudgeConfig {
public:
	JudgeConfig(const std::string& config_fie_path="config.properties") {
		std::ifstream config_file_stream;
		config_file_stream.open(config_fie_path.c_str(), std::ios::in);
		if (config_file_stream.is_open()) {
			//TODO:读取配置文件内容
			std::string pro_inf[3];
			
		}
		else {
			//配置文件不存在 新建默认配置
			//代码路径为当前路径
			//TODO:数据文件路径为当前路径的data文件夹内 若不存在新建
			//TODO:代码文件名默认为code.cpp 若不存在新建
			std::string pro_inf[][3] = {
				{"code_path","","测试代码路径"},
				{"data_path","","测试数据路径"},
				{"code_file_name","","待测代码文件名"}
			};
			pro_inf[0][1] = get_filepath(static_cast<std::string>(_pgmptr));
			pro_inf[1][1] = pro_inf[0][1] + "\\data";
			pro_inf[2][1] = "code.cpp";
			for (auto& inf : pro_inf)
				properties.insert(std::make_pair(inf[0], Properties{ inf }));
			output_config();
		}
		config_file_stream.close();
	}
	void output_config() {
		std::fstream config_file_write;
		config_file_write.open("config.properties", std::ios::out);
		if(!config_file_write.is_open()){
			//TODO:文件创建失败 报错
		}
		else{
			std::string out_inf = __config_template;
			for(auto &inf:properties){
				config_file_write << "# " << inf.second.getNote() << "\n";
				config_file_write << inf.first << "=" << inf.second.getValue() << "\n";
			}
			config_file_write.close();
			//TODO:输出成功结果提示
		}
	}
protected:
	std::map<std::string, Properties>properties;
};

