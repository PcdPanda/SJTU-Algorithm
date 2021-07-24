#include <iostream>
#include "dlist.h"

using namespace std;

class Client {
public:
    string name = "";
    string status = "";
    int duration = 0;
};

int main() {
    int numEvents;
    int curEvents = 0;
    int tick = 0;
    int busy = 0;
    int tStamp;

    Dlist<Client> platinum;
    Dlist<Client> gold;
    Dlist<Client> silver;
    Dlist<Client> regular;

    cin >> numEvents;
    cin >> tStamp;

    while (curEvents < numEvents or busy >= 0) {
        cout << "Starting tick #" << tick << endl;
        while (curEvents < numEvents and tStamp == tick) {
            auto curCall = new Client;
            cin >> curCall->name >> curCall->status >> curCall->duration;
            cout << "Call from " << curCall->name << " a " << curCall->status << " member" << endl;
            if (curCall->status == "platinum")
                platinum.insertBack(curCall);
            else if (curCall->status == "gold")
                gold.insertBack(curCall);
            else if (curCall->status == "silver")
                silver.insertBack(curCall);
            else
                regular.insertBack(curCall);
            cin >> tStamp;
            curEvents++;
        }

        if (busy <= 0) {
            Client *ans = nullptr;
            if (!platinum.isEmpty())
                ans = platinum.removeFront();
            else if (!gold.isEmpty())
                ans = gold.removeFront();
            else if (!silver.isEmpty())
                ans = silver.removeFront();
            else if (!regular.isEmpty())
                ans = regular.removeFront();
            if (ans != nullptr) {
                cout << "Answering call from " << ans->name << endl;
                busy = ans->duration;
                delete ans;
            }
        }
        tick++;
        busy--;
    }
}
