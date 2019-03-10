#include "FileEditor.h"
#include <iostream>
#include <fstream>
using namespace std;

FileEditor::FileEditor(string _filename) {
    file_name= _filename;

}

FileEditor::~FileEditor() {
    //dtor
}
