#include <stdio.h>

typedef struct Bruch{int zaehler; int nenner;} Rational;

Rational kuerzen(Rational);
Rational add(Rational, Rational);
Rational subtract(Rational, Rational);
Rational multiply(Rational, Rational);
Rational divide(Rational, Rational);
int ggT(int, int);
int kgV(int, int);
float toFloat(Rational);
void output(Rational);

int main(){
	Rational n1 = {3, 28};
	Rational n2 = {5, 6};
	//Rational n2;
	//scanf("%d %d", &n2.zaehler, &n2.nenner);
	Rational n3;
	float num1;
	n3 = add(n1, n2);
	printf("add:\t%d/%d\n", n3.zaehler, n3.nenner);
	n3 = subtract(n1, n2);
	printf("subtract: %d/%d\n", n3.zaehler, n3.nenner);
	n3 = multiply(n1, n2);
	printf("multiply: %d/%d\n", n3.zaehler, n3.nenner);
	n3 = divide(n1, n2);
	printf("devide:\t%d/%d\n", n3.zaehler, n3.nenner);
	num1 = toFloat(n1);
	printf("n1 -> float: %f\n", num1);
}

Rational kuerzen(Rational r){
    Rational n = {0, 0};
    int g = ggT(r.zaehler, r.nenner);
    n.zaehler = r.zaehler/g;
    n.nenner = r.nenner/g;
    return n;
}

Rational add(Rational a, Rational b){
    Rational n = {0, 0};

    int k = kgV(a.nenner, b.nenner);

    n.zaehler = (a.zaehler * (k / a.nenner)) + (b.zaehler * (k / b.nenner));
    n.nenner = k;

    return kuerzen(n);
}

Rational subtract(Rational a, Rational b){
    Rational n = {0, 0};

    int k = kgV(a.nenner, b.nenner);

    n.zaehler = (a.zaehler * (k / a.nenner)) - (b.zaehler * (k / b.nenner));
    n.nenner = k;

    return kuerzen(n);
}

Rational multiply(Rational a, Rational b){
    Rational n = {0, 0};

    n.zaehler = (a.zaehler * b.zaehler);
    n.nenner = (a.nenner * b.nenner);
    
    n = kuerzen(n);

    return n;
}

Rational divide(Rational a, Rational b){
    Rational n = {0, 0};

    n.zaehler = (a.zaehler * b.nenner);
    n.nenner = (a.nenner * b.zaehler);
    n = kuerzen(n);

    return n;
}

float toFloat(Rational r){
    return 1.0 * r.zaehler / r.nenner;
}

void output(Rational r){
    printf("%d / %d\n", r.zaehler, r.nenner);
}

int ggT(int a, int b){
    if(a==b||b==0)
        return a;
    else
        return ggT(b,a%b);
}

int kgV(int x, int y){
    return ((x*y) / ggT(x,y));
}


