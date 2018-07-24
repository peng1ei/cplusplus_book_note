#include <iostream>
using namespace std;

class Point {
	public:
		Point(float xval);
		virtual ~Point();

		float x() const;
		static int pointCount();

	protected:
		virtual ostream& print(ostream &os) const;

		float _x;
		static int _point_count;
};

int main(int argc, char *argv[]) {


	return 0;
}
