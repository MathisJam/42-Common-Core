#include "Webserv.hpp"
#include "ast.hpp"

const static std::string get_content(const char* file)
{
    std::ifstream in(file);
    if (!in) { throw std::runtime_error(std::string(file) + ": " + strerror(errno)); }
    std::stringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

struct Parser
{
    ConfWebserv webserv;
    size_t i;
    std::string content;

    Parser(const char* file) : i(0), content(get_content(file)) {};

    void skipSpace() {

        while (isspace(content[i])) ++i;
        if (content[i] == '#') {
            while (content[i] != '\n') ++i;
        }
        if (content[i] == '\n') skipSpace();
    }

    std::string readWord() {
        skipSpace();
        size_t start = i;
        while (i < content.size() && !isspace(content[i]) && content[i] != '{' &&
               content[i] != '}' && content[i] != ';')
            ++i;
        return content.substr(start, i - start);
    }

    ASTBlock parseBlock(std::string const& blockName = "") {
        ASTBlock block;
        block.name = blockName;

        while (true) {
            skipSpace();
            if (i >= content.size()) break;
            if (content[i] == '}') {
                i++;
                break;
            }
            std::string name = readWord();
            std::vector<std::string> args;
            while (true) {
                skipSpace();
                if (!content[i] || content[i] == ';' || content[i] == '{' || content[i] == '}')
                    break;
                args.push_back(readWord());
            }
            skipSpace();
            char c = content[i++];
            if (c == ';') {
                if (block.name == "" && name != "") throw std::runtime_error("invalid directive");
                ASTDirective d;
                d.name = name;
                d.args = args;
                block.directives.push_back(d);
            } else if (c == '{') {
                if (name == "server") {
                    if (args.size() != 0)
                        throw std::runtime_error(args[0] + ": invalid server directive");
                } else if (name == "location") {
                    if (args.size() != 1 || blockName != "server")
                        throw std::runtime_error("location: invalid location directive");
                } else throw ::std::runtime_error(name + ": invalid block");
                ASTBlock child = parseBlock(name);
                child.args = args;
                block.children.push_back(child);
            } else throw std::runtime_error("invalid token");
        }
        return block;
    }
};

ConfWebserv parse_config(const char* file)
{
    Parser p(file);
    ASTBlock root = p.parseBlock();
    if (p.content[p.i] != 0) throw std::runtime_error("invalid config");
    ConfWebserv conf;
    for (size_t i = 0; i < root.children.size(); ++i) {
        if (root.children[i].name == "server") {
            conf.servers.push_back(resolveServer(root.children[i]));
        }
    }
    return conf;
}
