#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T, unsigned int Rows, unsigned int Cols>
class Matrix
{
protected:
	T* _values;

public:

	// Constructeurs & Destructeurs
	Matrix();
	Matrix(const T* vals, int arraySize);
	Matrix(const std::vector<T> vals);
	Matrix(const Matrix<T, Rows, Cols>& m);
	template <typename T2>
	Matrix(Matrix<T2, Rows, Cols> matrix);
	~Matrix(void);

	// Accessors
	T* getValues(void) const;

	// Methods
	void construct();
	void setGlobalValue(T val);
	template <typename T2>
	void setValues(const T2 values[], int valNum);

	// Operators
	Matrix<T, Rows, Cols>& operator+=(const Matrix<T, Rows, Cols> &m);
	const Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& m) const;
	Matrix<T, Rows, Cols>& operator*=(T factor);	
	template<unsigned int Cols2>
	const Matrix<T, Rows, Cols2> operator*(const Matrix<T, Cols, Cols2>& m) const;

	T& operator()(int row, int col) const;

	friend std::ostream& operator<<(std::ostream& os, const Matrix & m)
	{
		os << "Matrix :" << endl;
		for (int row = 0; row < Rows; row++)
		{
			for (int col = 0; col < Cols; col++)
				os << m(row, col) << " ";
			os << endl;
		}
		return os;
	}

};

/*
 * ---------- Constructors & Destructors ----------
 */

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>::Matrix(void)
{
	construct();
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>::Matrix(const T* vals, int arraySize)
{
	construct();
	for(int pos = 0; pos < Rows * Cols && pos < arraySize; pos++)
		_values[pos] = vals[pos];
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>::Matrix(const std::vector<T> vals)
{
	construct();
	for(int pos = 0; pos < Rows * Cols && pos < vals.size(); pos++)
		_values[pos] = vals[pos];
	
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>::Matrix(const Matrix<T, Rows, Cols>& m)
{
	construct();
	for(int pos = 0; pos < Rows * Cols; pos++)
		_values[pos] = m.getValues()[pos];
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>::~Matrix(void)
{
	delete[] this->_values;
}

template<typename T, unsigned int Rows, unsigned int Cols>
template <typename T2>
Matrix<T, Rows, Cols>::Matrix(const Matrix<T2, Rows, Cols> matrix)
{
	construct();
	this->setValues(matrix.getValues(), Rows * Cols);
}

/*
 * ---------- Accessors ----------
 */
template<typename T, unsigned int Rows, unsigned int Cols>
T* Matrix<T, Rows, Cols>::getValues(void) const
{
	return _values;
}

template<typename T, unsigned int Rows, unsigned int Cols>
template<typename T2>
void Matrix<T, Rows, Cols>::setValues(const T2 values[], int valNum)
{
	for (int i = 0; i < valNum; i++)
		this->_values[i] = values[i];
}

/*
 * ---------- Methods ----------
 */

template<typename T, unsigned int Rows, unsigned int Cols>
void Matrix<T, Rows, Cols>::construct()
{
	_values = new T[Rows * Cols];
	setGlobalValue(0);
}

template<typename T, unsigned int Rows, unsigned int Cols>
void Matrix<T, Rows, Cols>::setGlobalValue(T val)
{
	for(int pos = 0; pos < Rows * Cols; pos++)
		_values[pos] = val;
}

/*
 * ---------- Operators ----------
 */
template<typename T, unsigned int Rows, unsigned int Cols>
const Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator+(const Matrix<T, Rows, Cols>& m) const
{
	Matrix<T, Rows, Cols> tmp(*this);

	tmp += m;
	return tmp;
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator+=(const Matrix<T, Rows, Cols> &m)
{
	for(int pos = 0; pos < Rows * Cols; pos++)
		_values[pos] += m.getValues()[pos];
	return *this;
}

template<typename T, unsigned int Rows, unsigned int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator*=(T factor)
{
	for (int pos = 0; pos < Rows * Cols; pos++)
		_values[pos] *= factor;
	return tmp;
}

template<typename T, unsigned int Rows, unsigned int Cols>
template<unsigned int Cols2>
const Matrix<T, Rows, Cols2> Matrix<T, Rows, Cols>::operator*(const Matrix<T, Cols, Cols2>& m) const
{
	Matrix<T, Rows, Cols2> tmp;

	for (int row = 0; row < Rows; row++)
		for (int col2 = 0; col2 < Cols2; col2++)
			for (int col = 0; col < Cols; col++)
				tmp(row, col2) += (*this)(row, col) * m(col, col2);	
	return tmp;
}

template<typename T, unsigned int Rows, unsigned int Cols>
T& Matrix<T, Rows, Cols>::operator()(int row, int col) const
{
	return getValues()[row * Cols + col];
}

/*
 * ---------- Functions ----------
 */

template <typename T>
Matrix<T, 4, 4> createXRotateMatrix(int angle)
{
	T matrixTab[] = {1, 0, 0, 0,
					0, cos(angle), -sin(angle), 0,
					0, sin(angle), cos(angle), 0,
					0, 0, 0, 1 };
	Matrix<T, 4, 4> returnMatrix(matrixTab, 16);
	return returnMatrix;
}

template <typename T>
Matrix<T, 4, 4> createYRotateMatrix(int angle)
{
	T matrixTab[] = {cos(angle), 0, sin(angle), 0,
					0, 1, 0, 0,
					-sin(angle), 0, cos(angle), 0,
					0, 0, 0, 1 };
	Matrix<T, 4, 4> returnMatrix(matrixTab, 16);
	return returnMatrix;
}

template <typename T>
Matrix<T, 4, 4> createZRotateMatrix(int angle)
{
	T matrixTab[] = {cos(angle), -sin(angle),0, 0,
					sin(angle), cos(angle), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1 };
	Matrix<T, 4, 4> returnMatrix(matrixTab, 16);
	return returnMatrix;
}

template <typename T>
Matrix<T, 4, 4> createScaleMatrix(T sx, T sy, T sz)
{
	T tab[] = {sx, 0, 0, 0,
				0, sy, 0, 0,
				0, 0, sz, 0,
				0, 0, 0, 1 };
	Matrix<T, 4, 4> returnMatrix(tab, 16);
	return returnMatrix;
}

template <typename T>
Matrix<T, 4, 4> createTranslateMatrix(T tx, T ty, T tz)
{
	T tab[] = {1, 0, 0, tx,
				0, 1, 0, ty,
				0, 0, 1, tz,
				0, 0, 0, 1 };
	Matrix<T, 4, 4> returnMatrix(tab, 16);
	return returnMatrix;
}

template<typename T>
Matrix<T, 4, 1> toHomogenous(const Matrix<T, 3, 1> &vect)
{
	Matrix<T, 4, 1> m(vect.getValues(), 3);
	
	m(3, 0) = 1;
	return  m;
}

template<typename T, unsigned int Rows>
Matrix<T, Rows - 1, 1> fromHomogenous(const Matrix<T, Rows, 1> &m)
{
	T* tempValue = new T[Rows - 1];
	T last = m.getValues()[Rows - 1];

	for (int i = 0; i < Rows - 1; i++)
	{
		if (last != 0)
			tempValue[i] = m.getValues()[i] / last;
	}
	return Matrix<T, Rows - 1, 1>(tempValue, Rows - 1);
}

//typedef Matrix<double, 1, 3> Vec3d;
typedef Matrix<double, 1, 2> Vec2d;

#endif