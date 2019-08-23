#include<iostream>
#include<math.h>
using namespace std;

/*点*/
class point_float
{
public:
	point_float(float _x,float _y):x(_x),y(_y){}
	float x;
	float y;
};
/*算法*/
/*思路：面积法*/
#define ABS_FLOAT_0 0.0001//计算机思维：0.0001即当做0
/*由3点求三角形面积*/
float GetS(const point_float a, const point_float b, const point_float c)
{
	float AB_x,AB_y ,BC_x,BC_y,CA_x,CA_y;
	AB_x = fabs(b.x - a.x);
	AB_y = fabs(b.y - a.y);

	BC_x = fabs(c.x - b.x);
	BC_y = fabs(c.y -b.y);

	CA_x = fabs(c.x - a.x);
	CA_y = fabs(c.y - a.y);

	float S;
	S = ((BC_y + CA_y)*AB_x - CA_x*CA_y - BC_x*BC_y)/2.0f;
	return S;
}
int main()
{
	/*定义一个三角形*/
	point_float A(0, 0);
	point_float B(1, 0);
	point_float C(0, 1);

	/*定义一个点*/
	point_float P(0, 1.1);

	/*求三角形ABC面积*/
	float S_ABC = GetS(A, B, C);
	/*求三角形ABP、BCP、CAP面积*/
	float S_ABP = GetS(A, B, P);
	float S_BCP = GetS(B, C, P);
	float S_CAP = GetS(C, A, P);

	float SS = S_ABP + S_BCP + S_CAP;//以P点为支点的三个小三角形面积和
	cout << S_ABC <<" "<<SS<< endl; //
	if (fabs(SS - S_ABC) < ABS_FLOAT_0)//两个面积差<0.0001时认为P在三角形ABC里
	{
		cout << "true" << endl;
		//return true;
	}
		
	else
	{
		cout << "false" << endl;
		//return false;
	}
		
	system("pause");
	return 0;
}