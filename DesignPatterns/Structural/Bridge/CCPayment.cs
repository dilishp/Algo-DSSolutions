using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Structural.Bridge
{
    /// <summary>
    /// Refined Abstraction
    /// </summary>
    class CCPayment : Payment
    {
        public CCPayment(IPaymentGateway paymentGateway):base(paymentGateway)
        {

        }
        public override void MakePayment()
        {
            paymentGateway.ProcessPayment("Credit Card");
        }
    }
}
