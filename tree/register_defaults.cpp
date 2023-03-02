#include "tree_shell.hpp"

void Tree_Shell::register_defaults()
{
    Basicshell::register_command("about", std::bind(&Tree_Shell::about, this, _1),"Display the documentation and other information for the indicated [item].", "Display the documentation and other information for the indicated [item]. An example is 'about calculator'", 1, 0);
    
    Basicshell::register_command("list", std::bind(&Tree_Shell::list, this, _1),"Displays the available suites.", "Displays the available suites. Passing an optional (suite) will display all the tests in that suite.", 0, 1);
    
    Basicshell::register_command("run", std::bind(&Tree_Shell::run, this, _1),"Runs an [item], being a test or suite.", "Runs an [item], being a test or suite, with the optional (number) of repetitions. The default is 1.", 1, 1);
    
    Basicshell::register_command("find", std::bind(&Tree_Shell::find, this, _1),
    "Checks if a test is loaded.", "Checks if a test is loaded after running 'load <test name>' to load the test. Call using find <test_name> (eg 'find test' or if further down the tree, find test.test1.test2 etc)", 1, 0);
    
    Basicshell::register_command("load", std::bind(&Tree_Shell::load, this, _1), "Loads the tests to run.",
    "Loads the tests to run from the available commands.  Call using 'load <test_name>' (eg 'load test' or if loading from further down the tree, find test.test1.test2 etc)", 1, 0);
}
