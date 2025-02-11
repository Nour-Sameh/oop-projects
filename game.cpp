#include <bits/stdc++.h>
using namespace std;

string getComputerChoice()
{
    string choices[] = {"Rock", "Paper", "Scissor"};
    return choices[rand() % 3];
}
string determineWinner(const string &userChoice, const string &computerChoice)
{
    if (userChoice == computerChoice)
    {
        return "It's a tie!";
    }
    else if ((userChoice == "Rock" && computerChoice == "Scissor") ||
             (userChoice == "Paper" && computerChoice == "Rock") ||
             (userChoice == "Scissor" && computerChoice == "Paper"))
    {
        return "You win!";
    }
    else
    {
        return "Computer wins!";
    }
}

int main()
{
    srand(time(0));
    string userChoice;
    string computerChoice;
    cout << "Welcome to Rock, Paper, Scissor Game!\n";
    cout << "Enter your choice (Rock, Paper, Scissor): ";
    cin >> userChoice;
    if (userChoice != "Rock" && userChoice != "Paper" && userChoice != "Scissor")
    {
        cout << "Invalid choice. Please enter Rock, Paper, or Scissor.";
        return 1;
    }
    computerChoice = getComputerChoice();
    cout << "Computer's choice: " << computerChoice << "\n";
    string result = determineWinner(userChoice, computerChoice);
    cout << result << "\n";
    return 0;
}
