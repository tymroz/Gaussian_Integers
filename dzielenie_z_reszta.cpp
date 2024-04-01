#include <iostream>
#include <cmath>

struct LiczbaGausa {
	int real;
	int imaginary;
};

int norma (LiczbaGausa& l){
	return (l.real * l.real) + (l.imaginary * l.imaginary);
}

//	x = q * y + r  => r = x - q * y

LiczbaGausa dzielnik(LiczbaGausa& x, LiczbaGausa& y){
	LiczbaGausa q;
	if(y.real == 0 && y.imaginary == 0){
		std::cout << "Nie można podzielić przez 0" << std::endl;
	} else{
		q.real = (x.real * y.real + x.imaginary * y.imaginary) / norma(y);
		q.imaginary = (x.imaginary * y.real - x.real * y.imaginary) / norma(y);
	}
	
	return q;
}

LiczbaGausa reszta(LiczbaGausa& x, LiczbaGausa& y){
	LiczbaGausa q = dzielnik(x, y);
	LiczbaGausa r;
	r.real = x.real - q.real * y.real + q.imaginary * y.imaginary;
	r.imaginary = x.imaginary - q.real * y.imaginary - q.imaginary * y.real;

	return r;
}

int main(){
	LiczbaGausa x = {3, 4};
	LiczbaGausa y = {1, 3};

	LiczbaGausa q, r;

	q = dzielnik(x, y);
	r = reszta(x, y);

	std::cout << "q: " << q.real << " + " << q.imaginary << "i" << std::endl;
	std::cout << "r: " << r.real << " + " << r.imaginary << "i" << std::endl;

	return 0;
}