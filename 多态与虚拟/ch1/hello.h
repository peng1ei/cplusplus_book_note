#ifndef _HELLO_H
#define _HELLO_H

class CPoint {
public:
	CPoint(float x = 0.0) : _x(x) {}

	float x();
	void x(float xval);

	// 重载 + 
	CPoint operator+(const CPoint &pt) const {
		return CPoint(_x + pt._x);
	}

protected:
	float _x;
};

#endif // _HELLO_H
