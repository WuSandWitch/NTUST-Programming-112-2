#include "Document.h"

class File : public Document {
private:
	std::string pathname;

public:
	File(std::string text, std::string pathname) : Document(text) {
		setPathname(pathname);
	}
	std::string getPathname() { return pathname; }
	void setPathname(std::string pathname) { this->pathname = pathname; }
};