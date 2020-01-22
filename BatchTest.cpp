
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
	judge.output_config();
	return 0;
}