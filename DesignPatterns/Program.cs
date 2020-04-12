using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignPatterns.Structural.Bridge;
using DesignPatterns.Behavioral.Observer;

namespace DesignPatterns
{
    class Program
    {
        static void ObserverPattern()
        {
            MarketSubject market = new MarketSubject();
            IDisplayObserver valueResearchdisplay = new ValueResearchObserver(market);
            IDisplayObserver moneyControlDisplay = new MoneyControlObserver(market);
            market.SetNAV();
            market.DeRegister(moneyControlDisplay);
            market.SetNAV();
        }

        static void BridgePattern()
        {
            IPaymentGateway citygateway = new CitiBankPaymentGateway();
            IPaymentGateway idbigateway = new IDBIBankPaymentGateway();
            Payment ccpayMode1 = new CCPayment(citygateway);
            Payment ccpayMode2 = new NetBankingPayment(idbigateway);
            ccpayMode1.MakePayment();
            ccpayMode2.MakePayment();
        }
        static void Main(string[] args)
        {
            ObserverPattern();
        }
    }
}
