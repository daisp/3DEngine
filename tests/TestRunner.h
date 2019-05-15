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

// for code conciseness
using std::string;
using std::cout;
using std::endl;

// some text formatting tools
#define UNDERLINE "______________________________________________________________________"
#define OVERLINE  "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
#define PASS "🗸"
#define FAIL "❌"

// actual macros to use
#define FILE_GLOBAL_INIT TestRunner tester
#define MAIN_FUNC_INIT(is_verbose_macro_arg) \
    bool verbose = (is_verbose_macro_arg), did_fail_at_least_1 = false, cur_test_result; \
    string class_name = tester.extractFileNameFromFullPath(argv[0]); \
    cout << UNDERLINE << endl << "Testing:  " <<  class_name;\
    if (verbose) { \
        cout << endl; \
        cout << OVERLINE << endl; \
    } else { \
        cout << " ... ";\
    }

#define RUN_TEST(test_name) \
        if (verbose) cout << endl << (#test_name) << " ... "; \
        if (!tester.runTest((test_name), #test_name, verbose)) did_fail_at_least_1 = true;

#define END_TESTS \
    if (verbose) { \
        cout <<  OVERLINE << endl; \
    } \
    else { \
        if (did_fail_at_least_1) { \
            cout << class_name << "  " << FAIL; \
        } else { \
            cout << PASS; \
        } \
        cout << endl << OVERLINE; \
    }

#define ASSERT_TRUE(expression) tester.assertTrue((expression), __LINE__, __FILE__)
#define ASSERT_FALSE(expression) tester.assertFalse((expression), __LINE__, __FILE__)


// the actual tester class
class TestRunner {
public:
    TestRunner() = default;

    TestRunner(const TestRunner &) = delete;

    ~TestRunner() = default;

    TestRunner operator=(const TestRunner &) = delete;

    bool operator==(const TestRunner &) = delete;

    void assertTrue(const bool &expression, const int &line_num, const string &file_name) {
        if (!expression) throw AssertTrueIsFalseException(line_num, file_name);
    }

    void assertFalse(const bool &expression, const int &line_num, const string &file_name) {
        if (expression) throw AssertFalseIsTrueException(line_num, file_name);
    }

    bool runTest(const std::function<void()> &test_to_run, const string &test_name,
                 bool is_verbose) {
        try {
            test_to_run();
        }
        catch (std::exception &e) {
            cout << endl << FAIL << "  " << e.what() << endl;
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


    // exception base class
    class TestRunnerException : public std::exception {
    public:
        TestRunnerException(const int &line_num, const string &file_name) {
            this->message_stream << "In: " << file_name << ":" << line_num << ":" << endl << "    ";
            this->common_message = this->message_stream.str();
        }

        const char *what() const noexcept override = 0;

    protected:
        std::stringstream message_stream;
        string common_message;
    };

    // class-specific exception subclasses
    class AssertTrueIsFalseException : public TestRunnerException {
    public:
        AssertTrueIsFalseException(const int &line_num, const string &file_name)
                : TestRunnerException(line_num, file_name) {
            this->message_stream << "Expression should be true but it is false.";
            this->unique_message = this->message_stream.str();
        }

        const char *what() const noexcept override {
            return this->unique_message.c_str();
        }

    protected:
        string unique_message;
    };

    class AssertFalseIsTrueException : public TestRunnerException {
    public:
        AssertFalseIsTrueException(const int &line_num, const string &file_name)
                : TestRunnerException(line_num, file_name) {
            this->message_stream << "Expression should be false but it is true.";
            this->unique_message = this->message_stream.str();
        }

        const char *what() const noexcept override {
            return this->unique_message.c_str();
        }

    protected:
        string unique_message;
    };

};

#endif //INC_3DENGINE_TESTRUNNER_H
