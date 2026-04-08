#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"



TEST_CASE("Cannot input an empty field to task input") {
    TodoList tasks;

    REQUIRE(tasks.add("") == false);
    REQUIRE(tasks.add("  ") == false);
    REQUIRE(tasks.size() == 0);
};

TEST_CASE("Done tasks are clearly tagged with a mark as done") {
    TodoList tasks;
    tasks.add("Clean the house");

    REQUIRE(tasks.complete(1) == true);

    vector<string> accomplishedtasks = tasks.complete();
    REQUIRE(accomplishedtasks.size() == 1);

};

TEST_CASE("List cleared upon selecting the choice") {
    TodoList tasks;
    tasks.add("Clean the house");
    tasks.add("Wipe the kitchen counter");
    tasks.add("Watch football game");

    tasks.clear();

    REQUIRE(tasks.empty() == true);
    REQUIRE(tasks.size() == 0);
    REQUIRE(tasks.all().empty() == true);
};


TEST_CASE("Creating a valid task") {
    TodoList tasks;
    REQUIRE(tasks.add("Clean the kitchen") == true);
    REQUIRE(tasks.size() == 1);

    vector<string> accomplishedtasks = tasks.all();
};

