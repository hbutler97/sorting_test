#ifndef INC_SORT_INTERFACE_H
#define INC_SORT_INTERFACE_H

#include <string>
#include <vector>
class SORT_INTERFACE
{

public:
  SORT_INTERFACE(void){};
  SORT_INTERFACE(std::string algorithm_name);
  virtual ~SORT_INTERFACE(void){};
  virtual std::vector<int> sort(void) = 0;
  virtual std::string get_algorithm_name(void) = 0;
private:
protected:
};
#endif //INC_SORT_INTERFACE_H
