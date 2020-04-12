using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeServiceHost
{
    class Program
    {
        static void Main(string[] args)
        {
            using (ServiceHost employeeserviceHost = new ServiceHost(typeof(EmployeeFormService.EmployeeService)))
            {
                employeeserviceHost.Open();
                Console.WriteLine("Service Successfully Started....Press any key to abort");
                Console.ReadLine();
            }

        }
    }
}
