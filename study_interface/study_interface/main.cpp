#include <iostream>
#include "ISTUDY.h"
using namespace std;


class mainClass01 : public IStudy
{
public:
	 void interface_study();
};

 void mainClass01::interface_study()
{
	 std::cout << "[mainClass01] interface test" << std::endl;
}

 class mainClass02 : public IStudy
 {
 public:
	 void interface_study();
 };

 void mainClass02::interface_study()
 {
	 std::cout << "[mainClass02] interface test" << std::endl;
 }

int main()
{
	// interface ÇÐ½À
	mainClass01* main_class01 = new mainClass01;
	mainClass02* main_class02 = new mainClass02;

	IStudy* iStudy = main_class01;
	iStudy->interface_study();

	iStudy = main_class02;
	iStudy->interface_study();
}