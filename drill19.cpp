#include "std_lib_facilities.h"

template<typename T>
struct S {
	S(T d) : val(d) {}
	T& get();
	const T& get() const;
	S& operator=(const T&);

	void set(T new_val) {val=new_val;};
private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T> const
T& S<T>::get() const
{
	return val;
}

template<typename T> 
S<T>& S<T>::operator=(const T& y){
	val = y;
	return *this;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}

int main(){

	S<int> si(12);
	cout << si.get() << endl;

	S<char> sc('x');
	cout << sc.get() << endl;

	S<double> sd(5.1);
	cout << sd.get() << endl;

	S<string> st("alma");
	cout << st.get() << endl;
	st="körte";
	cout << st.get() << endl;

	S<vector<int>> svi(vector<int>{5,10,15,20,25});
	
	for(int value : svi.get())
		cout << value << ",";
	cout << endl;

	cout << "Adj meg egy int értéket: " << endl;
	read_val(si.get());

	cout << "Adj meg egy karaktert: " << endl;
	read_val(sc.get());

	cout << "Adj meg egy double értéket: " << endl;
	read_val(sd.get());

	cout << si.get() << endl;
	cout << sc.get() << endl;
	cout << sd.get() << endl;

	return 0;	
}