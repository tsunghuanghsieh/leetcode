#include <map>
#include <string>

using namespace std;

class Logger {
public:
    Logger(): _className(__func__) {

    }

    // For main.cpp setup check
    string ClassName() {
        return _className;
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (messages.find(message) == messages.end() || messages[message] + 10 <= timestamp) {
            messages[message] = timestamp;
            return true;
        }
        return false;
    }
private:
    const string _className; // For main.cpp setup check
    map<string, int> messages;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */