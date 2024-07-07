#include <iostream>
#include "vectoref.h"
#include <vector>
using namespace std;
int main()
{
	vectoref<string> f{"HELLO", "FF", "GG"};
	f.sort();
	f.getFull();
}