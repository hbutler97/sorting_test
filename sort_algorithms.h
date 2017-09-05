#ifndef INC_SORT_ALGORITHMS_H
#define INC_SORT_ALGORITHMS_H

#include "sort_interface.h"
#include <iostream>
class BUBBLE_SORT:
public virtual SORT_INTERFACE
{
public:
  BUBBLE_SORT(std::string engine_name);
  ~BUBBLE_SORT(void);
  std::string get_algorithm_name(void){return m_name;};
  virtual std::vector<int> sort(void);

     
     
private:
  std::string m_name;
};
#endif //INC_SORT_ALGORITHMS_H
