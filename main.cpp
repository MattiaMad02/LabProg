
#include "Activity.h"
#include "TodoList.h"
int main() {
    Date NDate(29, 2, 2024);
    Time NTime(14, 30);
    NDate.print();
    NTime.print();
    Activity Att("Andare dalla nonna", Date(9, 6, 2024), Time(15, 40), false);
    Att.print();
    Att.doneActivity();
    Activity activity1("Vai in palestra", Date(10, 7, 2024), Time(9, 30), false);
    Activity activity2("Dottore", Date(11, 7, 2024), Time(14, 0), true); // Completato
    Activity activity3("Incontro con Samuele", Date(12, 7, 2024), Time(16, 15), false);
    TodoList todoList;
    todoList.addActivity(Att);
    todoList.addActivity(activity1);
    todoList.addActivity(activity2);
    todoList.addActivity(activity3);
    todoList.removeActivityCompleted();
    todoList.printList();
    todoList.NumberActivitiestoDo();
}