#define _CRT_SECURE_NO_WARNINGS
#include "TMatrix.h"
#include <iostream>
#include <string>


using namespace std;

void Start()
{
	int type, n, m;
	cout << "Выберите тип матрицы: 1.(int)\n2.(float)\n3.(double)\n4.(DT)\n\n\n>>> ";
	cin >> type;
	cout << "Введите количество строк и столбцов\n\n\n>>>";
	cin >> m >> n;
	switch (type)
	{
	case 1:
	{
		TMatrix<int> obj(m, n);
		obj.Set();
		obj.ShowData();
		obj.qUnderMid(obj.mid());
		break;
	}
	case 2:
	{
		TMatrix<float> obj(m, n);
		obj.Set();
		obj.ShowData();
		obj.qUnderMid(obj.mid());
		break;
	}
	case 3:
	{
		TMatrix<double> obj(m, n);
		obj.Set();
		obj.ShowData();
		obj.qUnderMid(obj.mid());
		break;
	}
	case 4:
	{
		TMatrix<DT> obj(m, n);
		obj.Set();
		obj.ShowData();
		obj.qUnderMid(obj.mid());
		break;
	}
	}
	system("pause");
}

template<class T>
void TMatrix<T>::Set()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
}

template<class T>
T TMatrix<T>::mid()
{
	T S(0.0);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			S = S + matrix[i][j];
	//returns absolute value of mid
	return (S / (M*N));
}

template<class T>
int TMatrix<T>::qUnderMid(T mid)
{
	int q = 0;
	for(int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (matrix[i][j] > 0 && mid > matrix[i][j])
			{
				q++;
				cout << matrix[i][j] << "\t";
			}
	cout << endl;
	return q;
}

template<class T>
T TMatrix<T>::negativeSum(bool parity)
{
	T sum(0);
		for (int i = 0; i < N; i++)
		{
			if (parity && i % 2 == 0)
			{
				for (int j = 0; j < M; j++)
					if (matrix[j][i] > 0)
						sum += matrix[j][i];
			}
			else if(!parity && i%2!=0)
			{
				for (int j = 0; j < M; j++)
					if (matrix[j][i] > 0)
						sum += matrix[j][i];
			}
		}
	return sum;
}

template<class T>
void TMatrix<T>::ShowData()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

template<class T>
TMatrix<T>::TMatrix(int M, int N):M(M), N(N)
{
	matrix = new T*[M];
	for (int i = 0; i < M; i++)
		matrix[i] = new T[N];
}

template<class T>
TMatrix<T>::~TMatrix()
{
	if (matrix)
	{
		for (int i = 0; i < M; i++)
			delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
	}
}


DT::DT()
{
	a = 0;
	b=0;
}
DT::DT(double _a)
{
	a = _a;
	b = 1;
}
DT::DT(int _a, int _b) : a(_a), b(_b)
{}

std::istream & operator>>(std::istream & _in, DT & _p)
{
	_in >> _p.a >> _p.b;
	return _in;
}

std::ostream & operator<<(std::ostream & _out, const DT & _p)
{
	_out << " (" << _p.a << ", " << _p.b << ") ";
	return _out;
}



DT & DT::operator + (const DT & _p) const
{
	DT A((a * _p.b) + (_p.a * b), (b * _p.b));
	return A;
}

DT & DT::operator - (const DT & _p) const
{
	DT A(a - _p.a, b - _p.b);
	return A;
}

DT & DT::operator/(int p) const
{
	DT A(a, b*p);
	return A;
}

DT::~DT()
{
}
