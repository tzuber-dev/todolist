#include <string>

#include <vector>

#include <iostream>

using namespace std;

class TodoList {
private:
    struct Tasks {
        string description;
        bool completed;

    };


    vector<Tasks> tasks;


    bool blankspace(const string& text) const;
    string formatthetask(int index, const Tasks& task) const;

public:
    bool add(const string& description);


    bool complete(int tasknumber);


    vector<std::string>all() const;
    vector<std::string> complete() const;
    vector<std::string> incomplete() const;


    void clear();

    int size() const;
    bool empty() const;

};
