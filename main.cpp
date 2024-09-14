
#include "Activity.h"
#include "TodoList.h"
int main() {
    try {
        Date NDate(29, 2, 2024);  // Data valida (anno bisestile)
        Time NTime(14, 30);  // Ora valida
        NDate.print();
        NTime.print();
    } catch (const Date::DateException& e) {
        std::cerr << "Date error: " << e.what() << std::endl;
    } catch (const Time::TimeException& e) {
        std::cerr << "Time error: " << e.what() << std::endl;
    }

    try {
        Activity Att("Andare dalla nonna", Date(9, 6, 2024), Time(15, 40), false);
        Att.print();
        Att.doneActivity();
        Activity activity1("Vai in palestra", Date(10, 7, 2024), Time(9, 30), false);
        Activity activity2("Dottore", Date(11, 7, 2024), Time(14, 0), true);  // Completato
        Activity activity3("Incontro con Samuele", Date(12, 7, 2024), Time(16, 15), false);

        TodoList todoList("list1");
        todoList.addActivity(Att);
        todoList.addActivity(activity1);
        todoList.addActivity(activity2);
        todoList.addActivity(activity3);

        todoList.NumberActivities();

        std::list<Activity> completedActivities = todoList.getCompletedActivities();
        std::cout << "\nCompleted Activities:" << std::endl;
        for (const auto& activity : completedActivities) {
            activity.print();
        }
        todoList.NumberActivitiesDone();
        std::list<Activity> ActivitiesToDo=todoList.getActivitiesToDo();
        std::cout << "\nActivities to do:" << std::endl;
        for (const auto& activity : completedActivities) {
            activity.print();
        }
        todoList.NumberActivitiestoDo();

        Date searchDate(10, 7, 2024); // Ricerca per data
        Activity foundActivity = todoList.getActivityByDate(searchDate);
        foundActivity.print();

        std::string filename = "todo_list.txt";// Salvataggio su file
        todoList.savetoFile(filename);
        std::cout << "Todo list saved to " << filename << std::endl;

        TodoList loadedTodoList("listLoaded");// Caricamento da file
        loadedTodoList.loadFromFile(filename);
        std::cout << "Todo list loaded from " << filename << std::endl;

        std::cout << "Loaded Todo List:" << std::endl;
        loadedTodoList.addActivity(Att);
        loadedTodoList.addActivity(activity1);
        loadedTodoList.addActivity(activity2);
        loadedTodoList.printList();

    } catch (const Date::DateException& e) {
        std::cerr << "Date error: " << e.what() << std::endl;
    } catch (const Time::TimeException& e) {
        std::cerr << "Time error: " << e.what() << std::endl;
    } catch (const Activity::ActivityException& e) {
        std::cerr << "Activity error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
    }

    return 0;
}