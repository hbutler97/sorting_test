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
  virtual int sort(std::vector<int> *data, bool debug=false);
private:
  std::string m_name;
};

class BUBBLE_SORT2:
public virtual SORT_INTERFACE
{
public:
  BUBBLE_SORT2(std::string engine_name);
  ~BUBBLE_SORT2(void);
  std::string get_algorithm_name(void){return m_name;};
  virtual int sort(std::vector<int> *data, bool debug=false);
private:
  std::string m_name;
};
class BUBBLE_SORT3:
public virtual SORT_INTERFACE
{
public:
  BUBBLE_SORT3(std::string engine_name);
  ~BUBBLE_SORT3(void);
  std::string get_algorithm_name(void){return m_name;};
  virtual int sort(std::vector<int> *data, bool debug=false);
private:
  std::string m_name;
};
#endif //INC_SORT_ALGORITHMS_H
