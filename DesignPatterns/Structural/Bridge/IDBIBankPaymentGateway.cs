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
    class IDBIBankPaymentGateway : IPaymentGateway
    {
        public void ProcessPayment(string paymentMode)
        {
            Console.WriteLine("Processing Payment from IDBI Bank Through the mode  :{0}", paymentMode);
        }
    }
}
