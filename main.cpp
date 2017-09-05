
#include "main.h"


int main(int argc, char** argv) {
  std::string sort_algorithm;
  try
    {
      std::unique_ptr<TCLAP::CmdLine> cmd(new TCLAP::CmdLine(VERSION,DELIMITER,USAGE));
      TCLAP::UnlabeledValueArg<std::string> algo_name_cmd ("algorithm",
							   "Name of sorting algorithm",
							   false,
							   "bubble",
							   "String",
							   *cmd,
							   NULL);
      cmd->parse(argc, argv);
      sort_algorithm = algo_name_cmd.getValue();

    } catch (TCLAP::ArgException &e)
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE);}

  std::unique_ptr<SORT_ALGORITHM_LIST> algorithm_list(new(SORT_ALGORITHM_LIST)());
  bool found(false);

  for(unsigned i = 0; i < algorithm_list->get_algorithm_list()->size() && !found; i++)
    {
      if(algorithm_list->get_algorithm_list()->at(i)->get_algorithm_name() == sort_algorithm)
	{
	  found = true;
	  clock_t begin(0), end(0);
	  begin = clock();
	  std::cout << "****************************************************" << std::endl;
	  algorithm_list->get_algorithm_list()->at(i)->sort();
	  std::cout << "****************************************************" << std::endl;
	  end = clock();
	  std::cout<<"Total Time elapsed is : "<<1000.0 * (double(end - begin) / CLOCKS_PER_SEC) <<"ms" << std::endl;
	 
	}
    }

  if(!found){
    std::cout << "Invalided Algorithm specified" << std::endl;
    std::cout << "Valid algorithms are:" << std::endl;
    for(unsigned i = 0; i < algorithm_list->get_algorithm_list()->size(); i++)
      std::cout << algorithm_list->get_algorithm_list()->at(i)->get_algorithm_name() << std::endl;
    
  }

  exit(EXIT_SUCCESS);
}



  
