#include "tree_shell.hpp"

// Forward declaration of find_children.
std::string find_children(const std::shared_ptr<Node>& node, std::string node_path);

int Tree_Shell::list (std::deque<std::string>& options)
{
    std::cout<< '\n';
    for(auto& child: root_node->children){
        std::cout<<child->node_name <<':'<<'\n';
        find_children(child, std::string());
        std::cout<<'\n';
    }
    (void) options; //to suppress unused variable warning
    
    
    return 0;
}

std::string find_children(const std::shared_ptr<Node>& node, std::string node_path){
    /* If the children node is empty, print out
     * the node_path and return. */
    if(node->children.size() == 0){
        std::cout<< "->" << node_path <<"loaded." <<'\n';
        return std::string();
    }
    /* Recursive call to add node_name to the
     * node_path for each child node. */
    for(auto& child: node->children){
        find_children(child, node_path + (child->node_name + "->"));
    }
    return std::string();
}
