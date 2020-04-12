using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Structural.Bridge
{
    /// <summary>
    /// Abstract Class
    /// </summary>
    abstract class Payment
    {
        protected IPaymentGateway paymentGateway;

        public Payment(IPaymentGateway paymentGateway)
        {
            this.paymentGateway = paymentGateway;
        }
        abstract public void MakePayment();
    }
}
