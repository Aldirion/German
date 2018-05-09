#pragma once
#ifndef _TMATRIX_H_
#define _TMATRIX_H_
#include <iostream>

void Start();

class DT
{
private:
	int a, b;
public:
	DT(double);
	DT(int, int);
	DT();
	DT & operator +(const DT &_p) const;
	DT &operator -(const DT &_p) const;
	DT &operator /(int) const;
	friend std::istream &operator >>(std::istream &_in, DT &_p);
	friend std::ostream &operator <<(std::ostream &_out, const DT &_p);
	bool operator >(int p) const
	{
		return a > p;
	}
	bool operator >(const DT &p)const
	{
		DT S = *this - p;
		return S > 0;
	}
	~DT();
};

template<class T>
class TMatrix
{
private:
	int M, N;
	T * * matrix;
public:
	TMatrix(int = 3, int = 3);
	~TMatrix();
	void Set();
	//returns absolute value of mid
	T mid();
	//returns
	int qUnderMid(T mid);
	T negativeSum(bool parity);
	void ShowData();
};
#endif

