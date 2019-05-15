//
// Created by dais on 5/14/19.
//

#ifndef INC_3DENGINE_TESTRUNNER_H
#define INC_3DENGINE_TESTRUNNER_H


#include <functional>
#include <string>
#include <iostream>
#include <cassert>
#include <sstream>


using std::string;
using std::cout;
using std::endl;

#define UNDERLINE "________________________________________________________________________________"
#define OVERLINE  "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"

#define PASS "🗸"
#define FAIL "❌"

#define INIT_TESTS(is_verbose_macro_arg) \
    bool verbose = (is_verbose_macro_arg); \
    cout << UNDERLINE << endl << "Testing:  " << tester.extractFileNameFromFullPath(argv[0]); \
    if (verbose) { \
        cout << endl; \
        cout << OVERLINE << endl; \
    }

#define RUN_TEST(test_name) tester.runTest((test_name), #test_name, verbose)
#define END_TESTS \
    if (!verbose) { \
        cout << " ... ️️" << PASS << endl << OVERLINE; \
    } \
    else { \
        cout << endl << OVERLINE << endl; \
    }

#define ASSERT_TRUE(expression) tester.assertTrue((expression), __LINE__, __FILE__)
#define ASSERT_FALSE(expression) tester.assertFalse((expression), __LINE__, __FILE__)


class TestRunner {
public:
    TestRunner() = default;

    TestRunner(const TestRunner &) = delete;

    ~TestRunner() = default;

    void assertTrue(const bool &expression, const int &line_num, const string &file_name) {
        if (!expression) throw AssertTrueIsFalseException(line_num, file_name);
    }

    void assertFalse(const bool &expression, const int &line_num, const string &file_name) {
        if (expression) throw AssertFalseIsTrueException(line_num, file_name);
    }

    bool runTest(const std::function<void()> &test_to_run, const string &test_name,
                 bool is_verbose) {
        if (is_verbose) cout << test_name << " ... ";
        try {
            test_to_run();
        }
        catch (std::exception &e) {
            if (is_verbose)
                cout << FAIL << "  Caught exception:" << endl << e.what() << endl << endl;
            else
                cout << FAIL << "  In test " << test_name << "Caught exception:" << endl << e.what()
                     << endl << endl;
            return false;
        }
        if (is_verbose) cout << PASS << endl;
        return true;
    }

    string extractFileNameFromFullPath(const string &full_path) {
        string file_name;
        for (auto it = full_path.rbegin(); it != full_path.rend(); ++it) {
            if (*it == '_') break;
            file_name.insert(0, 1, *it);
        }
        return file_name;
    }

    // exceptions
    class AssertTrueIsFalseException : public std::exception {
    public:
        AssertTrueIsFalseException(const int &line_num, const string &file_name) {
            std::stringstream message_stream;
            message_stream << "In file: " << file_name << endl <<"line " << line_num << endl <<
                           "Expression should be true but it is false.";
            this->message = message_stream.str();
        }

        const char *what() const noexcept override {
            return this->message.c_str();
        }

    private:
        string message;
    };

    class AssertFalseIsTrueException : public std::exception {
    public:
        AssertFalseIsTrueException(const int &line_num, const string &file_name) {
            std::stringstream message_stream;
            message_stream << "In file: " << file_name << endl <<"line " << line_num << endl <<
                           "Expression should be false but it is true.";
            this->message = message_stream.str();
        }

        const char *what() const noexcept override {
            return this->message.c_str();
        }

    private:
        string message;
    };
};

#endif //INC_3DENGINE_TESTRUNNER_H
