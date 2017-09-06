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
  virtual int sort(std::vector<int> *data, bool debug=false) = 0;
  virtual std::string get_algorithm_name(void) = 0;
private:
  
protected:
  void swap(std::vector<int>::iterator a, std::vector<int>::iterator b){
    int temp = *a;
    *a = *b;
    *b = temp;
  };
};
#endif //INC_SORT_INTERFACE_H
