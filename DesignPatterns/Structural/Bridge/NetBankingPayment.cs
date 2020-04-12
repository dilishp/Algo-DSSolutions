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
    class NetBankingPayment : Payment
    {
        public NetBankingPayment(IPaymentGateway paymentGateway):base(paymentGateway)
        {

        }
        public override void MakePayment()
        {
            if (paymentGateway != null)
                paymentGateway.ProcessPayment("NetBanking");
        }
    }
}
