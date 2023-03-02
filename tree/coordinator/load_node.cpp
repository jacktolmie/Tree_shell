#include "coordinator.hpp"

/* Adds a new child to the current node. It calls find_node to check
 * if nodes children container is empty. If so, root is the current node, otherwise calls find_node. */
void Coordinator::load_node(std::string& new_child, commands& on_node, node_ptr node){

    /* Check if the test the user wants to load is already loaded,
     * if so, print message. */
    if(on_node.size() == 1 && Coordinator::find_child(new_child, node) != nullptr){
        std::cout<<"\nNode "<<new_child<<" is already loaded\n";
        return;
    }

    /* If on_node is empty, add child to node. on_node is a container
     * that is used to hold the searched string. */
    if(on_node.empty()){
        return;
    }
    else if(!on_node.empty()){
        auto check_node{Coordinator::find_child(new_child,node)};

        if(check_node == nullptr){
            node->children.push_back(std::make_shared<Node>(new_child));
            on_node.erase(on_node.begin());
            new_child = on_node.front();
            node = node->children.back();
            if(on_node.empty()){
                return;
            }
            Coordinator::load_node(new_child, on_node, node);
        }
        else{
            on_node.erase(on_node.begin());
            new_child = on_node.front();
            node = check_node;
            if(on_node.empty()){
                return;
            }
            Coordinator::load_node(new_child,on_node, check_node);
        }
    }
}
