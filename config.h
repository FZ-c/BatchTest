#pragma once

#include<string>
#include<fstream>
#include <map>
#include "config_template.h"


//���ļ�·���е��ļ���ȥ��
inline std::string get_filepath(std::string path) {
	return path.substr(0, path.find_last_of('\\'));
}

class JudgeConfig {
public:
	JudgeConfig(const std::string& config_fie_path="config.properties") {
		std::ifstream config_file_stream;
		config_file_stream.open(config_fie_path.c_str(), std::ios::in);
		if (config_file_stream.is_open()) {
			//TODO:��ȡ�����ļ�����
			std::string pro_inf[3];
			
		}
		else {
			//�����ļ������� �½�Ĭ������
			//����·��Ϊ��ǰ·��
			//TODO:�����ļ�·��Ϊ��ǰ·����data�ļ����� ���������½�
			//TODO:�����ļ���Ĭ��Ϊcode.cpp ���������½�
			std::string pro_inf[][3] = {
				{"code_path","","���Դ���·��"},
				{"data_path","","��������·��"},
				{"code_file_name","","��������ļ���"}
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
			//TODO:�ļ�����ʧ�� ����
		}
		else{
			std::string out_inf = __config_template;
			for(auto &inf:properties){
				config_file_write << "# " << inf.second.getNote() << "\n";
				config_file_write << inf.first << "=" << inf.second.getValue() << "\n";
			}
			config_file_write.close();
			//TODO:����ɹ������ʾ
		}
	}
protected:
	std::map<std::string, Properties>properties;
};

