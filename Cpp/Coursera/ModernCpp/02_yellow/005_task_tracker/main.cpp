#include <iostream>
#include <map>

using namespace std;

#ifdef ONLY_HOME
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
#endif

class TeamTasks
{
public:
    // Получить статистику по статусам задач конкретного разработчика
    [[nodiscard]] const TasksInfo &GetPersonTasksInfo(
            const string &person) const
    {
        return data.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person) { ++data[person][TaskStatus::NEW]; }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string &person, int task_count)
    {
        TasksInfo updated = {};
        TasksInfo no_updated = {};

        if (data.find(person) == data.end()) {
            return { updated, updated };
        }

        TasksInfo work = data[person];

        int step{};

        step = min(task_count, work[TaskStatus::NEW]);

        work[TaskStatus::NEW] -= step;
        if (work[TaskStatus::NEW] > 0) {
            no_updated[TaskStatus::NEW] = work[TaskStatus::NEW];
        }
        if (step > 0) {
            updated[TaskStatus::IN_PROGRESS] = step;
            data[person][TaskStatus::NEW] -= step;
            data[person][TaskStatus::IN_PROGRESS] += step;
            task_count -= step;
            if (data[person][TaskStatus::NEW] == 0) {
                data[person].erase(TaskStatus::NEW);
            }
        }

        step = min(task_count, work[TaskStatus::IN_PROGRESS]);

        work[TaskStatus::IN_PROGRESS] -= step;
        if (work[TaskStatus::IN_PROGRESS] > 0) {
            no_updated[TaskStatus::IN_PROGRESS] = work[TaskStatus::IN_PROGRESS];
        }
        if (step > 0) {
            updated[TaskStatus::TESTING] = step;
            data[person][TaskStatus::IN_PROGRESS] -= step;
            data[person][TaskStatus::TESTING] += step;
            task_count -= step;

            if (data[person][TaskStatus::IN_PROGRESS] == 0) {
                data[person].erase(TaskStatus::IN_PROGRESS);
            }
        }

        step = min(task_count, work[TaskStatus::TESTING]);

        work[TaskStatus::TESTING] -= step;
        if (work[TaskStatus::TESTING] > 0) {
            no_updated[TaskStatus::TESTING] = work[TaskStatus::TESTING];
        }
        if (step > 0) {
            updated[TaskStatus::DONE] = step;

            data[person][TaskStatus::TESTING] -= step;
            data[person][TaskStatus::DONE] += step;

            if (data[person][TaskStatus::TESTING] == 0) {
                data[person].erase(TaskStatus::TESTING);
            }
        }

        return tuple<TasksInfo, TasksInfo>(updated, no_updated);
    }

private:
    map<string, TasksInfo> data;
};

#ifdef ONLY_HOME
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info)
{
    cout << tasks_info[TaskStatus::NEW] << " new tasks"
         << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
         << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
         << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
#endif
