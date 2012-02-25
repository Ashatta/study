#pragma once

class incorrectInput
{
    public:
        incorrectInput(const char * mess) :
            message(mess)
        {}
        ~incorrectInput() {}
        const char * what() const { return message; }
    private:
        const char * message;
};

void convertToPolish(std::istream &source, std::stringstream &dest);
