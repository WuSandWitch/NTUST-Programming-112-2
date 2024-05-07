#pragma once
#include "Document.h"

class File: public Document {
    private:
    std::string path;

    public:
    File(std::string content, std::string path): Document(content) {
        this->path = path;
    }
    std::string getPathname() const {
        return this->path;
    }
    void setPathname(std::string path) {
        this->path = path;
    }

    File& operator=(const File& file) {
        this->setText(file.getText());
        this->setPathname(file.getPathname());
        return *this;
    }
};