#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "study_Lamda.h"

using namespace std;

void goodBye(const string& a)
{
	cout << "bye" << a << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "object: hello " << s << endl;
	}
};

study_Lamda::study_Lamda()
{

}
void study_Lamda::lamda_test01()
{
	auto func = [](const int& i) -> void {cout << "hello" << endl; };

	func(123);

	[](const int& a) -> void {cout << "hello 01" << a << endl; }(123);

	{
		string name = "jack";
		[&]() {
			cout << name << endl; 
			name = "jack02";
		}();

		cout << name << endl;
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto fun2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), fun2);
	for_each(v.begin(), v.end(), [](int val) {cout << "for_each: " <<val << endl; });

	std::function<void(int)> fun3 = fun2;
	fun3(123);

	std::function<void(void)> fun4 = std:: bind(fun3, 890);
	fun4();

	Object instance;

	auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);
	f(string("world"));

	auto fun05 = std::bind(&goodBye, std::placeholders::_1);
	fun05(string("good"));

}
