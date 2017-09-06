#include "sort_algorithms.h"
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT::BUBBLE_SORT
(
 std::string name
):
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
m_name(name)
{
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
int BUBBLE_SORT::sort(std::vector<int> *data, bool debug)

//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
  std::vector<int>::iterator begin = data->begin();
  bool swap_occurred(false);
  int passes(0);
  do
    {
      swap_occurred = false;
      
      for(unsigned i = 0; i < data->size() - 1; i++){
	if(*(begin + i) > *(begin + i + 1)){
	  swap(begin+i, begin + i + 1);
	  swap_occurred = true;
	}
	passes++;
      }

    } while(swap_occurred);
  if(debug)
    {
     
      for(unsigned i = 0; i < data->size(); i++){
	std::cout << data->at(i) << std::endl;
      }
    }
  return passes;
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT::~BUBBLE_SORT(void)
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
}


//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT2::BUBBLE_SORT2
(
 std::string name
):
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
m_name(name)
{
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
int BUBBLE_SORT2::sort(std::vector<int> *data, bool debug)

//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
  std::vector<int>::iterator begin = data->begin();
  bool swap_occurred(false);
  int passes(0);
  unsigned n = data->size();

  do
    {
      swap_occurred = false;
      for(unsigned i = 0; i < n - 1; i++){
	if(*(begin + i) > *(begin + i + 1)){
	  swap(begin+i, begin + i + 1);
	  swap_occurred = true;
	}
	passes++;
      }
      n = n - 1;
    } while(swap_occurred);
  if(debug)
    {

      for(unsigned i = 0; i < data->size(); i++){
	std::cout << data->at(i) << std::endl;
      }
    }
  return passes; 
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT2::~BUBBLE_SORT2(void)
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
}

//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT3::BUBBLE_SORT3
(
 std::string name
):
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
m_name(name)
{
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
int BUBBLE_SORT3::sort(std::vector<int> *data, bool debug)

//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
  std::vector<int>::iterator begin = data->begin();
  bool swap_occurred(false);
  int passes(0);
  unsigned n = data->size();
  do
    {
      swap_occurred = false;
      unsigned newn = 0;      
      for(unsigned i = 0; i < n - 1; i++){
	if(*(begin + i) > *(begin + i + 1)){
	  swap(begin+i, begin + i + 1);
	  swap_occurred = true;
	  newn = i + 1;
	}
	passes++;
      }
      n = newn;
      
    } while(swap_occurred);
  if(debug)
    {

      for(unsigned i = 0; i < data->size(); i++){
	std::cout << data->at(i) << std::endl;
      }
    }
  return passes; 
}
//START_FUNCTION_HEADER//////////////////////////////////////////////////////
BUBBLE_SORT3::~BUBBLE_SORT3(void)
//
// Description: Constructor.  
//
// Returns:  None
//
//END_FUNCTION_HEADER////////////////////////////////////////////////////////
{
}
