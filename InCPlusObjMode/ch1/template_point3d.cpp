#include <iostream>
#include <cassert>
using namespace std;

template<class type>
class Point3d {
	public:
		Point3d(type x = 0.0, type y = 0.0, type z = 0.0) 	
			: _x(x), _y(y), _z(z) { }

		type x() const { return _x; }
		void x(type xval) { _x = xval; }

		type y() const { return _y; }
		void y(type yval) { _y = yval; }

		type z() const { return _z; }
		void z(type zval) { _z = zval; }

	private:
		type _x;
		type _y;
		type _z;
};

template <class type, int dim>
class Point {
	public:
		Point(); 
		Point(type coords[dim]) {
			for (int index = 0; index < dim; index++) {
				_coords[index] = coords[index];
			}
		}

		type& operator[](int index) {
			assert(index < dim && index >= 0);
			return _coords[index];
		}

		type operator[](int index) const {
			assert(index < dim && index >= 0);
			return _coords[index];
		}

	private:
		type _coords[dim];
};

template<class type, int dim>
Point<type, dim>::Point() {

}

inline template<class type, int dim>
ostream& operator<<(ostream &os, const Point<type, dim> &pt) {
	os << "(";
	for (int ix = 0; ix < dim - 1; ix++)
		os << pt[ix] << ", ";

	os << pt[dim-1];
	os << ")";
};

int main(int argc, char *argv[]) {
	float point[3] = { 0.1, 0.2, 0.6 };
	Point<float, int> pt;

	return 0;
}
