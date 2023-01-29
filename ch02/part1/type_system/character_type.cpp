/*
仿照上一章的“猜数游戏”，编写一个“猜字母”的游戏：
程序指定一个大写字母，允许用户通过多次输入来猜测是哪一个字母，直至猜对为止。猜错的提示与“猜数游戏”相同，输出提示是猜“大”了还是“小”了。
（提示： char 型变量仍然可以通过大于、小于号进行比较。）
*/

#include <iostream>
int main()
{
    srand(time(0));
    char ans;
    ans = 'A' + (rand() % 26);
    char guess{'a'};
    std::cout << "Please enter a capitalized letter." << std::endl;
    while (guess != ans)
    {
        std::cin >> guess;
        if (guess >= 65 && guess <= 90)
        {
            if (guess > ans)
            {
                std::cout << "That\'s bigger than the answer. Try again?" << std::endl;
            }
            if (guess < ans)
            {
                std::cout << "That\'s smaller than the answer. Try again?" << std::endl;
            }
        }
        else
        {
            std::cout << "Please enter a capital letter." << std::endl;
        }
    }
    std::cout << "Bingo! You got the answer!" << std::endl;
}