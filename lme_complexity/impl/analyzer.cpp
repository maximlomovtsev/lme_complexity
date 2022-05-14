#include "analyzer.h"

#include <fstream>

namespace lme::complexity
{

analyzer::analyzer(const std::string& filepath)
    : filepath_{filepath}
{

}

bool analyzer::analyze()
{
    std::ifstream file_stream(filepath_, std::ios_base::in);
    if(!file_stream.is_open())
    {
        return false;
    }
    if(!file_stream.good())
    {
        return false;
    }
    return true;
}

} // namespace lme::complexity