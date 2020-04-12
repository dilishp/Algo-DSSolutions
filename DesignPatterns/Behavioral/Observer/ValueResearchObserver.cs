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
    class ValueResearchObserver : IDisplayObserver
    {
        public ValueResearchObserver(MarketSubject marketSubject):base(marketSubject)
        {

        }
        public override void Update(int nav)
        {
            Console.WriteLine("Value Research NAV Graph Updated with {0}",nav);
        }
    }
}
