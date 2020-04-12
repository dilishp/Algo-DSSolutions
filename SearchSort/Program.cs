using System;
class Car
{
    static void Main(string[] args)
    {

        bool showMenu = true;
        while (showMenu)
        {
            showMenu = MainMenu();
        }
    }
    static bool key_is_in_ignition = false;
    static bool car_is_started = false;
    static bool seatbelt_is_fastened = false;
    static char gear = 'P';
    static bool wipers_are_on = false;
    static bool lights_are_on = false;
    static bool hibeams_are_on = false;
    static bool radio_is_on = false;
    static bool hazzard_is_on = false;
    static char signal_on = 'X';
    static int temperature = 0;
    static int speed = 0;
    const int MAX_SPEED = 55;
    const int ADD_SPEED = 5;
    const int DECELERATE = -5;
    private static double freq = 87.3;
    private static bool MainMenu()
    {
       

        //XXXXXXXXXXXXXXXXXX M E N U XXXXXXXXXXXXXXXXXXXXXXXX


        Console.Clear();
        Console.WriteLine("Choose an option:");
        Console.WriteLine("(1) Start the car :");
        Console.WriteLine("(2) Key in ignition:");
        Console.WriteLine("(3) Fasten seatbelt:");
        Console.WriteLine("(4) Stop the car");
        Console.WriteLine("(5) Exit");
        Console.WriteLine("\n\n Select an option ");

        switch (Console.ReadLine())

        {

            case "1":
                {
                    if (key_is_in_ignition)
                    {

                        Console.Clear();
                        Console.WriteLine("Choose an option:");
                        Console.WriteLine("(1) Change Gears :");
                        Console.WriteLine("(2) Step on Gas:");
                        Console.WriteLine("(3) Step on Break:");
                        Console.WriteLine("(4) Turn on / off the lights");
                        Console.WriteLine("(5) Turn on / off the signal");
                        Console.WriteLine("(6) Turn on / off the Hazzard light");
                        Console.WriteLine("(7) Turn on / off the Radio");
                        Console.WriteLine("(8) Turn on / off the Wipers");
                        Console.WriteLine("(9) Adjust the Temperature");
                        Console.WriteLine("(10) return to main menu");
                        Console.WriteLine("\n\n Select an option ");
                        string selection = Console.ReadLine();
                        switch (selection)
                        {
                            case "1":
                                Console.WriteLine("Please Enter the Gear(P - Park,D - Drive,R - Reverse,N - Neutral");
                                gear = char.Parse(Console.ReadLine().ToUpper());
                                break;
                            case "2":
                                if (gear == 'D' || gear == 'R')
                                {
                                    speed += ADD_SPEED;
                                    if (speed >= MAX_SPEED)
                                        speed = MAX_SPEED;
                                }
                                break;
                            case "3":
                                if (gear == 'D' || gear == 'R')
                                {
                                    speed += DECELERATE;
                                    if (speed < 0)
                                        speed = 0;
                                }
                                break;
                            case "4":
                                Console.WriteLine("Do you want to turn on Lights(Y/N)");
                                var lightState = char.Parse(Console.ReadLine().ToUpper());
                                lights_are_on = lightState == 'Y' ? true : false;
                                Console.WriteLine("Are you On HighBeams(Y/N)");
                                var beam = char.Parse(Console.ReadLine().ToUpper());
                                hibeams_are_on = beam == 'Y' ? true : false;
                                break;
                            case "5":
                                Console.WriteLine("Do you want to turn on Signal(Y/N)");
                                signal_on = char.Parse(Console.ReadLine().ToUpper());
                                break;
                            case "6":
                                Console.WriteLine("Do you want to turn on Hazard Lights(Y/N)");
                                var hazzardState = char.Parse(Console.ReadLine().ToUpper());
                                hazzard_is_on = hazzardState == 'Y' ? true : false;
                                break;
                            case "7":
                                Console.WriteLine("Do you want to turn on  Radio(Y/N)");
                                var radio = char.Parse(Console.ReadLine().ToUpper());
                                radio_is_on = radio == 'Y' ? true : false;
                                Console.WriteLine("Radio Station Frequency : {0}",freq);
                                Console.WriteLine("Do you want to Increase Freq(+/-)");
                                ConsoleKeyInfo choice = Console.ReadKey();
                                if (choice.Key == ConsoleKey.Add)
                                {
                                    freq += 3;
                                    if (freq >= 107.3)
                                        freq = 87.3;
                                }
                                else if (choice.Key == ConsoleKey.Subtract)
                                {
                                    freq -= 3;
                                    if (freq < 87.3)
                                        freq = 87.3;
                                }
                                break;
                            case "8":
                                Console.WriteLine("Do you want to turn on  Wiper(Y/N)");
                                var wiper = char.Parse(Console.ReadLine().ToUpper());
                                wipers_are_on = wiper == 'Y' ? true : false;
                                break;
                            case "9":
                                Console.WriteLine("Enter Temperature");
                                temperature = int.Parse(Console.ReadLine());
                                break;
                            case "10":
                                break;
                        }
                        return true;
                    }
                    else { 
                        key_is_in_ignition = insertkey();
                        return true;
                    }
                }

            case "2":
                key_is_in_ignition = insertkey();
                return true;
            case "3":
                seatbelt_is_fastened = true;
                return true;
            case "4":
                car_is_started = false;
                return true;
            default:
                return true;

        } // close switch
    }

    //XXXXXXXXXXXXXXXXXX C H E C K F O R K E Y XXXXXXXXXXXXXXXXXXXXXXXX

    private static bool insertkey()
    {
        char haveKey;
        Console.WriteLine("Do you have the key in the Ignition (Y/N)?");
        haveKey = char.Parse(Console.ReadLine().ToUpper());
        if (haveKey == 'Y')
        {
            Console.WriteLine("Key is in the Ignition!");

            return true;
        }


        else
            return false;

    }
}