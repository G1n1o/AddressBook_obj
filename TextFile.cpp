#include "TextFile.h"

string TextFile::getFileName() {
return FILE_NAME;
}

bool TextFile::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    return  (textFile.tellg() == 0) ? true : false;
}

