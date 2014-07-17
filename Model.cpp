#include "Model.hpp"


Model::Model()
{
	_ambiant = 0.0f;
	_depth = 0;
	_threshold = 0.0f;
}


Model::~Model()
{
}

float Model::getAmbiant()
{
	return _ambiant;
}

int Model::getDepth()
{
	return _depth;
}

float Model::getThreshold()
{
	return _threshold;
}

void Model::setAmbiant(float ambiant)
{
	_ambiant = ambiant;
}

void Model::setDepth(int depth)
{
	_depth = depth;
}

void Model::setThreshold(float threshold)
{
	_threshold = threshold;
}