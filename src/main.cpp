#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

bool isNumeric(const std::string& str) {
    if(str[0] == '-') {
        std::string str2 = "";

        for(std::string::size_type i = 1; i < str.length(); i++) {
            str2 += str[i];
        }

        str2 += "0";
        return std::all_of(str2.begin(), str2.end(), ::isdigit);
    } else {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }
}

// safe user input
std::string input() {
    std::string inp_str;
    char ch;
    while (std::cin.get(ch) && ch != '\n') {
        inp_str += ch;
    }
    return inp_str;
}

std::string prompt(std::string text) {
    // render the prompt text
    std::cout << text << std::endl;
    // displays the input text
    std::cout << "(name) > " << std::flush;

    std::string s;
    s = input();

    // gets user input
    return s;
}

// prompt a number
int prompt_int(std::string text) {
    // render the prompt text
    std::cout << text << std::endl;
    // displays the input text
    std::cout << "(number) > " << std::flush;

    // gets user input
    int i;
    std::string s = input();

    if(isNumeric(s)) {
        i = stoi(s);
    } else {
        prompt_int(text);
    }

    return i;
}

char choice3(std::string text, std::string _choice1, std::string _choice2, std::string _choice3) {
    // renders the prompt text with the choices
    std::cout << text << std::endl;
    std::cout << "   1) " << _choice1 << ", 2) " << _choice2 << ", 3) " << _choice3 << std::endl;

    // user input
    std::string picked;

    std::cout << " > " << std::flush;
    picked = input();

    // if input is within the choices then exit loop
    if(picked[0] == '1' || picked[0] == '2' || picked[0] == '3') {
        return picked[0];
    } else {
        choice3(text, _choice1, _choice2, _choice3);
    }

    return '0';
}

void print_list(std::vector<std::string> list)
{
    std::cout << "Todo List:" << std::endl;
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << "    " << i << ": " << list[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> todo_list;
    int pos;
    while (true)
    {
        print_list(todo_list);
        char choice = choice3("What would you like to do to your Todo list?", "Add an item", "Change an item", "Remove an Item");
        switch (choice)
        {
            case '1':
                todo_list.push_back(prompt("What is your item's name?"));
                break;
            
            case '2':
                pos = prompt_int("What item would you like to change?");
                if(pos >= int(todo_list.size()))
                {
                    std::cout << "That item does not exist" << std::endl;
                }
                else
                {
                    todo_list[pos] = prompt("What would you like to change it to?");
                }
                break;

            case '3':
                pos = prompt_int("What item would you like to delete?");
                if(pos >= int(todo_list.size()))
                {
                    std::cout << "That item does not exist" << std::endl;
                }
                else
                {
                    todo_list.erase(todo_list.begin()+pos, todo_list.begin()+pos+1);
                }
                break;
        }
    }


    return 0;
}
