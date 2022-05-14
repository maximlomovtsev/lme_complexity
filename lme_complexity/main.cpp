#include "impl/analyzer.h"

#include <cxxopts.hpp>

#include <stdexcept>
#include <iostream>
#include <vector>

enum main_error_code : int
{
    success = 0,
    general_error,
    incorrected_args_count,
    analysis_failed,
    unknown_error
};

const std::string project_name = LME_PROJECT_NAME;

int main(int argc, char** argv)
{
    try
    {
        cxxopts::Options options(project_name);

        options.add_options()
            ("h,help", "Show help message")
            ("f, file", "Select file for analysis", cxxopts::value<std::string>())
            ;

        const auto result = options.parse(argc, argv);
        if(!result.arguments().size())
        {
            std::cout << options.help();
            return main_error_code::incorrected_args_count;
        }

        if(result.count("file"))
        {
            const auto file = result["file"].as<std::string>();
            std::cout << "Selected file: " << file << std::endl;

            lme::complexity::analyzer file_analyzer(file);
            if(!file_analyzer.analyze())
            {
                return main_error_code::analysis_failed;
            }
        }

        return main_error_code::success;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return main_error_code::general_error;
    }
    catch(...)
    {
        std::cerr << "Unhandled exception" << std::endl;
        return main_error_code::unknown_error;
    }
}