using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;


class GuessingGame
{
    public static string CvtVirtualColums(int x,double y,int z)
    {
        string outStr = "";

        outStr += '|';

        string hex = Convert.ToString(x, 16);

        string finalLeft = hex.PadLeft(12, ' ');

        outStr += finalLeft;

        string middle =  String.Format("{0:0.0000}", y);

        middle = middle.PadRight(12, ' ');

        outStr += '|' + middle;

        string right = Convert.ToString(z).PadLeft(12, '0');

        outStr += '|' + right + '|';

        return outStr;
    }

    public static void Main()
    {
        Console.WriteLine(CvtVirtualColums(50, 321.1234567, 22));

        //Dictionary<int, int> prizes = new Dictionary<int, int>();

        //Random rndGen = new Random(0);

        //int num, money;

        //int i = 0;

        //while (i < 10)
        //{

        //    num = rndGen.Next(1, 20);

        //    money = rndGen.Next(1, 10000);

        //    if (!prizes.ContainsKey(num))
        //    {

        //        prizes.Add(num, money);

        //        i++;

        //    }

        //}

        //Console.Write("Enter two numbers(space separated): ");

        //string[] line = Console.ReadLine().Split(' ');

        //int num1 = Int32.Parse(line[0]);

        //int num2 = Int32.Parse(line[1]);

        //if (num1 == num2 || num1 < 1 || num1 > 20 || num2 < 0 || num2 > 20)

        //    Console.WriteLine("quit");

        //else
        //{

        //    int prizeMoney = 0;

        //    if (prizes.ContainsKey(num1))

        //        prizeMoney += prizes[num1];

        //    if (prizes.ContainsKey(num2))

        //        prizeMoney += prizes[num2];

        //    Console.WriteLine("You earned {0} in total!", prizeMoney);

        //    if (prizeMoney == 0)
        //    {
        //        int maxValue = prizes.Max(aPair => aPair.Value);
        //        KeyValuePair<int,int> maxPair = prizes.First(aPair=> (aPair.Value == maxValue));
        //        Console.WriteLine($"You are unlucky!If you guessed {maxPair.Key},You would have won the most money!");
        //    }
        //    else
        //    {
        //        var list = new List<int>();
        //        for (int k = 1;k <= 20;k++)
        //        {
        //            if (!prizes.ContainsKey(k))
        //            {
        //                list.Add(k);
        //            }
        //        }
        //        Console.WriteLine("You are so lucky! You could have 0 money if you have guessed");

        //        foreach (var item in list)
        //        {
        //            Console.WriteLine(item);
        //        }
        //    }
        //}

        

    }

}
