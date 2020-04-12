using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Behavioral.Observer
{
    /// <summary>
    /// Observer Interface
    /// </summary>
    public abstract class IDisplayObserver
    {
        protected MarketSubject market;

        public IDisplayObserver(MarketSubject market)
        {
            this.market = market;
            market.Register(this);
        }
        public abstract void Update(int nav);

    }
}
