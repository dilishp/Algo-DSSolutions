using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeForm.Data
{
    [DataContract]
    public class Employee
    {
        private string name;
        private int id;
        private string designation;
        private int salary;

        [DataMember]
        public string Name
        {
            get => name;
            set
            {
                name = value;
            }

        }
        [DataMember]
        public int Id
        {
            get => id;
            set
            {
                id = value;
            }
        }
        [DataMember]
        public string Designation
        {
            get => designation;
            set
            {
                designation = value;
            }
        }
        [DataMember]
        public int Salary
        {
            get => salary;

            set
            {
                salary = value;
            }
        }

    }
}
