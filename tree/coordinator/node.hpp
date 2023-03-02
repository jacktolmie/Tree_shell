#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string_view>
#include <memory>
#include <vector>

// Useless class. Only for testing. Delete when done.
class Runnable
{
public:
// cppcheck-suppress noExplicitConstructor
	Runnable(std::string_view name)
	{
		std::cout << "\nRunnable called as: " << name << "\n";
	}
};

class Node
{
public:
    explicit Node(std::string_view);
    std::string node_name;
    
    /* A vector to hold the children of the node that contains tests or
     *  other suites. */
    std::vector<std::shared_ptr<Node>> children;
    
    // Shared pointer to runnable sent with the caller.
    std::shared_ptr<Runnable> runnable;
};

#endif // NODE_HPP
