using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace AsyncOperation
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<Job> jobs;
        List<Employee> employees;
        public MainWindow() 
        {
            InitializeComponent();
            jobs = new List<Job>()
            {
                new Job() { Title="C++", Id=121, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
                new Job() { Title="Java", Id=122, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
                new Job() { Title="Python", Id=123, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
                new Job() { Title="C#", Id=124, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
                new Job() { Title="Angular", Id=125, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
                new Job() { Title="React", Id=126, StartDate=DateTime.Now.ToString(),EndDate=DateTimeOffset.Now.ToString()},
            };

            employees = new List<Employee>()
            {
                new Employee() { JobTitle="C++", Name="Nagesh"},
                new Employee() { JobTitle="C++", Name="Dilish"},
                new Employee() { JobTitle="Python", Name="Abhitosh"},
                new Employee() { JobTitle="C#", Name="Nagesh"}
            };

            cmdJobTitle.ItemsSource = jobs;
            Mediator.GetInstance.JobChangeEventHandler += PopulateEmployeeList;
            Mediator.GetInstance.JobChangeEventHandler += PopulateJobDetails;

        }

        private void CmdJobTitle_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Mediator.GetInstance.UpdateListofEmployees(sender, (Job)cmdJobTitle.SelectedItem);
        }

        private void PopulateEmployeeList(object sender,JobEventArgs jobEventArgs)
        {
            var lstofemployees = employees.Where((emp) => emp.JobTitle == jobEventArgs.Job.Title)
                                          .OrderBy((emp) => emp.Name);
            lstofEmployees.ItemsSource = lstofemployees;
            lstofEmployees.DisplayMemberPath = "Name";
            lblJobTitle.Content = jobEventArgs.Job.Title;
        }

        private void PopulateJobDetails(object sender,JobEventArgs jobEventArgs)
        {
            this.DataContext = jobEventArgs.Job;
        }
    }
}
