#include <iostream>

#include "src/hello.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <limits>



using namespace std;


void wipeincorrectuserinput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

int mainmenuselection() {
    int userselection;


    cout<<"1. Create Task"<<"\n";
    cout<<"2. Fill task as done"<<"\n";
    cout<<"3. Showcase your full tasks"<<"\n";
    cout<<"4. Showcase accomplished tasks"<<"\n";
    cout<<"5. Showcase not done tasks"<<"\n";
    cout<<"6. Clear your tasks"<<"\n";
    cout<<"7. Exit (thank you for using our ToDo list!)"<<"\n";

    cout<<"------------------------------------------------------- "<<endl;
cout<<"Type in your selection: ";
    cin>>userselection;

    if (cin.fail()) {
        wipeincorrectuserinput();
        return -1;
    };

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return userselection;

};

int locatetaskid() {
    int taskid;
    cin>>taskid;

    if (cin.fail()) {
        wipeincorrectuserinput();
        return -1;
    };

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return taskid;



};

void showcasealltasks(const vector<string>& tasks, const string& titlelabel) {
cout<<titlelabel<<endl;

    if (tasks.empty()) {
        cout<<"No tasks located!"<<endl;
        return;
    };

    for (const string& task : tasks) {
        cout<<task<<endl;
    }
}


int main() {
    TodoList tasks;
    int select = 0;

    cout<<"Welcome to the ToDo list!"<<endl;
    cout<<" ";

    while (select != 7) {
        select = mainmenuselection();

        if (select == 1) {
            string todowork;
            cout<<"Enter the tasks: "<<endl;
            getline(cin, todowork);


            if (tasks.add(todowork)) {
                cout<<"Task added!"<<endl;
            }else {
                cout<<"Task is not valid to be entered. Please retry."<<endl;
            }
        } else if (select == 2) {
            if (tasks.empty()) {
                cout<<"No tasks discovered!"<<endl;
            }else {
                showcasealltasks(tasks.all(), "Entire tasks");
                cout<<"--------------------------";
                cout<<"Enter to do task ID: ";

                int taskid = locatetaskid();

                if (tasks.complete(taskid)) {
                    cout<<"Task done!"<<endl;
                }else {
                    cout<<"Task ID is not valid to be entered. Please retry."<<endl;
                }

            }
        }else if (select == 3) {
            showcasealltasks(tasks.all(), "Full Task list");
        }else if (select == 4) {
            showcasealltasks(tasks.complete(), "Accomplished Task list");
        }else if (select == 5) {
            showcasealltasks(tasks.incomplete(), "Not Completed Task list");
        }else if (select == 6) {
            tasks.clear();
            cout<<"Tasks were wiped!"<<endl;
        }else if (select == 7) {
            cout<<"Thanks for using this program. Hope to see you next time! ";
        }else {
            cout<<"Input out of range, please try again."<<endl;
        }
    }
    return 0;
}



