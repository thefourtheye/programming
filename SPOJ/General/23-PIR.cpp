# include <iostream>
# include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	double W, V, U, u, v, w, X, Y, Z, x, y, z, a, b, c, d;
	int total;
	cin >> total;
	while (total--)
	{
		cin >> u >> v >> w >> W >> V >> U;
		X = (w - U + v)*(U + v + w);
		x = (U - v + w)*(v - w + U);
		Y = (u - V + w)*(V + w + u);
		y = (V - w + u)*(w - u + V);
		Z = (v - W + u)*(W + u + v);
		z = (W - u + v)*(u - v + W);
		a = sqrt (x * Y * Z);
		//cout << x * Y * Z << endl;
		b = sqrt (y * Z * X);
		//cout << y * Z * X << endl;
		c = sqrt (z * X * Y);
		//cout << z * X * Y << endl;
		d = sqrt (x * y * z);
		//cout << x * y * z << endl;
		//cout << X << " " << x << " " << Y << " " << y << " " << Z << " " << z << " " << a << " " << b << " " << c << " " << d << endl;
		double volume = sqrt ((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d)) / (192.0f * u * v * w);
		//cout << sqrt ((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d)) << endl;
		cout << fixed << setprecision (4) << volume << endl;
		//double area = sqrt((double)((bc + bd + cd) * (bc + bd - cd) * (bc - bd + cd) * (-bc + bd + cd)))/4.0;
	}
	return 0;
}