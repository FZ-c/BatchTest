
#include<iostream>
#include"config.h"

using namespace std;

enum {
	Accepted,
	WrongAnswer,
	TimeLimitExceeded,
	MemoryLimitExceeded,
	RuntimeError,
	PresentationError,
	OutputLimitError,
	CompileError
}Result;

int main() {
	JudgeConfig judge;
	cout << judge.code_path << "\n" << judge.data_path<<"\n"<<judge.code_file_name;
	judge.output_config();
	return 0;
}