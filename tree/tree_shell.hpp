#ifndef TREE_SHELL_HPP
#define TREE_SHELL_HPP

#include <iostream>
#include <string_view>
#include "../../../basicshell.hpp"
#include "coordinator/coordinator.hpp"
//#include "goldilocks/test.hpp"

#include <deque> //Delete when done unit test for list function
//For my testing of suites. Delete later
#include "suite_testing/suite.hpp"
#include "coordinator/node.hpp"


class Tree_Shell: private Basicshell, private Coordinator
{
 
private:

    std::shared_ptr<Node> root_node{std::make_shared<Node>("root")};
    
    using _register = std::function<int(std::deque<std::string>&)>;
    using commands = std::deque<std::string>&;
    /* information about the a specific test */
    int about(commands);
    
    /* Runs a benchmark on [test], using its registered 
     * comparative, with (number) repetitions. */
    int benchmark(commands);
    
    /* Runs a comparative benchmark between [test1] and 
     * [test2] with (number) repetitions. This is seldom
     * used, as its prone to apples-and-oranges comparisons,
     * unlike benchmark, but it can be useful at times. */
    int compare(commands);
    
    /* Function to register find_node on the shell. Used to
     * find tests that are currently loaded. */
    int find(commands);
    
    /* Displays the available suites. Passing an optional
     * (suite) will display all the tests in that suite. */
    int list (commands);
    
    /* Function to register load_node test to the shell.
     * Used to load all the suites, or the suites passed
     * as arguments. */
    int load (commands);
    
    /* Runs an [item], being a test or suite, with the
     * optional (number) of repetitions, default 1. */
    int run(commands);
    
    /* Runs a [test] as a "controlled crash", logging test
     * details to an external file on the way down. This is
     * the only way to run Fatality Tests, but is also
     * useful for Stress Tests, Edge Tests, and Fuzz Test
     * when a crash is occurring. */
    int kamikaze(commands);
    
    /* Register default commands to add to the container
     * of available commands. */
    void register_defaults();

    /* Unit test to load various tests to check list
     * function recursive calls. Delete when finished. */
    void unit_test();
 
public:
    Tree_Shell(std::string&& shell_name = "Tree Shell");
    ~Tree_Shell() = default;
    void start_shell();
};

#endif  // GOLDILOCKS_SHELL_HPP
