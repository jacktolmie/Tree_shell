#include "tree_shell.hpp"

/* Takes the container of arguments/options, and sends it
 * to process_tests to be tokenized, then calls find_node
 * to check if the tests are loaded. */
int Tree_Shell::find(commands& options){
    auto processed_commands{Coordinator::process_tests(options)};
    Coordinator::find_node(processed_commands, Tree_Shell::root_node);
    return 0;
}
