#include <iostream>
#include <fstream>
#include <string>

#define lineCounts 15000

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	std::ofstream outFile("判断质数.cpp");

	if (!outFile) {
		std::cerr << "Error: Unable to create file." << std::endl;
		return 1;
	}

	outFile << "#include <iostream>\n\n";
	outFile << "int main() {\n";
	outFile << "    int num;\n";
	outFile << "    std::cout << \"请输入一个数 (0-" << lineCounts << "): \";\n";
	outFile << "    std::cin >> num;\n";
	outFile << "    if (num < 0 || num > " << lineCounts << ") {\n";
	outFile << "        std::cout << \"您输入的数不在符合条件的范围内。\";\n";
	outFile << "        return 1;\n";
	outFile << "    }\n";

	for (int i = 0; i <= lineCounts; ++i) {
		outFile << "    else if (num == " << std::to_string(i) << ") {\n";
		outFile << "        std::cout << \"" << std::to_string(i);
		if (isPrime(i)) {
			outFile << " 是一个质数。\";\n";
		} else {
			outFile << " 不是一个质数。\";\n";
		}
		outFile << "    }\n";
	}

	outFile << "    return 0;\n";
	outFile << "}\n";

	outFile.close();

	std::cout << "判断质数.cpp 生成成功。\n";

	return 0;
}

