#include "coordinator.hpp"

/* Function to find children in the vector children. Returns a
 * shared_ptr with the node if found, otherwise shared_ptr of nullptr. */
Coordinator::node_ptr Coordinator::find_child(std::string child_name, node_ptr node){

    // If the children container is empty, return nullptr.
    if(node->children.empty()){
        return nullptr;
    }
    // Check if node_name matches the searched name.
    auto child{std::find_if(node->children.begin(), node->children.end(), [&child_name](auto& child){
            return (child->node_name == child_name)? child : nullptr;
    })};
    // If match found, return pointer to node, otherwise return nullptr.
    return (child != node->children.end())? *child: nullptr;

}
