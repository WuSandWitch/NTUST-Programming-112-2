#pragma once
#include "Document.h"

class Email: public Document {
    private:
    std::string sender;
    std::string recipient;
    std::string title;

    public:
    Email(std::string content, std::string sender, std::string recipient, std::string title): Document(content) {
        this->sender    = sender;
        this->recipient = recipient;
        this->title     = title;
    }

    std::string getSender() const {
        return this->sender;
    }

    void setSender(std::string sender) {
        this->sender = sender;
    }

    std::string getRecipient() const {
        return this->recipient;
    }

    void setRecipient(std::string recipient) {
        this->recipient = recipient;
    }

    std::string getTitle() const {
        return this->title;
    }

    void setTitle(std::string title) {
        this->title = title;
    }

    Email& operator=(const Email& email) {
        this->setText(email.getText());
        this->sender    = email.sender;
        this->recipient = email.recipient;
        this->title     = email.title;
        return *this;
    }
};