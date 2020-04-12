using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using EmployeeDataLibrary;
using EmployeeForm.Data;

namespace EmployeeFormService
{
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerCall,IncludeExceptionDetailInFaults =true)]
    public class EmployeeService : IEmployeeService
    {
        public IList<Employee> GetAllEmployees()
        {
            Employeedb empDBObj = new Employeedb();

            IList<Employee> lstofEmployees = null;

            try
            {
                lstofEmployees = empDBObj.GetEmployees();
            }
            catch (Exception sqlException)
            {
                throw sqlException;
            }

            return lstofEmployees;
        }

        public async Task<int> UpdateInsertEmployeeDetails(Employee employee)
        {
            Employeedb empDBObj = new Employeedb();

            int exeResult = 0;

            try
            {
                exeResult = await empDBObj.Execute(employee);
            }
            catch (Exception sqlException)
            {
                throw sqlException;
            }

            return exeResult;
        }
    }
}
