#pragma once
#include "Pch.h"

struct Num
{
	double value = 0.;
	bool isValid = false; // if false, use last value;

	bool IsWhole()
	{
		return (value == static_cast<int>(value));
	}
private:
	static void RemoveZeros(std::string& val)
	{
		char c = val[val.length() - 1];
		while (c == '0' && val.length() > 1)
		{
			val.pop_back();
			c = val[val.length() - 1];
		}
	}

public:
	Num() = default;
	Num(double val) { value = val; isValid = true; }
	Num(float val) { value = val; isValid = true; }
	Num(int val) { value = val; isValid = true; }
	Num(unsigned val) { value = val; isValid = true; }

	std::string FormatInt()
	{
		if (!IsWhole())
			std::cout << "WARNING: Num " << value << "rounded to int";
		return std::to_string(static_cast<int>(round(value)));
	}
	std::string FormatDec2()
	{
		std::string str = std::to_string(round(value * 100) / 100.);
		RemoveZeros(str);
		return str;
	}

	std::string FormatDec()
	{
		std::string str;
		if (static_cast<int>(value * 10000) != value * 10000)
			str = std::to_string(round(value * 10000) / 10000.);
		else
			str = std::to_string(value);
		RemoveZeros(str);
		return str;
	}

	// =
	void operator=(const double& val)
	{
		value = val;
		isValid = true;
	}
	void operator=(const float& val)
	{
		value = val;
		isValid = true;
	}
	void operator=(const int& val)
	{
		value = val;
		isValid = true;
	}
	void operator=(const unsigned& val)
	{
		value = val;
		isValid = true;
	}

	// +
	friend Num operator+( const Num& left, const double& right)
	{
		return Num(left.value + right);
	}

	friend Num operator+(const double& left, const Num& right)
	{
		return Num(left + right.value);
	}

	friend Num operator+(const Num& left, const float& right)
	{
		return Num(left.value + right);
	}

	friend Num operator+(const float& left, const Num& right)
	{
		return Num(left + right.value);
	}

	friend Num operator+(const Num& left, const int& right)
	{
		return Num(left.value + right);
	}

	friend Num operator+(const int& left, const Num& right)
	{
		return Num(left + right.value);
	}

	friend Num operator+(const Num& left, const unsigned& right)
	{
		return Num(left.value + right);
	}

	friend Num operator+(const unsigned& left, const Num& right)
	{
		return Num(left + right.value);
	}

	// -
	friend Num operator-(const Num& left, const double& right)
	{
		return Num(left.value - right);
	}

	friend Num operator-(const double& left, const Num& right)
	{
		return Num(left - right.value);
	}

	friend Num operator-(const Num& left, const float& right)
	{
		return Num(left.value - right);
	}

	friend Num operator-(const float& left, const Num& right)
	{
		return Num(left - right.value);
	}

	friend Num operator-(const Num& left, const int& right)
	{
		return Num(left.value - right);
	}

	friend Num operator-(const int& left, const Num& right)
	{
		return Num(left - right.value);
	}

	friend Num operator-(const Num& left, const unsigned& right)
	{
		return Num(left.value - right);
	}

	friend Num operator-(const unsigned& left, const Num& right)
	{
		return Num(left - right.value);
	}

	// *
	friend Num operator*(const Num& left, const double& right)
	{
		return Num(left.value * right);
	}

	friend Num operator*(const double& left, const Num& right)
	{
		return Num(left * right.value);
	}

	friend Num operator*(const Num& left, const float& right)
	{
		return Num(left.value * right);
	}

	friend Num operator*(const float& left, const Num& right)
	{
		return Num(left * right.value);
	}

	friend Num operator*(const Num& left, const int& right)
	{
		return Num(left.value * right);
	}

	friend Num operator*(const int& left, const Num& right)
	{
		return Num(left * right.value);
	}
	friend Num operator*(const Num& left, const unsigned& right)
	{
		return Num(left.value * right);
	}

	friend Num operator*(const unsigned& left, const Num& right)
	{
		return Num(left * right.value);
	}

	// /
	friend Num operator/(const Num& left, const double& right)
	{
		return Num(left.value / right);
	}

	friend Num operator/(const double& left, const Num& right)
	{
		return Num(left / right.value);
	}

	friend Num operator/(const Num& left, const float& right)
	{
		return Num(left.value / right);
	}

	friend Num operator/(const float& left, const Num& right)
	{
		return Num(left / right.value);
	}

	friend Num operator/(const Num& left, const int& right)
	{
		return Num(left.value / right);
	}

	friend Num operator/(const int& left, const Num& right)
	{
		return Num(left / right.value);
	}

	friend Num operator/(const Num& left, const unsigned& right)
	{
		return Num(left.value / right);
	}

	friend Num operator/(const unsigned& left, const Num& right)
	{
		return Num(left / right.value);
	}

	// %

	friend Num operator%(const Num& left, const int& right)
	{
		if (left.value != static_cast<int>(left.value))
			std::cout << "WARNING: Num value " << left.value << " truncated for % operation\n";
		return Num(static_cast<int>(left.value) % right);
	}

	friend Num operator%(const int& left, const Num& right)
	{
		if (right.value != static_cast<int>(right.value))
			std::cout << "WARNING: Num value " << right.value << " truncated for % operation\n";
		return Num(left % static_cast<int>(right.value));
	}

