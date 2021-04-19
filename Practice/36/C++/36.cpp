#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fmt/format.h>
#include <algorithm>
#include <cmath>
const auto PI = 3.141592653589793;
using namespace fmt;
enum coord_system
{
 Cartesian,
 Polar
};
class Point
{
private:
 double x, y;

public:
 constexpr static const double percision = 1e-10;
 constexpr static const double maxCharAllowedToSkip = 20;

 Point(double a1, double a2, coord_system coord)
 {
		if (coord == Cartesian)
		{
			x = a1;
			y = a2;
		}
		else
		{
			x = cos(a2) * a1;
			y = sin(a2) * a1;
		}
 }
 Point() : x(0), y(0) {}

 bool operator==(const Point &other) const
 {
		return abs(x - other.x) < percision && abs(y - other.y) < percision;
 }
 bool operator!=(const Point &other) const
 {
		return !(*this == other);
 }
 double get_x() const { return x; }
 double get_y() const { return y; }
 double get_r() const { return sqrt(x * x + y * y); }
 double get_phi() const
 {
		return atan(y / x) + (x < 0 ? PI : 0);
 }
 void set_x(double x) { this->x = x; }
 void set_y(double y) { this->y = y; }
 void set_r(double r)
 {
		double phi = get_phi();
		y = sin(phi) * r;
		x = cos(phi) * r;
 }
 void set_phi(double phi)
 {
		double r = get_r();
		y = sin(phi) * r;
		x = cos(phi) * r;
 }
};

std::ostream &operator<<(std::ostream &out, const Point &p)
{
 out << "(" << p.get_x() << "," << p.get_y() << ")";
 return out;
}
std::istream &operator>>(std::istream &in, Point &p)
{
 double a;
 in.ignore(p.maxCharAllowedToSkip, '(');
 in >> a;
 p.set_x(a);
 in.ignore(p.maxCharAllowedToSkip, ',');
 in >> a;
 p.set_y(a);
 in.ignore(p.maxCharAllowedToSkip, ')');
 return in;
}
int main()
{

 std::vector<Point> original;

 std::ifstream fin("data.txt");

 if (!fin.is_open())
 {

		std::cout << "Can't open file" << std::endl;

		return 1;
 }
 else
 {

		while (!fin.eof())
		{

			Point p;

			fin >> p;

			fin.ignore(2); // Точки разделены двумя символами ", "

			original.push_back(p);
		}

		fin.close();
 }

 std::vector<Point> simulacrum(original);

 for (auto &p : simulacrum)
 {

		std::cout << p;

		p.set_x(p.get_x() + 10);

		p.set_phi(p.get_phi() + 180 * PI / 180);

		p.set_y(-p.get_y());

		p.set_x(-p.get_x() - 10);

		std::cout << p << std::endl;
 }

 if (std::equal(original.begin(), original.end(), simulacrum.begin()))

		std::cout << "\nIt works!\n";

 else

		std::cout << "\nIt not works!\n";
}