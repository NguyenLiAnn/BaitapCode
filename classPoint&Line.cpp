#include <iostream>
using namespace std;

class Point{
	private:
		double x, y;
	public:
		void nhap(){
			cin >> x >> y;
		}
		void in(){
			cout << x << ' ' << y;
		}
		double getx(){
			return x;
		}
		double gety(){
			return y;
		}
		void setPoint(double x, double y){
			this->x = x;
			this->y = y;
		}
};

class Line{
	private:
	//dang ax + by = c
	//(a, b) phap tuyen
		double a, b, c;
		
	public:
		void set_HeSo(double a, double b, Point tmp);
		void in();
		double geta(){
			return a;
		}
		double getb(){
			return b;
		}
		double getc(){
			return c;
		}
};

void Line::set_HeSo(double a, double b, Point tmp){
	this->a = a;
	this->b = b;
	this->c = a * tmp.getx() + b * tmp.gety();
}

void Line::in(){
	cout << a << " " << b << " " << c;
}

void dinhthuc(Line ab, Line cd){
	double D, Dx, Dy;
	D = ab.geta() * cd.getb() - cd.geta() * ab.getb() ;
	Dx = ab.getc() * cd.getb() - cd.getc() * ab.getb() ;
	Dy = ab.geta() * cd.getc() - cd.geta() * ab.getc() ;
	if (D != 0){
		cout << Dx/D << " " << Dy/D;
	}
	else {
		if (Dx != 0 || Dy != 0){
			cout << "2 duong thang song song";
		}
		else cout << "2 duong thang trung nhau";
	}
}

int main(){
	Point A, B, C, D, AB, CD;
	A.nhap() ;
	B.nhap() ;
	C.nhap() ;
	D.nhap() ;
	
	//chi phuong
	AB.setPoint(A.getx() - B.getx(), A.gety() - B.gety()); 
	CD.setPoint(C.getx() - D.getx(), C.gety() - D.gety());
	
	Line ab, cd;
	ab.set_HeSo(AB.gety(), -AB.getx(), A);
	cd.set_HeSo(CD.gety(), -CD.getx(), C); 

	dinhthuc(ab, cd);
	
	return 0;
}
