#include <iostream>
#include <dirent.h>
#include <sys/types.h>

using namespace std;



void list_dir(const char *path) {
   struct dirent *entry;
   DIR *dir = opendir(path);

   if (dir == NULL) {
      return;
   }

   string current_entries[250];

   while ((entry = readdir(dir)) != NULL) {
     cout << entry->d_ino << " --- " << entry->d_name << endl;
   }
   closedir(dir);
}

int main() {
   list_dir("./");
}
