// Implement CFL generator as an NDFSPA 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// NDFSPA functions
std::string start(int depth, int max_depth);
std::string expression(int depth, int max_depth);
std::string number(int depth, int max_depth);
std::string digit(int depth, int max_depth);

int main(int argc, char* argv[])
{
  int max_depth = 10;
  std::srand(std::time(nullptr));

  if(argc == 2) {
    max_depth = std::atoi(argv[1]);
  }

  // generate and print a string
  std::cout << start(0, max_depth) << std::endl;
}

// < Start >      ::= < Expression >
std::string start(int depth, int max_depth)
{
  return expression(depth+1, max_depth);
}


// < Expression > ::= < Expression > "+" < Expression >
//                    | < Expression > "-" < Expression >
//                    | < Expression > "*" < Expression >
//                    | < Expression > "/" < Expression >
//                    | < Number >
std::string expression(int depth, int max_depth)
{
  int rule = rand() % 5;  

  if(depth > max_depth) {
    rule = 4;
  }

  switch(rule) {
    case 0:
      return expression(depth+1, max_depth) + "+" + expression(depth+1, max_depth);
    case 1:
      return expression(depth+1, max_depth) + "-" + expression(depth+1, max_depth);
    case 2:
      return expression(depth+1, max_depth) + "*" + expression(depth+1, max_depth);
    case 3: 
      return expression(depth+1, max_depth) + "/" + expression(depth+1, max_depth);
    default:
      return number(depth+1, max_depth);
  }
}


// < Number >     ::= < Number > < Digit >
//                    | < Digit >
std::string number(int depth, int max_depth)
{
  int rule = rand() % 2;  

  if(depth > max_depth) {
    rule = 1;
  }

  switch(rule) {
    case 0:
      return number(depth+1, max_depth) + digit(depth+1, max_depth);
    default:
      return digit(depth+1, max_depth);
  }
}


//  < Digit >      ::= "0" | "1" | "2" | ... | "9"
std::string digit(int depth, int max_depth)
{
  int d = rand() % 10;
  return std::to_string(d);
}