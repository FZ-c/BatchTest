#pragma once

#include<string>
#include<fstream>
#include <map>
#include "config_template.h"


//���ļ�·���е��ļ���ȥ��
std::string get_filepath(std::string path) {
	int pos = path.find_last_of('\\');
	return path.substr(0, pos);
}

class JudgeConfig {
public:
	std::map<std::string, std::string>properties;
	//�������·�� �ļ���
	std::string code_path;
	//��������·�� �ļ���
	std::string data_path;
	//��������ļ���
	std::string code_file_name;
	JudgeConfig(const std::string& config_fie_path="config.properties") {
		std::ifstream config_file_stream;
		config_file_stream.open(config_fie_path.c_str(), std::ios::in);
		if (config_file_stream.is_open()) {
			//TODO: �ļ����� ��ȡ����
		}
		else {
			//�����ļ������� �½�Ĭ������
			//����·��Ϊ��ǰ·��
			//�����ļ�·��Ϊ��ǰ·����data�ļ����� ���������½�
			//�����ļ���Ĭ��Ϊcode.cpp
			code_path = get_filepath(static_cast<std::string>(_pgmptr));
			data_path = code_path + "\\data";
			code_file_name = "code.cpp";
		}
	}
	void output_config() {
		std::fstream config_file_write;
		config_file_write.open("config.properties", std::ios::out);
		if(!config_file_write.is_open()){
			//TODO:�ļ�����ʧ�� ����
		}
		else{
			std::string out_inf = __config_template;
			out_inf.replace(out_inf.find("%code_path%"), strlen("%code_path%"), code_path);
			out_inf.replace(out_inf.find("%data_path%"), strlen("%data_path%"), data_path);
			out_inf.replace(out_inf.find("%code_file_name%"), strlen("%code_file_name%"), code_file_name);
			config_file_write << out_inf;
			config_file_write.close();
			//TODO:����ɹ������ʾ
		}
	}
};

