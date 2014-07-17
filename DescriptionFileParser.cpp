#include "DescriptionFileParser.hpp"

DescriptionFileParser::DescriptionFileParser()
{

}

DescriptionFileParser::DescriptionFileParser(std::string fileName) : _descriptionFileName(fileName)
{

}

DescriptionFileParser::~DescriptionFileParser()
{
}

void DescriptionFileParser::parseFile()
{
	std::ifstream file(_descriptionFileName, std::ios::in);

	if(file)
	{
		std::string currentLine;
		std::string currentBlock;
		bool isBlockWriting = false;
		while(std::getline(file, currentLine))
		{
			if(!stringStartWith(currentLine, "#"))
			{
				if(stringStartWith(currentLine, "model")
					|| stringStartWith(currentLine, "light")
					|| stringStartWith(currentLine, "camera")
					|| stringStartWith(currentLine, "object"))
				{
					isBlockWriting = true;
					currentBlock += currentLine + "\n";
				}
				else if(stringStartWith(currentLine, "end"))
				{
					_blocksString.push_back(currentBlock);
					currentBlock = "";
					isBlockWriting = false;
				}
				else if(isBlockWriting)
				{
					currentBlock += currentLine + "\n";
				}
			}
		}

		file.close();

		convertStringsToBlocks();

	}
	else
	{
		std::cerr << "Impossible to open file !" << std::endl;
	}
}

void DescriptionFileParser::displayBlocks() const
{
	for(size_t nbBlocks = 0; nbBlocks < _blocksString.size(); nbBlocks++)
	{
		std::cout << _blocksString[nbBlocks] << std::endl;
		std::cout << std::endl;
	}
}

void DescriptionFileParser::convertStringToBlock(std::string blockString)
{
	if(stringStartWith(blockString, "model"))
	{
		_sceneToReturn.setModel(parseModelBlock(blockString));
	}
	else if(stringStartWith(blockString, "camera"))
	{
		Camera cam = parseCameraBlock(blockString);
		_sceneToReturn.addCamera(cam);
	}
	else if(stringStartWith(blockString, "light"))
	{

	}
	else if(stringStartWith(blockString, "object"))
	{
		std::istringstream stringStream(blockString);
		std::string line;
		std::getline(stringStream, line);
		if("sphere" == parseLine<std::string>(line))
		{
			Sphere *sph = parseSphereBlock(blockString);
			_sceneToReturn.addShape(sph);
		}
	}
}

void DescriptionFileParser::convertStringsToBlocks()
{
	for(size_t nbBlocks = 0; nbBlocks < _blocksString.size(); nbBlocks++)
	{
		convertStringToBlock(_blocksString[nbBlocks]);
	}

	//sceneToReturn.getModelBlock().displayBlock();
}


Model DescriptionFileParser::parseModelBlock(std::string blockString)
{
	std::istringstream stringStream(blockString);
	std::string line;
	Model modelToAdd;
	while(std::getline(stringStream, line))
	{
		if(stringStartWith(line, "ambiant"))
		{
			modelToAdd.setAmbiant(parseLine<float>(line));
		}
		else if(stringStartWith(line, "depth"))
		{
			modelToAdd.setDepth(parseLine<int>(line));
		}
		else if(stringStartWith(line, "threshold"))
		{
			modelToAdd.setThreshold(parseLine<float>(line));
		}
	}
	return modelToAdd;
}

Transform DescriptionFileParser::parseTransformBlock(std::string blockString)
{
	std::istringstream stringStream(blockString);
	std::string line;
	Transform transformToAdd;
	while(std::getline(stringStream, line))
	{
		if(stringStartWith(line, "translate"))
		{
			transformToAdd.setPosition(parseLine<Vec3d>(line));
		}
		else if(stringStartWith(line, "scale"))
		{
			transformToAdd.setScale(parseLine<Vec3d>(line));
		}
		else if(stringStartWith(line, "rotation"))
		{
			transformToAdd.setRotation(parseLine<Vec3d>(line));
		}
	}

	return transformToAdd;
}

