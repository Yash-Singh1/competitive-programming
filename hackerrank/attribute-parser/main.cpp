#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
using namespace std;

struct Element {
    map<string, string> attributes;
    map<string, Element> children;
};

int main() {
    Element root;
    vector<string> reading;
    short n, q;
    cin >> n >> q;
    for (short i {0}; i < n; ++i) {
        char dump;
        string name;
        cin >> dump >> dump;
        if (dump == '/') {
            getline(cin, name);
            reading.pop_back();
        } else {
            while (dump != ' ' && dump != '>') {
                name += dump;
                scanf("%c", &dump);
            }
            if (dump == '>') {
                name += dump;
            }
            bool popped {name[name.size() - 1] == '>'};
            if (popped) name.pop_back();
            Element parsed;
            if (!popped) {
                cin >> dump;
                string nextAttr;
                while (dump != '>') {
                    if (dump == '=') {
                        if (nextAttr[nextAttr.size() - 1] == ' ') nextAttr.pop_back();
                        string realVal;
                        cin >> dump;
                        scanf("%c", &dump);
                        while (dump != '"') {
                            realVal += dump;
                            scanf("%c", &dump);
                        }
                        parsed.attributes[nextAttr] = realVal;
                        nextAttr.clear();
                    }
                    else {
                        nextAttr += dump;
                    }
                    if (nextAttr.length() == 0) {
                        cin >> dump;
                    } else {
                        scanf("%c", &dump);
                    }
                }
            }
            Element* insertion {&root};
            for (auto el: reading) {
                insertion = &((*insertion).children[el]);
            }
            insertion->children[name] = parsed;
            reading.push_back(name);
        }
    }
    for (short i; i < q; ++i) {
        string input;
        getline(cin, input);
        if (input.length() == 0) {
            input.clear();
            getline(cin, input);
        }
        stringstream line {input};
        char next;
        line >> next;
        string currentEl;
        bool notFound {false};
        Element *searchPoint {&root};
        while (next != '~') {
            if (next == '.') {
                if (searchPoint->children.find(currentEl) == searchPoint->children.end()) {
                    notFound = true;
                    break;
                }
                searchPoint = &(searchPoint->children[currentEl]);
                currentEl.clear();
            } else {
                currentEl += next;
            }
            line >> next;
            if (line.rdbuf()->in_avail() == 0) {
                notFound = true;
                break;
            }
        }
        if (searchPoint->children.find(currentEl) == searchPoint->children.end()) {
            notFound = true;
        } else {
            searchPoint = &(searchPoint->children[currentEl]);
        }
        if (notFound) {
            cout << "Not Found!" << endl;
            continue;
        }
        string attr;
        getline(line, attr);
        if (searchPoint->attributes.find(attr) == searchPoint->attributes.end()) {
            cout << "Not Found!" << endl;
        } else {
            cout << searchPoint->attributes[attr] << endl;
        }
    }
    return 0;
}
