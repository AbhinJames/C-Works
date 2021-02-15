using System;

//Namespace
namespace NumberGuesser
{
    //Main Class
    class Program
    {
        //Entry point method
        static void Main(string[] args)
        {
            GetAppInfo();

            GreetUser();

            while (true)
            {

                // Init correct number
                //int correctNumber = 7;

                //Create Random numbers
                Random random = new Random();
                int correctNumber = random.Next(1, 10);


                //Init guess number
                int guess = 0;

                //Ask user until a number in range
                Console.WriteLine("Guess a number between 1 and 10!:");

                //While guess is not correct
                while (guess != correctNumber)
                {
                    string userGuess = Console.ReadLine();

                    //mke sure its a number
                    if (!int.TryParse(userGuess, out guess))
                    {
                        PrintColorMessage(ConsoleColor.Red,"Please enter an actual number!:");
                        continue;
                    }

                    //Cast to int and put in guess
                    guess = Int32.Parse(userGuess);

                    //Match guess to 7
                    if (guess != correctNumber)
                    {
                        PrintColorMessage(ConsoleColor.Red, "Wrong Guess!! Try Again!!");

                    }
                }

                PrintColorMessage(ConsoleColor.Blue, "Correct Guess!!");


                Console.WriteLine("Do you want to play again [Y] or [N]?: ");
                string answer = Console.ReadLine().ToUpper();

                if (answer == "Y")
                {
                    continue;
                }
                else if (answer == "N")
                {
                    Console.WriteLine("Thanks for playing!");
                    return;
                }

                return;
            }

        }

        static void GreetUser()
        {
            //ASk users name
            Console.WriteLine("What is your name?");

            //Get user input
            string input = Console.ReadLine();

            //Display name
            Console.WriteLine("Hello {0}! Lets play a game!!", input);
        }

        static void GetAppInfo()
        {
            string appName = "Number Guesser";
            string appVersion = "1.0.0";
            string appAuthor = "Abhin";

            //Change colour of text
            Console.ForegroundColor = ConsoleColor.Green;

            //Write out app info
            Console.WriteLine("{0} : Version {1} by {2}", appName, appVersion, appAuthor);

            //Reset Colour
            Console.ResetColor();

        }

        static void PrintColorMessage(ConsoleColor color,string message)
        {
            //Change colour of text
            Console.ForegroundColor = color;

            //Write out
            Console.WriteLine(message);

            //Reset Colour
            Console.ResetColor();
        }
    }
}