Camera DescriptionFileParser::parseCameraBlock(std::string blockString)
{
	std::istringstream stringStream(blockString);
	std::string line;
	Camera cameraToAdd;
	//Transform trans = parseTransformBlock(blockString);
	//cameraToAdd.setTransformValue(parseTransformBlock(blockString));
	while(std::getline(stringStream, line))
	{
		if(stringStartWith(line, "width"))
		{
			cameraToAdd.setWidth(parseLine<int>(line));
		}
		else if(stringStartWith(line, "height"))
		{
			cameraToAdd.setHeight(parseLine<int>(line));
		}
		else if(stringStartWith(line, "camera"))
		{
			if("perspective" == parseLine<std::string>(line))
			{
				cameraToAdd.setProjectionType(CamProjectionType::PERSPECTIVE);
				cameraToAdd.setFov(parseLine<float>(line));
			}
			else
			{
				cameraToAdd.setProjectionType(CamProjectionType::ISOMETRIC);
			}
		}
	}

	return cameraToAdd;
}

Sphere* DescriptionFileParser::parseSphereBlock(std::string blockString)
{
	std::istringstream stringStream(blockString);
	std::string line;
	Sphere *sphereToAdd = new Sphere();

	Transform trans = parseTransformBlock(blockString);
	sphereToAdd->setTransform(trans.getPosition(), trans.getRotation(), trans.getScale());

	while(std::getline(stringStream, line))
	{
		if(stringStartWith(line, "ambiant_coeff"))
		{
			sphereToAdd->setAmbiantCoeff(parseLine<Vec3d>(line));
		}
		else if(stringStartWith(line, "difuse_coeff"))
		{
			sphereToAdd->setDifuseCoeff(parseLine<Vec3d>(line));
		}
		else if(stringStartWith(line, "spec_coeff"))
		{
			sphereToAdd->setSpecularCoeff(parseLine<Vec3d>(line));
		}
		else if(stringStartWith(line, "alpha"))
		{
			sphereToAdd->setAlpha(parseLine<float>(line));
		}
	}

	return sphereToAdd;
}


void DescriptionFileParser::parseLightBlock(std::string blockString)
{

}

void DescriptionFileParser::parseObjectBlock(std::string blockString)
{
	
}

bool stringStartWith(std::string stringToTest, std::string stringToFind)
{
	std::size_t found = stringToTest.find(stringToFind);
	if(found != std::string::npos && found == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int stringSplit(std::vector<std::string>& tokens, std::string stringToSplit, std::string delimiter)
{
	tokens.clear();

	std::string::size_type strTemp = stringToSplit.find(delimiter);

	while(strTemp != std::string::npos)
	{
		tokens.push_back(stringToSplit.substr(0, strTemp));
		stringToSplit = stringToSplit.substr(strTemp + 1);
		strTemp = stringToSplit.find(delimiter);
	}

	tokens.push_back(stringToSplit);

	return tokens.size();
}

template <>
int parseLine<int>(std::string line)
{
	std::vector<std::string> values;
	stringSplit(values, line, " ");

	return std::stoi(values[values.size()-1]);
}

template <>
float parseLine<float>(std::string line)
{
	std::vector<std::string> values;
	stringSplit(values, line, " ");

	return std::stof(values[values.size()-1]);
}

template <>
Vec3d parseLine<Vec3d>(std::string line)
{
	std::vector<std::string> values;
	stringSplit(values, line, " ");

	Vec3d vecToReturn(std::stod(values[1]), std::stod(values[2]), std::stod(values[3]));
	return vecToReturn;
}

template <>
std::string parseLine<std::string>(std::string line)
{
	std::vector<std::string> values;
	stringSplit(values, line, " ");

	return values[1];
}