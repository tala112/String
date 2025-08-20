//Tala Fahed 12219511
//oop2 based on dr's code

#include <iostream>
#include <string.h>
#include <math.h>
#include <cassert>

using  namespace std;

#pragma warning(disable : 4996)

class String
{
private:
	char* s;
public:

	String() :s(NULL)
	{
		sets("hello");
	}
	String(const char* x) :s(NULL)  //converting constructor..
	{
		sets(x);
	}
	String(const char y) :s(NULL)
	{
		char a[2] = { y,NULL };
		sets(a);
	}
	String(const int y) :s(NULL)
	{
		char a[2] = { y,NULL };
		sets(a);
	}
	String(const String& R) :s(NULL)
	{
		sets(R.gets());
	}

	~String()
	{
		if (s)
			delete[]s;
		s = NULL;
	}

	char& operator [] (int index)
	{
		assert(index >= 0 && index < strlen(gets()));
		return gets()[index];
	}

	inline char* gets()const
	{
		return s;
	}
	inline void sets(const char* p = "goofy")
	{
		this->~String();
		//s = new char[strlen(p) + 1];
		//strcpy(s, p);

		s = strdup(p);

	}

	friend  ostream& operator << (ostream& out, const String& R)
	{
		out << endl << R.gets();
		return out;
	}
	friend  istream& operator >> (istream& in, String& R)
	{
		char* p = new char[10000];
		cout << "\nEnter a string?";
		//in.getline(p, 1000);
		in >> p;
		R.sets(p);

		delete[]p;

		return in;
	}

	String& operator = (const String& R)
	{
		if (this != &R)
			sets(R.gets());
		return *this;

	}
	String& operator = (const char* R)
	{
		sets(R);
		return *this;

	}
	String& operator = (const char R)
	{
		String T = R;
		*this = T;
		return *this;

	}
	String& operator = (const int R)
	{
		*this = char(R);
		return *this;

	}

	String operator + (const String& R)
	{
		char* p = new char[strlen(gets()) + strlen(R.gets()) + 1];
		strcpy(p, gets());
		strcat(p, R.gets());

		String T = p;
		delete[] p;

		return T;
	}
	String operator + (const char* R)
	{
		String T(R);

		T = *this + T;

		return T;
	}
	String operator + (const char R)
	{
		String T(R);

		T = *this + T;

		return T;
	}
	String operator + (const int R)
	{
		String T(R);

		T = *this + T;

		return T;
	}

	String operator += (const String& R)
	{
		return *this = *this + R;
	}
	String operator += (const char* R)
	{
		return *this = *this + R;
	}
	String operator += (const char R)
	{
		return *this = *this + R;
	}
	String operator += (const int R)
	{
		return *this = *this + R;
	}

	String operator - (const String& R)
	{
		char* l = strdup(gets());

		char* r = R.gets();

		char* M = NULL;

		while (M = strstr(l, r))
		{
			char* q = M + strlen(r);
			strcpy(M, q);
		}


		String T = l;
		delete[] l;

		return T;
	}
	String operator - (const char* R)
	{
		String T = R;
		T = *this - T;
		return T;
	}
	String operator - (const char R)
	{
		String T = R;
		T = *this - T;
		return T;
	}
	String operator - (const int  R)
	{
		String T = R;
		T = *this - T;
		return T;
	}

	String operator -= (const String& R)
	{
		return *this = *this - R;
	}
	String operator -= (const char* R)
	{
		return *this = *this - R;
	}
	String operator -= (const char R)
	{
		return *this = *this - R;
	}
	String operator -= (const int  R)
	{
		return *this = *this - R;
	}

	int operator >(const String& R)
	{
		return stricmp(gets(), R.gets()) > 0;
	}
	int operator >(const char* R)
	{
		return stricmp(gets(), R) > 0;
	}
	int operator >(const char  R)
	{
		char T[2] = { R,NULL };
		return *this > T;
	}
	int operator >(const int  R)
	{
		char T[2] = { R,NULL };
		return *this > T;
	}

	int operator <=(const String& R)
	{
		return !(*this > R);
	}
	int operator <=(const char* R)
	{
		return !(*this > R);
	}
	int operator <=(const char R)
	{
		return !(*this > R);

	}
	int operator <=(const int  R)
	{
		return !(*this > R);

	}

