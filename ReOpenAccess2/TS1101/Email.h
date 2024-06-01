#include "Document.h"

class  Email : public Document {
private:
	std::string sender;
	std::string  recipient;
	std::string title;
public:
	Email(std::string text, std::string sender, std::string recipient, std::string title) : Document(text) {
		this->sender = sender;
		this->recipient = recipient;
		this->title = title;
	}
	void operator=(Email& email) {
		setText(email.getText());
		this->sender = email.sender;
		this->recipient = email.recipient;
		this->title = email.title;
	}

	std::string getSender() { return sender; }
	void setSender(std::string sender) { this->sender = sender; }
	std::string getRecipient() { return recipient; }
	void setRecipient(std::string recipient) { this->recipient = recipient; }
	std::string getTitle() { return title; }
	void setTitle(std::string title) { this->title = title; }
};