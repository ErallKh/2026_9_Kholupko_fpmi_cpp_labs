#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <ctime>
#include <iomanip>

std::string getCurrentTime() 
{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(localTime, "%d.%m.%Y %H:%M:%S");
    return oss.str();
}

void logAction(std::ofstream& logFile, const std::string& message)
{
    logFile << getCurrentTime() << " | " << message << "\n";
}

bool StringChecker(const std::string& a, const std::string& b)
{
    std::map<char, int> arrSv;
    for (const char& c : a)
    {
        if (std::isalpha(c))
        {
            char lowL = tolower(c);
            arrSv[lowL]++; 
        }
    }

    for (const char& c : b)
    {
        if (std::isalpha(c))
        {
            char lowL = tolower(c);
            arrSv[lowL]--;
        }
    }
    for (const auto& pair : arrSv)
    {
        if (pair.second != 0)
            return false;
    }
    return true;
}

int main()
{
    std::ofstream logFile("log.txt");
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log.txt\n";
        return 1;
    }
    logAction(logFile, "prog start");

    logAction(logFile, "opening file \"input.txt\"");
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        logAction(logFile, "ERROR: failed to open \"input.txt\"");
        return 1;
    }
    logAction(logFile, "file \"input.txt\" open");

    logAction(logFile, "opening file \"output.txt\"");
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        logAction(logFile, "not open \"output.txt\"");
        return 1;
    }
    logAction(logFile, "file \"output.txt\" opened");

    logAction(logFile, "reading lines \"input.txt\"");

    std::string line1, line2;
    
    while (std::getline(inputFile, line1)) {
        logAction(logFile, "line 1: \"" + line1 + "\"");
        
        if (std::getline(inputFile, line2)) {
            logAction(logFile, "line 2: \"" + line2 + "\"");
            logAction(logFile, "checking anagram");
            
            bool isAnagram = StringChecker(line1, line2);
            
            std::string result = isAnagram ? "it is anagrama" : "it isn`t anagrama";
            
            logAction(logFile, "result: " + result);
            logAction(logFile, "writing res \"output.txt\"");
            
            outputFile << result << "\n";
        } else {
            logAction(logFile, "skip");
            outputFile << "no pair\n";
        }
    }

    logAction(logFile, "prog close with code 0");

    inputFile.close();
    outputFile.close();
    logFile.close();

    std::cout << "Finish" << std::endl;
    return 0;
}