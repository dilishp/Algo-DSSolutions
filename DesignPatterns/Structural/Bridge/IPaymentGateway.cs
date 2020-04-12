﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignPatterns.Structural.Bridge
{
    /// <summary>
    /// Implementor Interface
    /// </summary>
    public interface IPaymentGateway
    {
        void ProcessPayment(string paymentMode);
    }

}
