#pragma once
#include <string>

class Document {
private:
	std::string text;
public:
	Document(std::string text) {
		this->text = text;
	}

	std::string getText() const { return text; }
	void setText(std::string text) { this->text = text; }
	
	void operator=(Document& document) {
		setText(document.getText());
	}
};