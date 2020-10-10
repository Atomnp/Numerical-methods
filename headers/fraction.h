#pragma once

#include <iostream>
#include <ostream>
#include <string>

int hcf(int a, int b) {
	if (b == 0)
		return a;
	return hcf(b, a % b);
}
long long lcm(int a, int b)
{
	return (a / hcf(a, b)) * b;
}
class Fraction {


public:
	int numerator;
	int denominator;

	Fraction(int n, int d) {
		if (d == 0) {
			std::cout << "denominatro cant be zero" << std::endl;
			exit(0);
		}
		int h = hcf(n, d);
		numerator = n / h;
		denominator = d / h;
		if (denominator < 0) {
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
	}
	Fraction(int n) :numerator(n), denominator(1) {

	}
	Fraction operator+(const Fraction& other) {
		int l = lcm(denominator, other.denominator);
		return Fraction(l / denominator * numerator + l / other.denominator * other.numerator, l);
	}
	Fraction operator*(const Fraction& other)const  {
		return Fraction(numerator*other.numerator,denominator*other.denominator);
	}
	Fraction operator*(int val) {
		return Fraction(numerator *val, denominator);
	}
	Fraction operator/(const Fraction& other)const {
		return Fraction(numerator * other.denominator, denominator * other.numerator);
	}
	Fraction operator-(const Fraction& other) {
		int l = lcm(denominator, other.denominator);
		return Fraction(l / denominator * numerator - l / other.denominator * other.numerator, l);
	}
	bool operator ==(const Fraction& other) {
		return (numerator == other.numerator and denominator == other.denominator);
	}
	bool operator !=(const Fraction& other) {
		return !(numerator == other.numerator and denominator == other.denominator);
	}
	friend std::ostream& operator<<(std::ostream& os, Fraction f);
	friend Fraction operator*(int val, Fraction f);
	double toDecimal() {
		return (numerator * 1.0) / denominator;
	}
};

Fraction operator*(int val, Fraction f) {
	return f * val;
}
std::ostream& operator<<(std::ostream& os, Fraction f) {
	std::string msg="";
	if (f.denominator == 1) {
		msg = std::to_string(f.numerator);
	}
	else {
		msg += std::to_string(f.numerator) + "/" + std::to_string(f.denominator);
	}
	
	os << msg ;
	return os;
};