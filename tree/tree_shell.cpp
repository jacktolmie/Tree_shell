#include "tree_shell.hpp"

/* Tree_Shell constructor that passes the
 * name provided by the user for the shell name. 
 * It will be called Basicshell by default. */
Tree_Shell::Tree_Shell(std::string&& shell_name)
: Basicshell(shell_name)
{}

/* This registers the default commands for 
 * Tree_Shell, and starts the
 * Basicshell program for interactive sesson. */
void Tree_Shell::start_shell()
{
    Tree_Shell::register_defaults();
    Tree_Shell::unit_test();
    Basicshell::initial_shell();
}

void Tree_Shell::unit_test(){
    std::deque<std::string> tests;
    tests.push_back("test");
    tests.push_back("test.test1.test11.test111");
    tests.push_back("test.test2.test22.test222");
    tests.push_back("test.test2.test2222.test22222");
    tests.push_back("test.test2.test22.test_new_section.test22222");
    tests.push_back("test.test2.test22.test_new_section.test_another_new.test22222");
    tests.push_back("test.test2.test22.test_new_section.test_another_new.another_new_test.test22222222");
    tests.push_back("test.test2.test22.test_new_section.test_another_new.test22222.and_yet_another.22222222");
    tests.push_back("test_second.test33.test333.test3333");
    tests.push_back("test_third.test44.test444.test4444");
    tests.push_back("test_fourth.test55.test555.test5555");
    tests.push_back("test_fifth.test66.test666.test6666");
    tests.push_back("test_sixth.test77.test777.test7777");
    tests.push_back("test_sixth.test88.test888.test8888");
    
    for(auto& test: tests){
        std::deque<std::string> temp{test};
        Tree_Shell::load(temp);
    }
}
