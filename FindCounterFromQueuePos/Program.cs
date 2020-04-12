

using System;
using System.Collections.Generic;
using System.Security.Policy;
using System.Xml;


class StockPrice
{
    private string stockName;
    private double stockPrice;

    public StockPrice(string name, double price)
    {
        stockName = name;
        stockPrice = price;
    }

    public string AStockName { get => stockName; set => stockName = value; }
    public double AStockPrice { get => stockPrice; set => stockPrice = value; }


    public override string ToString()
    {
        return "\nName : " + stockName + "\n Price : " + stockPrice;
    }
}

interface ISubject
{
    void Attach(IStockObserver observer);

    void Detach(IStockObserver observer);

    void Notify();
}
interface IStockObserver
{
    void Execute(ISubject subject);

}

class StockDisplay : IStockObserver
{
    public void Execute(ISubject subject)
    {
        foreach (var stock in (subject as StockTicker).StockPrices)
        {
            Console.WriteLine(stock);
        }

        if ((subject as StockTicker).AffectedStock != null)
        {
            Console.WriteLine((subject as StockTicker).AffectedStock);
            (subject as StockTicker).AffectedStock = null;
        }
    }
}
class StockTicker : ISubject
{
    private List<StockPrice> myStockPrices;
    private List<IStockObserver> myObservers;
    private StockPrice myAffectedStock = null;

    public StockPrice AffectedStock
    {
        get { return myAffectedStock = null; }
        set { myAffectedStock = value; }
    }

    public StockTicker()
    {
        myStockPrices = new List<StockPrice>();
        myObservers = new List<IStockObserver>();
    }

    public List<StockPrice> StockPrices { get => myStockPrices; set=> myStockPrices = value; }
    public void AddStockPrice(StockPrice item)
    {
        myStockPrices.Add(item);
        Notify();
    }

    public void RemoveStockPrice(StockPrice item)
    {
        if (myStockPrices.Find(stockPrice => stockPrice.AStockName == item.AStockName) == null)
            return;

        myStockPrices.Remove(item);
        Notify();
    }

    public void UpdateStock(StockPrice item)
    {
        //no updation if thestockprice not present
        var stock = myStockPrices.Find(stockPrice => stockPrice.AStockName == item.AStockName);
        if (stock == null)
            return;

        stock = item;
        myAffectedStock = item;
        Notify();
    }


    public void Attach(IStockObserver observer)
    {
        myObservers.Add(observer);
    }

    public void Detach(IStockObserver observer)
    {
        myObservers.Remove(observer);
    }

    public void Notify()
    {
        foreach (var observer in myObservers)
        {
            observer.Execute(this);
        }
    }
}



class Program
{
    public static void Main()
    {
        bool bExit = false;
        ISubject subject = new StockTicker();
        subject.Attach(new StockDisplay());
        var stockTicker = subject as StockTicker;
        while (!bExit)
        {
            Console.WriteLine("(a)Add a new stock");
            Console.WriteLine("(u)Update Existing stock");
            Console.WriteLine("(r)Remove stock");
            Console.WriteLine("(e)End of the Program");

            var ch = Console.ReadLine();

            switch (ch)
            {
                case "a":
                    Console.WriteLine("Enter Stock Name :");
                    var name = Console.ReadLine();
                    Console.WriteLine("Enter Stock Price  :");
                    var price = Convert.ToDouble(Console.ReadLine()); 
                    stockTicker.AddStockPrice(new StockPrice(name,price));
                    break;
                case "u":
                    Console.WriteLine("Enter Stock Name :");
                    var updatename = Console.ReadLine();
                    Console.WriteLine("Enter Stock Price  :");
                    var updateprice = Convert.ToDouble(Console.ReadLine());
                    stockTicker.UpdateStock(new StockPrice(updatename, updateprice));
                    break;
                case "r":
                    Console.WriteLine("Enter Stock Name :");
                    var rmname = Console.ReadLine();
                    Console.WriteLine("Enter Stock Price  :");
                    var rmprice = Convert.ToDouble(Console.ReadLine());
                    stockTicker.RemoveStockPrice(new StockPrice(rmname, rmprice));
                    break;
                case "e":
                    bExit = true;
                    break;
            }
        }
        

    }
}



