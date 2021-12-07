#include <iostream>

char change_letter(char t)
{
    char c;

    if (t < 97 || t > 122)
        return (t);
    else
        c = t - 32;
    return (c);
}

int main(int argc, char *argv[])
{
    char c;
    int i;
    int j;

    i = 1;
    j = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (argv[i])
    {
        while (argv[i][j])
        {
            c = change_letter(argv[i][j]);
            argv[i][j] = c;
            j++;
        }
        j = 0;
        std::cout << argv[i];
        i++;
    }
    std::cout << "\n";
    return (0);
}