#pragma once

#include <string>

namespace lme::complexity
{

class analyzer
{
public:
    analyzer(const std::string& filepath);

    bool analyze();

private:
    std::string filepath_;
};

} // namespace lme::complexity