//
// Created by dais on 5/14/19.
//

#ifndef INC_3DENGINE_TESTRUNNER_H
#define INC_3DENGINE_TESTRUNNER_H


#include <functional>
#include <string>
#include <iostream>
#include <cassert>


using std::string;
using std::cout;
using std::endl;

#define INIT_TESTS(is_verbose) TestRunner tester; bool verbose=(is_verbose); cout << endl << \
            argv[0] << " ... " << endl
#define RUN_TEST(test_name) (tester.runTest((test_name), #test_name, verbose))
#define END_TESTS if (!verbose) cout << endl << "  ✔️" << endl

class TestRunner {
public:
    TestRunner() = default;

    TestRunner(const TestRunner &) = delete;

    ~TestRunner() = default;

    void runTest(const std::function<void()> &test_to_run, const string &test_name,
                 bool is_verbose) {
        if (is_verbose) cout << "Running " << test_name << " ... ";
        try {
            test_to_run();
        }
        catch (std::exception &e) {
            if (is_verbose) cout << "❌  Caught exception:" << endl << e.what();
            else cout << "❌  In test " << test_name << "Caught exception:" << endl << e.what();
        }
        if (is_verbose) cout << "✔️️";
    }
};

#endif //INC_3DENGINE_TESTRUNNER_H
