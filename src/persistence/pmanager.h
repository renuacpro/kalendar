#ifndef PMANAGER_H
#define PMANAGER_H

#include <sqlite3.h> /* Version: 3.9.2 */
#include <stdio.h>
#include <list>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <fstream>
#include "../model/event.h"
#include "../model/category.h"

#define FOLDER_NAME "kalendar"
#define DATABASE_NAME "events.sql"

using namespace std;

class PManager
{
private:
    sqlite3 *db;
    string db_path;
public:
    PManager();
    ~PManager();
    bool add_event (Event *e);
    bool remove_event(Event *e);
    bool remove_all();
    list<Event*> get_events_of_month(int month, int year);
    bool add_category (Category *c);
    bool remove_category(Category *c);
    list<Category*> get_categories();
};

#endif // PMANAGER_H