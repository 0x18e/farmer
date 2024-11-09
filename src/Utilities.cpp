#include "Utilities.h"

std::random_device rd;
std::mt19937 rng{ rd() };
float GetRandomNumber(float rangex, float rangey) {


	std::uniform_real_distribution<float> r(rangex, rangey);

	return r(rng);
}


// This constructor works
Point::Point(float x, float y) : x(0.0f), y(0.0f){
	this->x = x;
	this->y = y;
}
// This works
Point& Point::operator+=(const Point& p_point){
	this->x += p_point.x;
	this->y += p_point.y;
	return *this;
}
// This works
Point Point::operator+(const Point& p_point){
	return Point(this->x + p_point.x, this->y + p_point.y);
}
// This works
Point& Point::operator-=(const Point& p_point){
	this->x -= p_point.x;
	this->y -= p_point.y;
	return *this;
}
// This works
Point Point::operator-(const Point& p_point){
	return Point(this->x - p_point.x, this->y - p_point.y);
}
// This works
Point& Point::operator*=(const Point& p_point){
	this->x *= p_point.x;
	this->y *= p_point.y;
	return *this;
}
// This works
Point Point::operator*(const Point& p_point){
	return Point(this->x * p_point.x, this->y * p_point.y);
}
// This works
Point Point::operator*(const float n_scale){
	return Point(this->x * n_scale, this->y * n_scale);
}
// This works
Point& Point::operator*=(const float n_scale){
	this->x *= n_scale;
	this->y *= n_scale;
	return *this;
}

// This works
Point& Point::operator/=(const Point& p_point){
	this->x /= p_point.x;
	this->y /= p_point.y;

	return *this;
}
// This works
Point Point::operator/(const Point& p_point){
	return Point(this->x / p_point.x, this->y / p_point.y);
}
// This works
Point Point::operator/(const float f_divisor){
	return Point(this->x / f_divisor, this->y/f_divisor);
}
// This works
Point& Point::operator/=(const float f_divisor)
{
	this->x /= f_divisor;
	this->y /= f_divisor;

	return *this;
}



Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2& Vector2::operator+=(const Vector2& v){
	this->x += v.x;
	this->y += v.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& v){
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2& Vector2::operator-=(const Vector2& v_vec){
	this->x -= v_vec.x;
	this->y -= v_vec.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v_vec){
	return Vector2(this->x - v_vec.x, this->y-v_vec.y);
}

Vector2& Vector2::operator/=(const Vector2& v_vec){
	this->x /= v_vec.x;
	this->y /= v_vec.y;

	return *this;
}

Vector2 Vector2::operator/(const Vector2& v_vec){
	return Vector2(this->x / v_vec.x, this->y / v_vec.y);
}

Vector2 Vector2::operator/(const float f_divisor) {
	return Vector2(x/f_divisor, y/f_divisor);
}

Vector2& Vector2::operator/=(const float f_divisor) {
	
	this->x /= f_divisor;
	this->y /= f_divisor;
	return *this;
}

float Vector2::Dot(Vector2 other) {
	float vars = this->x* other.x + this->y * other.y;
	return vars / (Magnitude(other) * Magnitude(*this));
}

Vector2& Vector2::operator*=(const float& scale){
	this->x *= scale;
	this->y *= scale;

	return *this;
}

Vector2 Vector2::operator*(const float& scale){
	return Vector2(this->x * scale, this->y * scale);
}

Vector2 Vector2::operator*(const Vector2& v_vec){
	return Vector2(this->x * v_vec.x, this->y * v_vec.y);
}

Vector2& Vector2::operator*=(const Vector2& v_vec){
	this->x *= v_vec.x;
	this->y *= v_vec.y;
	return *this;
}
// Helper functions
float Magnitude(Vector2 vec) {
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

float Distance(Vector2 v1, Vector2 v2) {
	return std::sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
}

Vector2 UnitVector(Vector2 vector) {
	return Vector2(vector.x / Magnitude(vector), vector.y / Magnitude(vector));
}