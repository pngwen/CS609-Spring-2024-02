// Implement CFL generator as an NDFSPA 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// NDFSPA functions
std::string start();
std::string expression();
std::string number();
std::string digit();

int main()
{
  std::srand(std::time(nullptr));

  // generate and print a string
  std::cout << start() << std::endl;
}

// < Start >      ::= < Expression >
std::string start()
{
  return expression();
}


// < Expression > ::= < Expression > "+" < Expression >
//                    | < Expression > "-" < Expression >
//                    | < Expression > "*" < Expression >
//                    | < Expression > "/" < Expression >
//                    | < Number >
std::string expression()
{
  int rule = rand() % 5;  

  switch(rule) {
    case 0:
      return expression() + "+" + expression();
    case 1:
      return expression() + "-" + expression();
    case 2:
      return expression() + "*" + expression();
    case 3: 
      return expression() + "/" + expression();
    default:
      return number();
  }
}


// < Number >     ::= < Number > < Digit >
//                    | < Digit >
std::string number()
{
  int rule = rand() % 2;  

  switch(rule) {
    case 0:
      return number() + digit();
    default:
      return digit();
  }
}


//  < Digit >      ::= "0" | "1" | "2" | ... | "9"
std::string digit()
{
  int d = rand() % 10;
  return std::to_string(d);
}