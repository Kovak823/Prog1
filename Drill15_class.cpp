#include "std_lib_facilities.h"

struct Person{

	Person() {}
	Person(string ff, string ss, int aa);

	string first_name() const {return f;}
	string second_name() const {return s;}
	int age() const {return a;}

private:
	string f;
	string s;
	int a;
};

Person::Person(string ff, string ss, int aa)
	: f{ff}, s{ss}, a{aa}
{
	if (aa < 0 || aa > 150) error("Invalid age");
	string name = ff + ss;
	for ( char c : name ){
		switch(c){
			case ';': case ':': case '"': case '\'': case '[': case ']': case '*': 
			case '&': case '^': case '%': case '$': case '#': case '@': case '!':
			error("Invalid character");
		}

	}
}

istream& operator>>(istream& is, Person& p)
{
	string f;
	string s;
	int a;
	is >> f >> s >> a;

	if(!is) error("Cannot read into Person");

	p = Person(f, s, a);

	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.first_name() << ' ' << p.second_name() << ' ' << p.age();
}


int main(){

	//Person p{"Goofy", 63};
	//cout << p << endl;

	vector<Person> v;

	cout << "Enter firstname, lastname and age! To end enter 'end' instead of name" << endl;

	for ( Person p; cin >> p; ){
		if (p.first_name()=="end") 
		break;
		v.push_back(p);
	}

	for ( Person p : v ){
		cout << p << endl;
	}

}