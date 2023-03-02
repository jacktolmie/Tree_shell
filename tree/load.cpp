#include "tree_shell.hpp"

/* Takes the container of arguments/options, and sends it
 * to process_tests to be tokenized, then calls load_node
 * to add the tests to be added. */
int Tree_Shell::load(commands& options){
    auto processed_commands{Coordinator::process_tests(options)};
    for(auto& word: processed_commands) std::cout<< word << ' ';
    std::cout<<'\n';
    Coordinator::load_node(processed_commands.front(), processed_commands, Tree_Shell::root_node);
    return 0;
}
