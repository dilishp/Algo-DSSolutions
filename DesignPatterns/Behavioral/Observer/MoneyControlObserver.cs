using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Behavioral.Observer
{
    /// <summary>
    /// Concrete Observer
    /// </summary>
    class MoneyControlObserver : IDisplayObserver
    {
        
        public MoneyControlObserver(MarketSubject marketSubject):base(marketSubject)
        {

        }
        public override void Update(int nav)
        {
            Console.WriteLine("Money Control NAV Graph Updated with {0}",nav);
        }

    }
}
