#include <iostream>
#include <cmath>

struct LiczbaGausa {
	int real;
	int imaginary;
};

int norma (LiczbaGausa& l){
	return (l.real * l.real) + (l.imaginary * l.imaginary);
}

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

LiczbaGausa nwd(LiczbaGausa& x, LiczbaGausa& y){
	LiczbaGausa u = x;
	LiczbaGausa v = y;
	LiczbaGausa r = reszta(u, v);

	while(r.real != 0 && r.imaginary != 0){
		u = v;
		v = r;
		r = reszta(u, v);
	}

	return v;
}

LiczbaGausa mnozenie(LiczbaGausa& x, LiczbaGausa& y){
	LiczbaGausa wynik;
	wynik.real = x.real * y.real - x.imaginary * y.imaginary;
	wynik.imaginary = x.real * y.imaginary + x.imaginary * y.real;

	return wynik;
}

LiczbaGausa nww(LiczbaGausa& x, LiczbaGausa& y){
	LiczbaGausa w;
	LiczbaGausa m = mnozenie(x, y);
	LiczbaGausa n = nwd(x, y);
	w = dzielnik(m, n);

    return w;
}

int main(){
	LiczbaGausa x = {3, 4};
	LiczbaGausa y = {1, 3};

	LiczbaGausa n;

	n = nww(x, y);

	std::cout << "nww: " << n.real << " + " << n.imaginary << "i" << std::endl;

	return 0;
}