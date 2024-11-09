#pragma once
#include<iostream>
#include<vector>
#include<random>

// Debug tools
// Logging
#define DEBUG 1
#if DEBUG

#define LOG(x) std::cout << x << "\n"
#else
#define LOG(x)
#endif 
float GetRandomNumber(float rangex, float rangey);

// Point Struct used to denote a 2-Dimensional point. This might be useless.
struct Point {
	float x, y;
	Point() : x(0.0f), y(0.0f) {};
	Point(float x, float y);

	// Point Arithmetic

	Point& operator+=(const Point& p_point);
	Point operator+(const Point& p_point);

	Point& operator-=(const Point& p_point);
	Point operator-(const Point& p_point);

	Point& operator*=(const Point& p_point);
	Point operator*(const Point& p_point);
	Point operator*(const float n_scale);
	Point& operator*=(const float n_scale);

	Point& operator/=(const Point& p_point); // Divide two points with each other and assign the end value
	Point operator/(const Point& p_point); // Divide two points and return a new value
	Point operator/(const float f_divisor); 
	Point& operator/=(const float f_divisor);
	



};

// Vector2 Struct used to denote a 2-Dimensional vector.
struct Vector2 {

	float x, y;

	Vector2() : x(0.0f), y(0.0f) {};

	Vector2(float x, float y);
	
	// Vector Arithmetic

	// Vector Addition
	Vector2& operator+=(const Vector2& v_vec);
	Vector2 operator+(const Vector2& v_vec);
	
	// Vector Subtraction
	Vector2& operator-=(const Vector2& v_vec);
	Vector2 operator-(const Vector2& v_vec);
	
	// Vector division
	Vector2& operator/=(const Vector2& v_vec);
	Vector2 operator/(const Vector2& v_vec);
	Vector2 operator/(const float f_divisor); 
	Vector2& operator/=(const float f_divisor);
	
	float Dot(Vector2 other);
	
	// Vector Multiplication with Scalar
	Vector2& operator*=(const float& scale);
	Vector2 operator*(const float& scale);
	// Vector Multiplication
	Vector2 operator*(const Vector2& v_vec);
	Vector2& operator*=(const Vector2& v_vec);
	
};


float Magnitude(Vector2 vec);
float Distance(Vector2 v1, Vector2 v2);
Vector2 UnitVector(Vector2 vector);