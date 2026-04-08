#include <string>

#include <vector>
#include <iostream>

#include "hello.hpp"

using namespace std;


bool TodoList::blankspace(const string &text) const {


    for (int i = 0; i < text.length(); i++) {
       if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
           return false;
       }
    }
    return true;
}

string TodoList::formatthetask(int index, const Tasks &task) const {


    string result = to_string(index+1);

    result += ", [";

    if (task.completed) {
        result += "X";
    } else {
        result += " ";
    }

    result += "]";
    result += task.description;
    return result;


}

bool TodoList::add(const string &description) {
    if (blankspace(description)) {
        return false;
    }


    Tasks task;
    task.description = description;
    task.completed = false;

    tasks.push_back(task);
    return true;

};

bool TodoList::complete(int tasknumber) {



    if (tasknumber <= 0 || tasknumber > tasks.size()) {
        return false;
    };


    if (tasks[tasknumber-1].completed) {
        return false;
    }


    tasks[tasknumber-1].completed = true;
    return true;

};

vector<std::string> TodoList::all() const {
    vector<std::string> result;

    for (int f = 0; f < tasks.size(); f++) {
        result.push_back(formatthetask(f, tasks[f]));
    }
    return result;

}

vector<std::string> TodoList::complete() const {
    vector<std::string> result;
    for (int x = 0; x < tasks.size(); x++) {
        if (tasks[x].completed) {
            result.push_back(formatthetask(x, tasks[x]));
        }
    }

    return result;
};

vector<std::string> TodoList::incomplete() const {
    vector<std::string> result;
    for (int y = 0; y < tasks.size(); y++) {
        if (!tasks[y].completed) {
            result.push_back(formatthetask(y, tasks[y]));
        }
    }
    return result;
};

void TodoList::clear() {
    tasks.clear();
};

int TodoList::size() const {
    return tasks.size();
};

bool TodoList::empty() const {
    return tasks.empty();
}

