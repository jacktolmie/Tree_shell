#include "coordinator.hpp"

/* Looks for node with node_path value. Returns a shared_ptr if found. */
Coordinator::node_ptr Coordinator::find_node(commands& node_path, node_ptr node){
    /* If there is node_path is empty, return the
     * current node. */
    if(node_path.empty()){
        return node;
    }
    // Check if node_name matches the first string in the node_path container.
    auto search_node{std::find_if(node->children.begin(), node->children.end(), [&node_path] (auto& searched_node){
         return searched_node->node_name == node_path.front();
    })};

    /* If the search_node matches, delete the first
     * element in the container, and recursively call
     * find_node with new string for which to look. */
    if(search_node != node->children.end()){
        std::cout<<"Found " << node_path.front() <<'\n';
        node_path.erase(node_path.begin());
        Coordinator::find_node(node_path, *search_node);
    }
    /* If the node_name does not match any nodes,
     * print message and return nullptr. */
    else{
        std::cout<<"Cannot find node: "<<node_path.front() <<" on the node: "<<node->node_name<<'\n';
        return nullptr;
    }
    return (search_node != node->children.end()) ? node: nullptr;
}
