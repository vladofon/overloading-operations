#pragma once
#include <iostream>
#include<cmath>
#include <string>

class triangle
{
public:

   triangle()
   {

      this->a_ = -1;
      this->b_ = -1;
      this->c_ = -1;
   }

   triangle(const int a, const int b, const int c)
      : a_(a),
      b_(b),
      c_(c)
   {
      std::cout << "Constructor with params:" << std::endl;
      std::cout << to_string() << std::endl;
   }

   triangle(const triangle& triangle)
   {


      this->a_ = triangle.get_a();
      this->b_ = triangle.get_b();
      this->c_ = triangle.get_c();

   }

   ~triangle()
   {

   }

   bool is_exist() const
   {
      if (a_ + b_ > c_ || a_ + c_ > b_ || c_ + b_ > a_)
         return true;

      return false;
   }

   int get_perimeter() const
   {
      return is_exist() ? a_ + b_ + c_ : -1;
   }

   double get_area() const
   {
      const int p = get_perimeter();

      return is_exist() ? sqrt(p * (p - a_) * (p - b_) * (p - c_)) : -1;
   }

   int get_a() const
   {
      return a_;
   }

   void set_a(const int a)
   {
      this->a_ = a;
   }

   int get_b() const
   {
      return b_;
   }

   void set_b(const int b)
   {
      this->b_ = b;
   }

   int get_c() const
   {
      return c_;
   }

   void set_c(const int c)
   {
      this->c_ = c;
   }

   std::string to_string() const
   {
      std::string dump = "triangle: [{\n";
      dump += "  side A: " + std::to_string(a_) + ",\n";
      dump += "  side B: " + std::to_string(b_) + ",\n";
      dump += "  side C: " + std::to_string(c_) + ",\n";
      dump += "  is exist: " + std::to_string(is_exist()) + ",\n";
      dump += "  perimeter: " + std::to_string(get_perimeter()) + ",\n";
      dump += "  area: " + std::to_string(get_area()) + ",\n";
      dump += "}];\n";

      return dump;
   }

   // prefix increment
   triangle& operator++()
   {
      set_a(get_a() + 1);
      set_b(get_b() + 1);
      set_c(get_c() + 1);

      std::cout << "++Prefix increment:\n" << to_string() << std::endl;

      return *this; // return new value by reference
   }

   // postfix increment
   triangle operator++(int)
   {
      triangle old = *this; // copy old value
      operator++();  // prefix increment

      std::cout << "Postfix increment++:\n" << old.to_string() << std::endl;

      return old;    // return old value
   }

   // prefix decrement
   triangle& operator--()
   {
      set_a(get_a() - 1);
      set_b(get_b() - 1);
      set_c(get_c() - 1);

      std::cout << "--Prefix decrement:\n" << to_string() << std::endl;

      return *this; // return new value by reference
   }

   // postfix decrement
   triangle operator--(int)
   {
      triangle old = *this; // copy old value
      operator--();  // prefix decrement

      std::cout << "Postfix decrement--:\n" << old.to_string() << std::endl;

      return old;    // return old value
   }

   triangle& operator*(const int rhs)
   {
      set_a(get_a() * rhs);
      set_b(get_b() * rhs);
      set_c(get_c() * rhs);

      std::cout << "Multiplication * :\n" << to_string() << std::endl;

      return *this;
   }

   operator bool() const
   {
      std::cout << "Existing (bool):\n" << to_string() << std::endl;

      return is_exist();
   }

private:
   int a_;
   int b_;
   int c_;
};

std::ostream& operator<<(std::ostream& out, const triangle& f)
{
   return out << "Object string representation:\n" << f.to_string();
}