	friend Num operator%(const Num& left, const unsigned& right)
	{
		if (left.value != static_cast<unsigned>(left.value))
			std::cout << "WARNING: Num value " << left.value << " truncated for % operation\n";
		return Num(static_cast<unsigned>(left.value) % right);
	}

	friend Num operator%(const unsigned& left, const Num& right)
	{
		if (right.value != static_cast<unsigned>(right.value))
			std::cout << "WARNING: Num value " << right.value << " truncated for % operation\n";
		return Num(left % static_cast<unsigned>(right.value));
	}

	// <
	friend bool operator<( const Num& left, const double& right)
	{
		return left.value < right;
	}

	friend bool operator<(const double& left, const Num& right)
	{
		return (left < right.value);
	}

	friend bool operator<(const Num& left, const float& right)
	{
		return (left.value < right);
	}

	friend bool operator<(const float& left, const Num& right)
	{
		return (left < right.value);
	}

	friend bool operator<(const Num& left, const int& right)
	{
		return (left.value < right);
	}

	friend bool operator<(const int& left, const Num& right)
	{
		return (left < right.value);
	}

	friend bool operator<(const unsigned& left, const Num& right)
	{
		return (left < right.value);
	}

	friend bool operator<(const Num& left, const unsigned& right)
	{
		return (left.value < right);
	}

	friend bool operator<(const Num& left, const Num& right)
	{
		return (left.value < right.value);
	}

	// <=
	friend bool operator<=(const Num& left, const double& right)
	{
		return left.value <= right;
	}

	friend bool operator<=(const double& left, const Num& right)
	{
		return (left <= right.value);
	}

	friend bool operator<=(const Num& left, const float& right)
	{
		return (left.value <= right);
	}

	friend bool operator<=(const float& left, const Num& right)
	{
		return (left <= right.value);
	}

	friend bool operator<=(const Num& left, const int& right)
	{
		return (left.value <= right);
	}

	friend bool operator<=(const int& left, const Num& right)
	{
		return (left <= right.value);
	}

	friend bool operator<=(const Num& left, const unsigned& right)
	{
		return (left.value <= right);
	}

	friend bool operator<=(const unsigned& left, const Num& right)
	{
		return (left <= right.value);
	}

	friend bool operator<=(const Num& left, const Num& right)
	{
		return (left.value <= right.value);
	}

	// >
	friend bool operator>(const Num& left, const double& right)
	{
		return left.value > right;
	}

	friend bool operator>(const double& left, const Num& right)
	{
		return (left > right.value);
	}

	friend bool operator>(const Num& left, const float& right)
	{
		return (left.value > right);
	}

	friend bool operator>(const float& left, const Num& right)
	{
		return (left > right.value);
	}

	friend bool operator>(const Num& left, const int& right)
	{
		return (left.value > right);
	}

	friend bool operator>(const int& left, const Num& right)
	{
		return (left > right.value);
	}

	friend bool operator>(const Num& left, const unsigned& right)
	{
		return (left.value > right);
	}

	friend bool operator>(const unsigned& left, const Num& right)
	{
		return (left > right.value);
	}

	friend bool operator>(const Num& left, const Num& right)
	{
		return (left.value > right.value);
	}

	// >=
	friend bool operator>=(const Num& left, const double& right)
	{
		return left.value >= right;
	}

	friend bool operator>=(const double& left, const Num& right)
	{
		return (left >= right.value);
	}

	friend bool operator>=(const Num& left, const float& right)
	{
		return (left.value >= right);
	}

	friend bool operator>=(const float& left, const Num& right)
	{
		return (left >= right.value);
	}

	friend bool operator>=(const Num& left, const int& right)
	{
		return (left.value > right);
	}

	friend bool operator>=(const int& left, const Num& right)
	{
		return (left >= right.value);
	}

	friend bool operator>=(const Num& left, const unsigned& right)
	{
		return (left.value > right);
	}

	friend bool operator>=(const unsigned& left, const Num& right)
	{
		return (left >= right.value);
	}

	friend bool operator>=(const Num& left, const Num& right)
	{
		return (left.value >= right.value);
	}

	// ==
	friend bool operator==(const Num& left, const double& right)
	{
		return left.value == right;
	}

	friend bool operator==(const double& left, const Num& right)
	{
		return (left == right.value);
	}

	friend bool operator==(const Num& left, const float& right)
	{
		return (left.value == right);
	}

	friend bool operator==(const float& left, const Num& right)
	{
		return (left == right.value);
	}

	friend bool operator==(const Num& left, const int& right)
	{
		return (left.value == right);
	}

	friend bool operator==(const int& left, const Num& right)
	{
		return (left == right.value);
	}

	friend bool operator==(const Num& left, const unsigned& right)
	{
		return (left.value == right);
	}

	friend bool operator==(const unsigned& left, const Num& right)
	{
		return (left == right.value);
	}

	friend bool operator==(const Num& left, const Num& right)
	{
		return (left.value == right.value);
	}

	operator double() const
	{
		return value;
	}

	operator float() const
	{
		std::cout << "WARNING: Conversion from Num to float. Possible loss of precision\n";
		return static_cast<float>(value);
	}

	operator int() const
	{
		if (value != static_cast<int>(value))
			std::cout << "WARNING: Loss of data wheen converting Num to int\n";
		return static_cast<int>(value);
	}

	operator unsigned() const
	{
		if (value != static_cast<unsigned>(value))
			std::cout << "WARNING: Loss of data wheen converting Num to unsigned int\n";
		return static_cast<unsigned>(value);
	}
};