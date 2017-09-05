#ifndef INC_SORT_ALGORITHM_LIST_H
#define INC_SORT_ALGORITHM_LIST_H
//# INCLUDE FILES //////////////////////////////////////////////////////////
#include "sort_interface.h"
#include "sort_algorithms.h"
class SORT_ALGORITHM_LIST
{
public:
     SORT_ALGORITHM_LIST(void){init_list();};
     ~SORT_ALGORITHM_LIST(void)
       {
	 for(unsigned i = 0; i < m_sort_list.size(); i++){
	   delete(m_sort_list[i]);
	 }
       };
     std::vector<SORT_INTERFACE*> *get_algorithm_list(void){return &m_sort_list;};
     void remove_algorithm(std::string name)
     {
         bool found_engine = false;

	 std::vector<SORT_INTERFACE*>::iterator position;
         for(position = m_sort_list.begin();
             position < m_sort_list.end();
             ++position)
	   {
	     if((*position)->get_algorithm_name() == name)
             {
                 m_sort_list.erase(position);
                 found_engine = true;
                 break;
	     }
	   }
         assert(found_engine);
     }
     
         
     

    
private:
    SORT_ALGORITHM_LIST(const SORT_ALGORITHM_LIST& sort_list);
    std::vector<SORT_INTERFACE*> m_sort_list;


    void init_list(void)
    {
      m_sort_list.push_back(new BUBBLE_SORT("bubble"));

    };

};


#endif //INC_SORT_ALGORITHM_LIST_H
