#include <iostream>
#include <string_view>
#include <string>
#include <sstream>
#include <array>


#include "./complex.hpp"


void print_usage()
{
    static constexpr std::array usage = {
        "Usage:",
        "./complex \"[Complex1] [OP] [Complex2]\"",
        "   where OP is one of: +, -, *, /",
        "   and complex is in format RE+IMGj",
        "Example:",
        "   $ ./complex \"23+2j * -12+-3j\"",
        "   Complex{23 + 2j} * Complex{-12 + -3j} = Complex{-270 + -93j}"
    };

    for (auto line : usage)
    {
        std::cout << line << '\n';
    }
}


int main(int argc, char *argv[])
{
    --argc; ++argv; // skip progname

    if (argc == 1)
    {
        Complex a;
        Complex b;
        char op;

        std::istringstream iss{ *argv };
        iss >> a >> op >> b;

        if (iss)
        {
            switch (op)
            {
            case '+':
                std::cout << a << ' ' << op << ' ' << b << " = " << a + b << '\n';
                break;
            case '-':
                std::cout << a << ' ' << op << ' ' << b << " = " << a - b << '\n';
                break;
            case '*':
                std::cout << a << ' ' << op << ' ' << b << " = " << a * b << '\n';
                break;
            case '/':
                std::cout << a << ' ' << op << ' ' << b << " = " << a / b << '\n';
                break;

            default:
                std::cerr << "Invalid operation: " << op << '\n';
                print_usage();
                return 1;
            }
        }
        else
        {
            std::cerr << "Invalid expression: " << *argv << '\n';
            print_usage();
            return 1;
        }
    }
    else
    {
        std::cerr << "Invalid number of arguments\n";
        print_usage();
        return 1;
    }

    return 0;
}
