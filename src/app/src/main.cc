#include <boost/program_options.hpp>
#include <iostream>

#include <dto_handler/dto_handler.hh>
#include <nael_utils/json/json_handler.hh>

namespace po = boost::program_options;

int exitAndReturn(int retCode){
	//Return
	return retCode;
}

int processArgs(po::variables_map const &vm)
{
	if( vm.count("debug") )
	{
		io::LoggerManager::SetLogLevel(io::LogLevel::DEBUG);
	}
	//input
	if( vm.count("input-file") )
	{
        std::cerr << "claude is poop" << std::endl;
		//Import dto
	    dto::DtoContext dto_context;
		INFOLOG << "Import " << vm["input-file"].as< std::string >() << std::endl;
		json::import_from_file(vm["input-file"].as< std::string >(), dto_context);
		DBUGLOG << "Got " << dto_context << std::endl;
		//convert dto to bo
		bo::BoContext bo_context;
		dto_handler::dto_to_bo(dto_context, bo_context);
		//export dto to file
		if( vm.count("output-file") )
		{
			json::export_to_file(vm["output-file"].as< std::string >(), dto_context);
		}
	}

	return exitAndReturn(0);
}

int main(int argc, char* argv[])
{
	std::ostringstream usage;
	try {
		po::options_description desc("Available options");
		desc.add_options()
			("help,h", "Print this message")
			("debug,d", "Activate debug log")
			("input-file,i", po::value< std::string >(), "Input file (.dbg | .json)")
			("output-file,o", po::value< std::string >(), "Output file (.json)")
		;

		usage << "Usage: options_description [options]" << std::endl;
		usage << desc;

		po::positional_options_description pod;
		pod.add("input-file", 1);
		pod.add("output-file", 1);

		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).
					options(desc).positional(pod).run(), vm);
		po::notify(vm);

		//Affichage de l'aide
		if( vm.empty() || vm.count("help") )
		{
			std::cout << usage.str();
			//Always exit if help required
			return exitAndReturn(0);
		}
		else
		{
			return processArgs(vm);
		}
	}
	//Catch boost program options exception
	catch(std::exception& e)
	{
		std::cerr << "Error in command line : " << e.what();
		std::cerr << usage.str();
		return exitAndReturn(1);
	}
}

