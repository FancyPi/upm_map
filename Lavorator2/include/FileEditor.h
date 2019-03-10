#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <string>
#include <fstream>

class FileEditor {
public:
    FileEditor(std::string _filename);
    virtual ~FileEditor();

    std::string file_name;



protected:

private:
    std::istream readFromFile;
    std::ostream writeFromFile;
};

#endif // FILEEDITOR_H
