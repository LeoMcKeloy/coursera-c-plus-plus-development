#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <map>
using namespace std;

TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_tasks_.at(person);
    }
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++person_tasks_[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;

        TasksInfo& tasks = person_tasks_[person];

        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status)) {
            updated_tasks[Next(status)] = min(task_count, tasks[status]);
            task_count -= updated_tasks[Next(status)];
        }

        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status)) {
            untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
        }

        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

        RemoveZeros(updated_tasks);
        RemoveZeros(untouched_tasks);

        return {updated_tasks, untouched_tasks};
    }

private:
    map<string, TasksInfo> person_tasks_;

    void RemoveZeros(TasksInfo& tasks_info) {
        vector<TaskStatus> statuses_to_remove;
        for (const auto& task_item : tasks_info) {
            if (task_item.second == 0) {
                statuses_to_remove.push_back(task_item.first);
            }
        }
        for (const TaskStatus status : statuses_to_remove) {
            tasks_info.erase(status);
        }
    }

};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}