#include "std_lib_facilities.h"

struct Person{
	Person(): magassag(0), suly(0), nem(""), kor(0) {};
	Person(int m, int s, string n, int k): magassag(m), suly(s), nem(n), kor(k){};
	int magassag;
	int suly;
	string nem;
	int kor;


};

istream& operator>>(istream& is,Person& p) {
	int magassag;
	int suly;
	string nem;
	int kor;
	is >> magassag >> suly >> nem >> kor;
	if(!is) error("Nem megfelelő formátum!");
	p = Person(magassag, suly, nem, kor);
	return is;
} 

ostream& operator<<(ostream& os, Person& p){
	return os << "Magasság: " << p.magassag << " cm\n" << "Súly: " << p.suly << " kg\n" << "Neme: " << p.nem << "\n" << "Kor: " << p.kor << endl;
}

int main(){

	cout << "Írja be a magasságát, testsúlyát, nemét és életkorát!(szóközzel elválasztva)" << endl;
	Person tt;
	cin >> tt;
	cout << tt << endl;
	auto BMI = [](int s, int m){ return  (double)s / ((double)m * (double)m);};
	cout << "BMI: " << BMI(tt.suly, tt.magassag) << endl;

	return 0;
}