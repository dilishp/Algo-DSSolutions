using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Data;
using EmployeeForm.Data;

namespace EmployeeDataLibrary
{
    public class Employeedb
    {
        private string connectionString = string.Empty;
        public Employeedb()
        {
            connectionString = ConfigurationManager.ConnectionStrings["DBString"].ConnectionString;
        }


        public async Task<int> Execute(Employee employee)
        {
            using (var connection = new SqlConnection(connectionString))
            {

                SqlCommand sqlCommand = new SqlCommand("SP_SUBMIT", connection);
                sqlCommand.CommandType = System.Data.CommandType.StoredProcedure;

                sqlCommand.Parameters.Add("@EmpId", SqlDbType.Int).Value = employee.Id;
                sqlCommand.Parameters.Add("@EmpName", SqlDbType.VarChar).Value = employee.Name;
                sqlCommand.Parameters.Add("@EmpDesignation", SqlDbType.VarChar).Value = employee.Designation;
                sqlCommand.Parameters.Add("@EmpSalary", SqlDbType.Int).Value = employee.Salary;

                int exeResult;

                try
                {
                    connection.Open();
                    exeResult = await sqlCommand.ExecuteNonQueryAsync();
                }
                catch (Exception sqlException)
                {
                    throw sqlException;
                }
                finally
                {
                    connection.Close();
                }

                return exeResult;
            }
        }

        public IList<Employee> GetEmployees()
        {
            using (var connection = new SqlConnection(connectionString))
            {
                SqlCommand getEmpCommand = new SqlCommand("SP_GETALLEMPLOYEES", connection);
                getEmpCommand.CommandType = CommandType.StoredProcedure;
                List<Employee> employees = new List<Employee>();
                try
                {
                    connection.Open();
                    SqlDataReader dataReader = getEmpCommand.ExecuteReader();

                    if (dataReader.HasRows)
                    {
                        while (dataReader.Read())
                        {
                            Employee employee = new Employee
                            {
                                Id = int.Parse(dataReader["EmpId"].ToString()),
                                Name = dataReader["EmpName"].ToString(),
                                Designation = dataReader["EmpDesignation"].ToString(),
                                Salary = int.Parse(dataReader["EmpSalary"].ToString())
                            };
                            employees.Add(employee);
                        }
                    }
                }
                catch (Exception sqlException)
                {
                    throw sqlException;
                }
                finally
                {
                    connection.Close();
                }

                return employees;
            }
        }
    }
}
