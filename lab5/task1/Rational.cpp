﻿#include "stdafx.h"
#include "Rational.h"
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

unsigned LCM(unsigned x, unsigned y)
{
	return (x / GCD(x, y) * y);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
double  CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
CRational const CRational::operator +() const
{
	return *this;
}

CRational const CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
const CRational operator + (const CRational &num1, const CRational &num2)
{
	const unsigned lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
	return CRational(num1.GetNumerator() * (lcm / num1.GetDenominator()) + num2.GetNumerator() * (lcm / num2.GetDenominator()), lcm);
}
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
CRational& CRational::operator +=(CRational const& rational)
{
	m_numerator = m_numerator * rational.m_denominator + rational.m_numerator * m_denominator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
//const CRational operator == (const CRational &num1, const CRational &num2)
//{
//	return CRational(num1.GetNumerator() * (l / num1.GetDenominator()) + num2.GetNumerator() * (l / num2.GetDenominator()), l);
//}
//
//const CRational operator != (const CRational &num1, const CRational &num2)
//{
//	const unsigned l = LCM(num1.GetDenominator(), num2.GetDenominator());
//	return CRational(num1.GetNumerator() * (l / num1.GetDenominator()) + num2.GetNumerator() * (l / num2.GetDenominator()), l);
//}
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////


