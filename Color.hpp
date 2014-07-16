#pragma once
class Color
{
private:
	double red;
	double green;
	double blue;

public:
	Color();
	Color(double red, double green, double blue);
	~Color();

	void setRed(double red) { this->red = red; }
	double getRed() const { return this->red; }
	void setGreen(double green) { this->green = green; }
	double getGreen() const { return this->green; }
	void setBlue(double blue) { this->blue = blue; }
	double getBlue() const { return this->blue; }

	inline unsigned char getRedUC() const { return (unsigned char)(this->red * 255); }
	inline unsigned char getGreenUC() const { return (unsigned char)(this->green * 255); }
	inline unsigned char getBlueUC() const { return (unsigned char)(this->blue * 255); }

	Color operator*(const Color c) const;
};

