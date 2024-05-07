#pragma once
#include <string>

class Document {
    private:
    std::string content;

    public:
    Document(std::string content) {
        this->content = content;
    }
    std::string getText() const {
        return this->content;
    }
    void setText(std::string content) {
        this->content = content;
    }

    Document& operator=(const Document& document) {
        this->content = document.content;
        return *this;
    }
};
