#ifndef DESCRIPTION_FILE_PARSER_H
#define DESCRIPTION_FILE_PARSER_H

#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Scene.hpp"
#include "Sphere.hpp"
#include "Model.hpp"


class DescriptionFileParser
{
private:
	std::string _descriptionFileName;
	std::vector<std::string> _blocksString;

	Scene _sceneToReturn;

public:
	DescriptionFileParser();
	DescriptionFileParser(std::string fileName);

	~DescriptionFileParser();

	inline Scene getScene() const
	{
		return _sceneToReturn;
	}

	void parseFile();
	void convertStringsToBlocks();
	void convertStringToBlock(std::string blockString);

	void displayBlocks() const;

	Transform DescriptionFileParser::parseTransformBlock(std::string blockString);
	Model parseModelBlock(std::string blockString);
	Camera parseCameraBlock(std::string blockString);
	Sphere DescriptionFileParser::parseSphereBlock(std::string blockString);
	void parseLightBlock(std::string blockString);
	void parseObjectBlock(std::string blockString);
};

bool stringStartWith(std::string stringToTest, std::string stringToFind);
int stringSplit(std::vector<std::string>& tokens, std::string stringToSplit, std::string delimiter);

template <typename T>
T parseLine(std::string line)
{
	//std::vector<std::string> values;
	//stringSplit(values, line, " ");

	//if(std::is_same<T, int>::value)
	//{
	//	return std::stoi(values[values.size()]);
	//}
	//else if(std::is_same<T, float>::value)
	//{
	//	return std::stof(values[values.size()]);
	//}
	//else if(std::is_same<T, std::string>::value)
	//{
	//	std::string stringToReturn(values[1]);
	//	return stringToReturn;
	//}
	//else if(std::is_same<T, Vec3d>::value)
	//{
	//	Vec3d vecToReturn(std::stof(values[1]), std::stof(values[2]), std::stof(values[3]));
	//	return vecToReturn;
	//}
};

template <>
int parseLine<int>(std::string line);

template <>
float parseLine<float>(std::string line);

template <>
Vec3d parseLine<Vec3d>(std::string line);

template <>
std::string parseLine<std::string>(std::string line);

#endif