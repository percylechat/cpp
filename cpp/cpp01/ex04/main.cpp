// Make a program called replace that takes a filename and two strings, let’s call them
// s1 and s2, that are NOT empty.
// It will open the file, and write its contents to FILENAME.replace, after replacing
// every occurrence of s1 with s2.
// All the member functions of the class std::string are allowed, except replace. Use
// them wisely!
// Of course, you will handle errors as best you can. Do not use the C file manipulation
// functions, because that would be cheating, and cheating’s bad, m’kay?
// You will turn in some test files to show your program works.

#include <iostream>
#include <fstream>
#include <istream>

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream file;
    int i;
    std::string content;
    std::string res;

    if (s1.empty() || s2.empty())
    {
        std::cout << "strings can't be empty!" << std::endl;
        return ;
    }
    file.open(&filename[0]);
    while (getline(file, content))
    {
        i = content.find(s1);
        if (i > 0)
        {
            res.append(content.substr(0, i ));
            res.append(s2);
            if (i + s1.size() != content.size())
                res.append(content.substr(i + s1.size(), content.size() - i + s1.size()));
        }
        else if (i == 0)
        {
            res.append(s2);
            if ( i + s1.size() != content.size())
                res.append(content.substr(i + s1.size(), content.size() - i + s1.size()));
        }
        else
            res.append(content);
        res.append("\n");
    }
    file.close();
    std::string filename1 = filename;
    filename1 = filename1.append(".replace");
    std:: ofstream file1;
    file1.open(&filename1[0]);
    file1 << res;
    file1.close();
}

int main()
{
    std::string content;
    // std::string file1 = "test1.txt";
    // std::string s1 = "hibou";
    // std::string s2 = "chaton";
    std::string file1 = "test2";
    std::string s1 = "(";
    std::string s2 = ";";
    replace(file1, s1, s2);
    return 0;
}