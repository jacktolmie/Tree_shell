#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <memory>
//#include <string_view>

#include "node.hpp"
//#include "../../../../../basic_shell/basicshell.hpp"

class Coordinator// : virtual private Basicshell
{
public:
    using commands = std::deque<std::string>;
    using node_ptr = std::shared_ptr<Node>;

    // Default name for the starter node.
    std::string name{"root"};
    
    Coordinator() = default;
    ~Coordinator() = default;
    
    void add_child(std::string_view, node_ptr node);
    
    /* Function to find children in the vector m_children. Returns a
     * shared_ptr with the node if found, otherwise shared_ptr of nullptr.
     */    
    node_ptr find_child(std::string, node_ptr);
    
    /* Looks for node with node_path value. Returns a shared_ptr if found. */
    node_ptr find_node(commands&, node_ptr);
    
    /* Adds a new child to the current node. It calls find_node to check if
     * on_node is empty. If so, root is the parent, otherwise calls find_node.
     */
    void load_node(std::string &, commands&, node_ptr);

    /* Function to register find_node on the shell. */
    int find(commands&);
    
    /* Function to register load_node test to the shell. */
    int load(commands&);

    /* Function to break the list of tests to load into
     * tokens to be used to add to the tree. */
    commands process_tests(commands&);

    /* Function to register commands into Blueshell. */
    void register_defaults();

    /* Splits a string sent to it into tokens. */
    void split_string(std::string&, char, std::vector<std::string>&);
};

#endif  // COORDINATOR_HPP
