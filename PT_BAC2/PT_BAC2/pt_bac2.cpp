#include<stdio.h>
#include<math.h>
//PT bac 2 co dang a.x^2 + b.x + c =0 (a!=0)
class PT_BAC2
{
private:
	float a;
	float b;
	float c;
	float X1;
	float X2;
	float delta;
public:
	void GiaiPT(float a, float b, float c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		delta = b*b - 4 * a * c;
		if (delta < 0) printf("\r\nPT vo nghiem");
		if (delta == 0)
		{
			X1 = -b/(2*a);
			X2 = X1;
			printf("\r\nPhuong trinh co nghiem kep: X1 = X2 = %.1f", X1);
		}
		if (delta > 0)
		{
			X1 = (-b + (float)sqrt(delta)) / (2*a);
			X2 = (-b - (float)sqrt(delta)) / (2 * a);
			printf("\r\nPhuong trinh co 2 nghiem phan biet la: X1 = %.1f, X2 = %.1f", X1, X2);
		}
	}
};
int main()
{
	float a = 0, b = 0, c = 0;
	PT_BAC2 A;
	do
	{
		printf("\r\nNhap vao cac he so a, b, c cua phuong trinh bac 2:");
		scanf_s("%f%f%f", &a, &b, &c);
	} while (a == 0);
	printf("Phuong trinh da nhap la: %.1f.x^2 + %.1f.x + %.1f", a, b, c);
	A.GiaiPT(a,b,c);
	return 0;
}