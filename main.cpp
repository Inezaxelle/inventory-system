#include <iostream>
#include <ctime>
#include <regex>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// structure to hold information
struct Item
{
    string item_id;
    string item_name;
    int item_quantity;
    string item_registration_date;
};

// Function to see if the date format is valid
bool isValid(string &date)
{
    regex date_pattern(R"(\d{4}-\d{2}-\d{2})");
    return regex_match(date, date_pattern);
}

// Function to add item to the inventory
void addItem(string &item_id, string &item_name, int intem_quantity, string &item_registration_date)
{

    if (!isValid(item_registration_date))
    {
        cout << "Invalid date entered! Enter date in form YYYY-MM-DD" << endl;
        return;
    }

    // To append item to the inventory.csv
    ofstream file("inventory.csv", ios::app);
    if (file.is_open())
    {
        file << item_id << "," << item_name << "," << intem_quantity << "," << item_registration_date << endl;
        file.close();
        cout << "Item added to file successfully" << endl;
    }
    else
    {
        cerr << "Unable to open file" << endl;
    }
}

// Function to read from the inventory
vector<Item> readInventory()
{
    vector<Item> inventory;
    ifstream file("inventory.csv");
    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            stringstream ss(line);
            Item item;
            string quantity;

            getline(ss, item.item_id, ',');
            getline(ss, item.item_name, ',');
            getline(ss, quantity, ',');
            getline(ss, item.item_registration_date, ',');
            item.item_quantity = stoi(quantity);
            inventory.push_back(item);
        }
        file.close();
    }
    else
    {
        cerr << "Can not open inventory.csv";
    }
    return inventory;
}

// Function to list all items in alphabetical order
void listItems()
{
    vector<Item> inventory = readInventory();
    sort(inventory.begin(), inventory.end(), [](const Item &a, const Item &b)
         { return a.item_name < b.item_name; });

    for (size_t i = 0; i < inventory.size(); ++i)
    {
        const Item &item = inventory[i];
        cout << "Item Id:" << item.item_id << " Item Name:" << item.item_name << " Item Quantity:" << item.item_quantity << " Item Reg Date:" << item.item_registration_date << endl;
    }
}

// Function to convert commands to lowercase so they can become case-insensitive when being executed
string toLower(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to display command syntaxes
void commandSyntax()
{
    cout << "------------------------------" << endl;
    cout << "*      Command Syntaxes      *" << endl;
    cout << "------------------------------" << endl;
    cout << "itemadd\n<item_id> <item_name> <item_quantity> <registration_date>" << endl;
    cout << "listitem" << endl;
}

int main()
{
    string command;
    while (true)
    {
        cout << "Enter a command: " << endl;
        cout << "Console>";
        getline(cin, command);
        command = toLower(command);
        {
            if (command == "additem")
            {
                string item_id, item_name, item_registration_date;
                int item_quantity;
                cin >> item_id >> item_name >> item_quantity >> item_registration_date;
                addItem(item_id, item_name, item_quantity, item_registration_date);
            }
            else if (command == "listitem")
            {
                listItems();
            }
            else if (command == "exit")
            {
                break;
            }
            else if (command == "help")
            {
                commandSyntax();
            }
            else
            {
                cout << "Invalid Command" << endl;
            }
        }
    }

    return 0;
}