	int operator ==(const String& R)
	{
		return stricmp(gets(), R.gets()) == 0;
	}
	int operator ==(const char* R)
	{
		return stricmp(gets(), R) == 0;
	}
	/* here new 2 */
	int operator ==(const char R)
	{
		char T[2] = { R,NULL };
		return *this == T;
	}
	int operator ==(const int R)
	{
		char T[2] = { R,NULL };
		return *this == T;
	}

	int operator !=(const String& R)
	{
		return !(*this == R);
	}
	/* here new 3 */
	int operator !=(const char* R)
	{
		return !(*this == R);
	}
	int operator !=(const char R)
	{
		char T[2] = { R,NULL };
		return !(*this == T);
	}
	int operator !=(const int R)
	{
		char T[2] = { R,NULL };
		return !(*this == T);
	}

	int operator < (const String& R)
	{
		return !(*this == R || *this > R);
	}
	/* here new 3 */
	int operator < (const char* R)
	{
		return !(*this == R || *this > R);
	}
	int operator < (const char R)
	{
		char T[2] = { R,NULL };
		return !(*this == T || *this > T);
	}
	int operator < (const int R)
	{
		char T[2] = { R,NULL };
		return !(*this == T || *this > T);
	}

	/* here new 4 */
	int operator >= (const String& R) {
		return !(*this < R);
	}
	int operator >= (const char* R) {
		return !(*this < R);
	}
	int operator >= (const char R) {
		return !(*this < R);
	}
	int operator >= (const int R) {
		return !(*this < R);
	}

};

template <class ZZ>
void read(ZZ* p)
{
	for (int i = 0; i < 10; i++)
		cin >> *p++;

}

template <class ZZ>
void display(ZZ* p)
{
	for (int i = 0; i < 10; i++)
		cout << *p++;

}

template <class ZZ>
void getmax(ZZ* p)
{
	ZZ* max = p;

	for (int i = 0; i < 10; i++) {
		if (p->gets() > max->gets())
			max = p;
		p++;

	}
	cout << endl << "the max string -->>" << *max;
}

template <class ZZ>
void sort(ZZ* arr)
{
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j < 10; j++)
			if (arr[i] > arr[j])
			{
				ZZ T = arr[i];
				arr[i] = arr[j];
				arr[j] = T;
			}
}

template <class ZZ>
void getmin(ZZ* p)
{
	ZZ* min = p;

	for (int i = 0; i < 10; i++) {
		if (p->gets() < min->gets())
			min = p;
		p++;

	}

	cout << endl << "the min string -->>" << *min;

}

// searching
template <class ZZ>
int search(ZZ* p, const ZZ& obj) {
	for (int i = 0; i < 10; i++) {
		if (p[i] == obj)return i;
	}
	return -1;
}

// replacing a string with another string
template <class ZZ>
void replace(ZZ* p, const ZZ& old, const ZZ& newobj) {
	int i = search(p, old);
	if (i != -1) p[i] = newobj;

}

//  merging an array of strings.
template <class ZZ>
void merge(ZZ* x, int s1, ZZ* y, int s2, ZZ* result) {
	for (int i = 0; i < s1; ++i)
		result[i] = x[i];
	for (int i = 0; i < s2; ++i)
		result[s1 + i] = y[i];
}


int main(void)
{
	/*
	String y("bee");
	String m = x;
	String a = 67;
	String b = 'r';
	String t = b;
	*/

	/*my test*/
	String x[4] = { "ff" ,"hhhh","kkkkkk" };
	String xz("ff"), ys("ll");
	String y[2] = { "hlo" };

	String arr[10] = { "dddddddd","ff","sgdd","gfg","figji","ritj" }, d[10];
	String* p = arr;
	cout << search(arr, xz);
	replace(arr, xz, ys);
	display(arr);
	cout << endl;
	merge(x, 3, y, 1, d);
	display(d);
	cout << endl;

	//read(arr);
	//display(arr);
	//getmax(arr);
	//getmin(arr);

	sort(arr);
	display(arr);

	//a = "abdHHdcddd";
	//a = strupr(a.gets());     
	//a= C string style... ( char *)
/*dr ex ........*/
	return 0;
}