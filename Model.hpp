#ifndef MODEL_PARSER_H
#define MODEL_PARSER_H

class Model
{
private:
	float _ambiant;
	int _depth;
	float _threshold;

public:
	Model();
	~Model();

	float getAmbiant();
	int getDepth();
	float getThreshold();

	void setAmbiant(float ambiant);
	void setDepth(int depth);
	void setThreshold(float threshold);
};

#endif