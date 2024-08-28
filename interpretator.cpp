#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <optional>
#include <vector>

std::string readFile(const std::string& filePath) {
    std::ifstream fileStream(filePath); // Открываем файл
    if (!fileStream.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filePath);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf(); // Читаем содержимое файла в строковый поток

    return buffer.str(); // Возвращаем содержимое файла в виде строки
}

enum class TokenType
{
    Ident,
    StringLit,
    OpenPara,
    ClosePara,
}

struct Token
{
    TokenType type;
    std::optional<std::string> value;
}

std::vector<Token> lexing(const std::string& code)
{
    std::string buffer;
    std::vector<Token> tokens;

    for(size_t i = 0; i < code.size(); i++)
    {
        char symbol = code.at(i);

        if(symbol == "(") tokens.push_back(Token{.type = TokenType::OpenPara});
        else if(symbol == "(") tokens.push_back(Token{.type = TokenType::ClosePara});

        else if(symbol == '"')
        {
            i++;

            while(i < code.size() && code.at(i) != '"')
            {
                buffer.push_back(code.at(i);
                i++;
            }

            if(i > code.size()) 
            {
                std::cerr << "Ожидалось \"\n";
            }
        }
    }
}

