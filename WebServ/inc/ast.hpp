#pragma once

#include <string>
#include <vector>

struct ASTDirective
{
    std::string					name;
    std::vector<std::string>	args;
};

struct ASTBlock
{
    std::string					name; // ex: server|location
    std::vector<std::string>	args; // ex: /static/
    std::vector<ASTDirective>	directives;
    std::vector<ASTBlock>		children;
};
