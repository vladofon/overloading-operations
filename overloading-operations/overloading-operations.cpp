#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
   std::cout << "Hello World!\n";

   auto bar = triangle(5, 5, 5);

   bar++;

   ++bar;

   bar--;

   --bar;

   bar * 10;

   cout << bar << endl;
}
