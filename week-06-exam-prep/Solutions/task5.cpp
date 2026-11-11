#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_POINTS = 50000;

// global, because 2 * 50000 doubles (~800 KB) are close to the default 1 MB stack on Windows
double x[MAX_POINTS], y[MAX_POINTS];

bool is_in_circle(double px, double py, double xc, double yc, double r)
{
	double dx = px - xc;
	double dy = py - yc;
	return dx * dx + dy * dy <= r * r;
}

bool is_in_rectangle(double px, double py, double left, double right, double bottom, double top)
{
	return px >= left && px <= right && py >= bottom && py <= top;
}

int main() {
	int n;
	cin >> n;

	if (n < 0 || n >= MAX_POINTS)
	{
		cout << "Invalid number of points" << endl;
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	// the rectangle
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double left = min(x1, x2);
	double right = max(x1, x2);
	double bottom = min(y1, y2);
	double top = max(y1, y2);

	// the circle
	double xc, yc, r;
	cin >> xc >> yc >> r;

	int in_circle = 0;
	int in_rectangle = 0;
	int in_both = 0;

	for (int i = 0; i < n; i++)
	{
		bool circle = is_in_circle(x[i], y[i], xc, yc, r);
		bool rectangle = is_in_rectangle(x[i], y[i], left, right, bottom, top);

		if (circle) in_circle++;
		if (rectangle) in_rectangle++;
		if (circle && rectangle) in_both++;
	}

	cout << in_circle << endl;
	cout << in_rectangle << endl;
	cout << in_both << endl;

	return 0;
}
