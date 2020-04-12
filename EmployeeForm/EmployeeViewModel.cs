using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using EmployeeForm.Data;

namespace EmployeeForm
{
    public class EmployeeViewModel : INotifyPropertyChanged
    {
        private EmpService.EmployeeServiceClient empClient = new EmpService.EmployeeServiceClient();
        private ObservableCollection<Employee> _employees = new ObservableCollection<Employee>();
        private int _id;
        private string _name;
        private string _designationText;
        private int _salaryText;
        private Employee _selectedEmployee;

        #region Constructor
        public EmployeeViewModel()
        {
            if (DesignerProperties.GetIsInDesignMode(new System.Windows.DependencyObject()))
                return;

            Employees = new ObservableCollection<Employee>(empClient.GetAllEmployees());

            ClickCommand = new RelayCommand(OnSubmitClicked, CanSubmitClicked);
        }

        #endregion

        #region Properties
        public ObservableCollection<Employee> Employees
        {
            get
            {
                return _employees;
            }
            set
            {
                _employees = value;
                OnPropertyChanged("Employees");
            }
        }
        public int IdText
        {
            get
            {
                return _id;
            }
            set
            {
                _id = value;
                OnPropertyChanged("IdText");
            }
        }
        public string NameText
        {
            get
            {
                return _name;
            }
            set
            {
                _name = value;
                OnPropertyChanged("NameText");
            }
        }
        public string DesignationText
        {
            get
            {
                return _designationText;
            }
            set
            {
                _designationText = value;
                OnPropertyChanged("DesignationText");
            }
        }

        public int SalaryText
        {
            get
            {
                return _salaryText;
            }
            set
            {
                _salaryText = value;
                OnPropertyChanged("SalaryText");
            }
        }

        public Employee SelectedEmployee
        {
            get
            {
                return _selectedEmployee;
            }
            set
            {
                _selectedEmployee = value;
                if(_selectedEmployee != null)
                {
                    NameText = _selectedEmployee.Name;
                    IdText = _selectedEmployee.Id;
                    DesignationText = _selectedEmployee.Designation;
                    SalaryText = _selectedEmployee.Salary;
                }
                ClickCommand.RaiseCanExecuteChanged();
            }
        }
        public RelayCommand ClickCommand
        {
            get;
            private set;
        }
        #endregion

        #region Event
        public event PropertyChangedEventHandler PropertyChanged;
        #endregion

        #region EventHandlers
        public void OnPropertyChanged(string propName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propName));
            }
        }

        public bool CanSubmitClicked()
        {
            if (IdText == 0 &&
                NameText == null &&
                DesignationText == null )
            {
                return false;
            }
            return true;
        }

        public async void OnSubmitClicked()
        {
            try
            {
                Employee employee = new Employee
                {
                    Name = NameText,
                    Id = IdText,
                    Designation = DesignationText,
                    Salary = SalaryText
                };
                int result = await empClient.UpdateInsertEmployeeDetailsAsync(employee);
                Employees = new ObservableCollection<Employee>(empClient.GetAllEmployeesAsync().Result);
                if(result == -1)
                {
                    MessageBox.Show($"{result} Row Affected", "Success");
                }
            }
            catch (Exception exception)
            {
                MessageBox.Show("Exception Occured on Button Clicked", exception.Message);
            }
        }

        #endregion
    }
}
