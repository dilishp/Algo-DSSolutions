using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Structural.Bridge
{
    /// <summary>
    /// Concrete Implementation
    /// </summary>
    class CitiBankPaymentGateway : IPaymentGateway
    {
        public void ProcessPayment(string paymentMode)
        {
            Console.WriteLine("Processing Payment from Citi Bank Through the mode  :{0}",paymentMode);
        }
    }
}
