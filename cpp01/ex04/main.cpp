#include <fstream>
#include <iostream>
#include <string>

std::string FtReplace(std::string& text, std::string& s1, std::string& s2)
{
	std::string newText;
	std::size_t pos = 0, oldPos = 0;

	if (s1.empty())
		return text;
	while ((pos = text.find(s1, pos)) != std::string::npos)
	{
		newText += text.substr(oldPos, pos - oldPos) + s2;
		pos += s1.length();
		oldPos = pos;
	}
	newText += text.substr(oldPos, text.length() - oldPos);

	return newText;
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong arguement number, required 3" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cout << "Error opening file" << std::endl;
		inFile.close();
		return 1;
	}
	std::string text, line;
	while (std::getline(inFile, line))
		text += line + "\n";
	if (!inFile.eof())
	{
		std::cout << "Error reading file" << std::endl;
		inFile.close();
		return 1;
	}
	inFile.close();

	std::string newText = FtReplace(text, s1, s2);

	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile)
	{
		std::cout << "Error opening file" << std::endl;
		outFile.close();
		return 1;
	}
	outFile << newText;
	outFile.close();
	return 0;
}
