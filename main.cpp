
#include "main.h"


int main(int argc, char** argv) {
  std::string sort_algorithm;
  bool debug(false);
  unsigned numb_samples(0);
  bool random_data(false);
  try
    {
      std::unique_ptr<TCLAP::CmdLine> cmd(new TCLAP::CmdLine(VERSION,DELIMITER,USAGE));
      TCLAP::ValueArg<std::string> algo_name_cmd ("a",
						  "algorithm",
						  "Name of sorting algorithm",
						  false,
						  "bubble",
						  "String",
						  *cmd,
						  NULL);

      TCLAP::ValueArg<unsigned int> numb_samples_cmd ("n",
						     "numb_samples",
						     "Number of elements to be sorted",
						     false,
						     100,
						     "Integer",
						     *cmd,
						     NULL);
      TCLAP::SwitchArg debug_cmd("d",
				 "debug",
				 "Runs in Debug mode",
				 *cmd,
				 false,
				 NULL);

      TCLAP::SwitchArg random_cmd("r",
				 "random",
				 "Generate Random Data",
				 *cmd,
				 false,
				 NULL);
      cmd->parse(argc, argv);
      sort_algorithm = algo_name_cmd.getValue();
      debug = debug_cmd.getValue();
      numb_samples = numb_samples_cmd.getValue();
      random_data = random_cmd.getValue();

    } catch (TCLAP::ArgException &e)
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE);}

  std::unique_ptr<SORT_ALGORITHM_LIST> algorithm_list(new(SORT_ALGORITHM_LIST)());
  bool found(false);

  for(unsigned i = 0; i < algorithm_list->get_algorithm_list()->size(); i++)
    {
      if(algorithm_list->get_algorithm_list()->at(i)->get_algorithm_name() == sort_algorithm)
	{
	  found = true;
	  clock_t begin(0), end(0);
	  std::vector<int> data =generate_data(numb_samples, random_data);
	  begin = clock();
	  std::cout << "****************************************************" << std::endl;
	  int iterations = algorithm_list->get_algorithm_list()->at(i)->sort(&data, debug);
	  std::cout << "Iterations: " << iterations << std::endl;
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

std::vector<int> generate_data(unsigned int size, bool random)
{
  std::vector<int> input_data;
  
  std::random_device seeder;
  std::mt19937 engine(seeder());
  std::uniform_int_distribution<int> dist(0, size);
  int numb = size;

  for(unsigned int i = 0; i < size; i++){
    if(random)
      input_data.push_back(dist(engine));
    else{ //worse case sort required
      input_data.push_back(numb);
      numb = numb - 1;
    }
  }
  return input_data;
}

  
