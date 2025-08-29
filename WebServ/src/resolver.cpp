#include "Webserv.hpp"
#include "ast.hpp"

template <typename T>
static void set_ports(T& dst, ASTDirective d, ASTBlock block) {
    if (block.name != "server") throw std::runtime_error("listen should only be in server");
    if (d.args.size() != 1) throw std::runtime_error("error in listen directive");
    int port = strict_stoi(d.args[0]);
    if (port < 1 || port > 65535) throw std::runtime_error("port out of range");
    dst.port = d.args[0];
}

template <typename T>
static void set_hostname(T& dst, ASTDirective d, ASTBlock block) {
    if (block.name != "server") throw std::runtime_error("hostname should only be in server");
    if (d.args.size() != 1) throw std::runtime_error("error in hostname directive");
    dst.hostname = d.args[0];
}

template <typename T>
static void set_server_name(T& dst, ASTDirective d, ASTBlock block) {
    if (block.name != "server") throw std::runtime_error("server_name should only be in server");
    dst.names = d.args;
}

template <typename T>
static void set_error_files(T& dst, ASTDirective d) {
    if (d.args.size() < 2) throw std::runtime_error("error in error_page");
    int code;
    for (size_t i = 0; i < d.args.size() - 1; ++i) {
        code = strict_stoi(d.args[i]);
        dst.error_files[code] = d.args.back();
    }
}

template <typename T>
static void set_client_max_body_size(T& dst, ASTDirective d) {
    if (d.args.size() != 1) throw std::runtime_error("error in client_max_body_size");
    dst.client_max_body_size = strict_stoi(d.args[0]);
}

template <typename T>
static void set_root(T& dst, ASTDirective d) {
    if (d.args.size() != 1) throw std::runtime_error("error in root");
    dst.root = d.args[0];
}

template <typename T>
static void set_autoindex(T& dst, ASTDirective d) {
    if (d.args.size() != 1) throw std::runtime_error("error in autoindex");
    if (d.args[0] == "on") dst.autoindex = true;
    else if (d.args[0] == "off") dst.autoindex = false;
    else throw std::runtime_error("error in autoindex");
}

template <typename T>
static void set_redirect(T& dst, ASTDirective d) {
    if (d.args.size() != 2) throw std::runtime_error("error in redirects");
    dst.redirect = std::make_pair(strict_stoi(d.args[0]), d.args[1]);
}

template <typename T>
static void set_upload_path(T& dst, ASTDirective d) {
    if (d.args.size() != 1) throw std::runtime_error("error in upload_path");
    dst.upload_path = d.args[0];
}

template <typename T>
static void set_allowed_methods(T& dst, ASTDirective d) {
    dst.allowed_methods = d.args;
}

template <typename T>
static void set_cgi(T& dst, ASTDirective d) {
    if (d.args.size() != 3 && d.args.size() != 4) throw std::runtime_error("error in cgi");
    // if (!(d.args[0] == ".py" || d.args[0] == ".php"))
    // throw std::logic_error("only supports .py and .php cgi");
    // now supports tester ig..
    dst.cgi_handlers[d.args[0]].path = d.args[1];
    dst.cgi_handlers[d.args[0]].methods.assign(d.args.begin() + 1, d.args.end());
}

template <typename T>
static void set_default_index(T& dst, ASTDirective d) {
    if (d.args.size() < 1) throw std::runtime_error("error in index");
    dst.default_index = d.args;
}

template <typename T>
static void set_alias(T& dst, ASTDirective d) {
    if (d.args.size() != 1) throw std::runtime_error("error in alias");
    dst.alias = d.args[0];
    if (!dst.alias.empty() && dst.alias[dst.alias.length() - 1] != '/') { dst.alias += '/'; }
}

template <typename T>
static T resolveBlock(ASTBlock const& ast, Context const& defaults) {
    T ret;
    ret.client_max_body_size = defaults.client_max_body_size;
    ret.root = defaults.root;
    ret.autoindex = defaults.autoindex;
    ret.upload_path = defaults.upload_path;
    ret.error_files = defaults.error_files;
    ret.redirect = defaults.redirect;
    ret.cgi_handlers = defaults.cgi_handlers;
    ret.default_index = defaults.default_index;
    ret.allowed_methods = defaults.allowed_methods;

    for (size_t i = 0; i < ast.directives.size(); i++) {
        ASTDirective d = ast.directives[i];
        if (d.name == "listen") set_ports(ret, d, ast);
        else if (d.name == "hostname") set_hostname(ret, d, ast);
        else if (d.name == "server_name") set_server_name(ret, d, ast);
        else if (d.name == "error_page") set_error_files(ret, d);
        else if (d.name == "client_max_body_size") set_client_max_body_size(ret, d);
        else if (d.name == "root") set_root(ret, d);
        else if (d.name == "autoindex") set_autoindex(ret, d);
        else if (d.name == "return") set_redirect(ret, d);
        else if (d.name == "upload_path") set_upload_path(ret, d);
        else if (d.name == "allow_methods") set_allowed_methods(ret, d);
        else if (d.name == "cgi") set_cgi(ret, d);
        else if (d.name == "index") set_default_index(ret, d);
        else if (d.name == "alias") set_alias(ret, d);
        else if (d.name == "") continue;
        else throw std::runtime_error(d.name + ": unknown instruction");
    }

    for (size_t i = 0; i < ast.children.size(); ++i) {
        if (ast.children[i].name == "location") {
            ConfLoc child = resolveBlock<ConfLoc>(ast.children[i], ret);
            if (ast.children[i].args.size() != 1)
                throw std::runtime_error("unknown location prefix");
            child.prefix = ast.children[i].args[0];
            ret.locations.push_back(child);
        } else throw std::runtime_error("unknown instruction");
    }
    return ret;
}

ConfServ resolveServer(ASTBlock const& srvAST) {
    Context emptyDefaults;
    ConfServ srv = resolveBlock<ConfServ>(srvAST, emptyDefaults);
    return srv;
}
