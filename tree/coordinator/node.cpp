#include "node.hpp"

Node::Node(std::string_view name): node_name{name}, runnable{std::make_shared<Runnable>(name)}
{
    std::cout<<"Added "<< name <<'\n';
}
