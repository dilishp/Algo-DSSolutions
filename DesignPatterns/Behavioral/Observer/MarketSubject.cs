using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Behavioral.Observer
{
    /// <summary>
    /// Subject class
    /// </summary>
    public class MarketSubject
    {
        List<IDisplayObserver> displayObservers = new List<IDisplayObserver>();

        public void Register(IDisplayObserver platform)
        {
            displayObservers.Add(platform);
        }

        public void DeRegister(IDisplayObserver platform)
        {
            displayObservers.Remove(displayObservers.Find((aPlatform) => aPlatform.Equals(platform)));
        }

        public void Notify(int nav)
        {
            foreach (IDisplayObserver displayPlatform in displayObservers)
            {
                if (displayPlatform != null)
                    displayPlatform.Update(nav);
            }
        }

        public void SetNAV()
        {
            Random nav = new Random();
            Notify(nav.Next(25, 35));
        }
    }
}
