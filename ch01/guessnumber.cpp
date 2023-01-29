#include <iostream>
#include <ctime> 
int main()
{
    srand(time(0));
    int n{100};
    int l{0};
    int r{n};
    int ans{rand()%n};
    int guess = l-1;
    while (guess != ans)
    {
        std::cout << "Please enter an integer between " << l << " and " << r << " (excluding endpoints)." << std::endl;
        std::cin >> guess;
        if (guess > ans && guess < r)
        {
            std::cout << "That\'s bigger than the answer." << std::endl;
            r = guess;
        }
        if (guess < ans && guess > l)
        {
            std::cout << "That\'s smaller than the answer." << std::endl;
            l = guess;
        }
    }
    std::cout << "Bingo! You got the answer!" << std::endl;
}